#include "NKWindow/NKMain.h"
#include <iostream>
#include <cstring>
#include <map>
#include "NKNetwork/NKNetwork.h"
#include "NKNetwork/Protocol/NkConnection.h"
#include "NKNetwork/Transport/NkSocket.h"
#include <NKThreading/NkMutex.h>
#include <NKThreading/NkScopedLock.h>
#include <NKTime/NkChrono.h>

using namespace nkentseu;
using namespace net;

struct PlayerInfo {
    NkPeerId peerId;
    double lastMessageTime;
};

nkentseu::threading::NkMutex tableMutex;
std::map<uint64, PlayerInfo> playerTable;

void RunServerTask(bool& keepRunning, uint16 port) {
    NkConnectionManager serverManager;
    
    serverManager.onPeerConnected = [](NkPeerId peerId) {
        NkScopedLock<nkentseu::threading::NkMutex> lock (tableMutex);
        playerTable[peerId.value] = PlayerInfo{peerId, NkChrono::Now().milliseconds};
        std::cout << "[SERVEUR] Joueur connecte ! ID = " << peerId.value << std::endl;
    };

    serverManager.onPeerDisconnected = [](NkPeerId peerId, const char* reason) {
        NkScopedLock<nkentseu::threading::NkMutex> lock (tableMutex);
        double currentTime = NkChrono::Now().milliseconds;
        double elapsed = 0.0;
        
        auto it = playerTable.find(peerId.value);
        if (it != playerTable.end()) {
            elapsed = currentTime - it->second.lastMessageTime;
            playerTable.erase(it);
        }
        std::cout << "[SERVEUR] Joueur deconnecte ID = " << peerId.value << " | Raison : " <<reason << " | Delai depuis dernier message : " << elapsed << " ms" << std::endl;
    };

    if (serverManager.StartServer(port, 8) != NkNetResult::NK_NET_OK) {
        return;
    }

    while (keepRunning) {
        NkVector<NkReceiveMsg> messages;
        serverManager.DrainAll(messages);
        NkScopedLock<nkentseu::threading::NkMutex> lock (tableMutex);
        
        for (usize i = 0; i < messages.Size(); ++i) {
            uint64 senderId = messages[i].from.value;
            if (playerTable.find(senderId) != playerTable.end()) {
                playerTable[senderId].lastMessageTime = NkChrono::Now().milliseconds;
            }
        }
        NkChrono::SleepMilliseconds(10);
    }
    serverManager.Shutdown();
}

int nkmain(const nkentseu::NkEntryState &state) {
    (void)NkSocket::PlatformInit();

    constexpr uint16 kPort = 7777;
    bool serverRunning = true;

    // 1. Démarrage du serveur en arrière-plan
    nkentseu::threading::NkThread serverThread([&](auto&&...){
       RunServerTask(serverRunning, kPort);
    } );
    NkChrono::SleepMilliseconds(200);

    // 2. Initialisation du Client
    NkConnectionManager clientManager;
    NkAddress serverAddr("127.0.0.1", kPort);
    uint16 localPort = 0;

    if (clientManager.Connect(serverAddr, localPort) != NkNetResult::NK_NET_OK) {
        std::cerr << "[CLIENT] Erreur de connexion." << std::endl;
        serverRunning = false;
        serverThread.Join();
        (void)NkSocket::PlatformShutdown();
        return 1;
    }

    bool connected = false;
    for (int i = 0; i < 200; ++i) {
        if (clientManager.ConnectedPeerCount() >= 1) {
            connected = true;
            break;
        }
        NkChrono::SleepMilliseconds(10);
    }

    if (connected) {
        std::cout << "[CLIENT] Envoi régulier de messages (boucle de test)..." << std::endl;
        for (int i = 0; i < 20; ++i) {
            const char* msg = "Ping";
            NkChrono::SleepMilliseconds(100);
        }
    }
    std::cout << "[CLIENT] Fermeture propre en cours..." << std::endl;
    clientManager.Shutdown();

    NkChrono::SleepMilliseconds(500);

    serverRunning = false;
        serverThread.Join();
    
    (void)NkSocket::PlatformShutdown();

    std::cout << "Exercice 10 execute avec succes !" << std::endl;
    return 0;
}


