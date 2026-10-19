#include "NKWindow/NKMain.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <thread>
#include <cstring>
#include <NKTime/NkChrono.h>
#include "NKNetwork/Protocol/NkConnection.h"
#include "NKNetwork/Transport/NkSocket.h"

using namespace nkentseu;
using namespace net;

// 1. Fonction exécutant le serveur en arrière-plan (mode écho)
void RunServerTask(bool& keepRunning, uint16 port) {
    NkConnectionManager serverManager;
    if (serverManager.StartServer(port, 4) != NkNetResult::NK_NET_OK) {
        return;
    }

    while (keepRunning) {
        NkVector<NkReceiveMsg> serverMsgs;
        serverManager.DrainAll(serverMsgs);
        for (usize m = 0; m < serverMsgs.Size(); ++m) {
            // Écho : renvoyer immédiatement le message reçu à l'expéditeur
            (void)serverManager.SendTo(serverMsgs[m].from, serverMsgs[m].data, serverMsgs[m].size, serverMsgs[m].channel);
        }
        NkChrono::SleepMilliseconds(1);
    }
    serverManager.Shutdown();
}

int nkmain(const nkentseu::NkEntryState &state) {
    (void)NkSocket::PlatformInit();

    constexpr uint16 kPort = 7777;
    bool serverRunning = true;

    // 2. Démarrage du serveur dans un thread séparé
    std::thread serverThread(RunServerTask, std::ref(serverRunning), kPort);

    // Petite pause pour laisser le serveur s'initialiser
    NkChrono::SleepMilliseconds(100);

    // 3. Partie Client
    NkConnectionManager connectionManager;

    // Attente de l'établissement de la connexion (handshake)
    NkPeerId serverPeer {};
    connectionManager.onPeerConnected = [&](NkPeerId peerId){
        serverPeer = peerId;
        std::cout<<"client connectee ID du serveur distant = "<< peerId.value;
    };
    NkAddress serverAddr("127.0.0.1", kPort);
    uint16 localPort = 0;
    auto result = connectionManager.Connect(serverAddr, localPort);
    if (result != NkNetResult::NK_NET_OK) {
        std::cerr << "Erreur de connexion au serveur." << std::endl;
        serverRunning = false;
        if (serverThread.joinable()) serverThread.join();
        (void)NkSocket::PlatformShutdown();
        return 1;
    }
    bool connected = false;
    for (int i = 0; i < 200; ++i) {
        if (connectionManager.ConnectedPeerCount() >= 1) {
            connected = true;
            break;
        }
        NkChrono::SleepMilliseconds(10);
    }

    if (!connected) {
        std::cerr << "Échec de l'établissement de la connexion avec le serveur." << std::endl;
        connectionManager.Shutdown();
        serverRunning = false;
        if (serverThread.joinable()) serverThread.join();
        (void)NkSocket::PlatformShutdown();
        return 1;
    }

    std::vector<double> mesures;
    mesures.reserve(100);

    double srtt = 100.0; 
    double alpha = 0.125;

    // Boucle pour effectuer 100 allers-retours, un message à la fois
    for (int i = 0; i < 100; ++i) {
        NkChrono chrono;
        chrono.BeginPreciseTiming();

        // 1. Envoyer le message numéroté i
        uint32 messageId = static_cast<uint32>(i);
        (void)connectionManager.SendTo(serverPeer, reinterpret_cast<const uint8*>(&messageId), sizeof(messageId), NkNetChannel::NK_NET_CHANNEL_RELIABLE_ORDERED);

        // 2. Attendre le retour du même numéro en vidant la file par DrainAll
        bool recu = false;
        for (int timeout = 0; timeout < 1000 && !recu; ++timeout) {
            NkVector<NkReceiveMsg> messages;
            connectionManager.DrainAll(messages);
            for (usize m = 0; m < messages.Size(); ++m) {
                if (messages[m].size >= sizeof(uint32)) {
                    uint32 receivedId = *reinterpret_cast<const uint32*>(messages[m].data);
                    if (receivedId == static_cast<uint32>(i)) {
                        recu = true;
                        break;
                    }
                }
            }
            if (!recu) {
                NkChrono::SleepMilliseconds(1);
            }
        }

        // 3. Mesurer le temps écoulé si le message est bien revenu
        if (recu) {
            double R = chrono.Elapsed().milliseconds;
            mesures.push_back(R);

            // 4. Calculer la valeur lissée : SRTT
            srtt = (1.0 - alpha) * srtt + alpha * R;
        }
    }

    // Calculs statistiques
    if (!mesures.empty()) {
        double somme = std::accumulate(mesures.begin(), mesures.end(), 0.0);
        double moyenne = somme / mesures.size();
        double minimum = *std::min_element(mesures.begin(), mesures.end());
        double maximum = *std::max_element(mesures.begin(), mesures.end());
        
        std::cout << "Moyenne RTT : " << moyenne << " ms (Min: " << minimum << " ms, Max: " << maximum << " ms)" << std::endl;
    }
    NkConnectionStats stats;
    double moteurR = 0.0;
    if(connectionManager.GetConnectionStats(serverPeer, stats)){
        moteurR = stats.rttMs;
    }
    std::cout<< "Moteur : "<<moteurR<< "ms "<<std::endl;

    // Nettoyage propre
    connectionManager.Shutdown();
    serverRunning = false;
    if (serverThread.joinable()) {
        serverThread.join();
    }
    (void)NkSocket::PlatformShutdown();

    std::cout << "Exercice 9 execute avec succes dans un seul terminal !" << std::endl;
    return 0;
}

