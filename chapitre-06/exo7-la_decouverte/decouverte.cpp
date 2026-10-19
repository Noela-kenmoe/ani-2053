#include "NKWindow/NKMain.h"
#include <iostream>
#include <cstring>
#include <thread>
#include "NKNetwork/Transport/NkSocket.h"
#include "NKNetwork/Lobby/NkLobby.h"
#include "NKTime/NkChrono.h"

using namespace nkentseu;
using namespace net;

// Fonction exécutée en arrière-plan pour simuler le serveur qui diffuse
void RunServerTask(bool& keepRunning) {
    NkDiscovery::ServerInfo info{};
    std::strncpy(info.name, "MonServeurLocal", sizeof(info.name) - 1);
    info.name[sizeof(info.name) - 1] = '\0';
    info.maxPlayers = 4;

    while (keepRunning) {
        (void)NkDiscovery::Broadcast(info);
        (void)NkChrono::SleepMilliseconds(2000);
    }
}

int nkmain(const nkentseu::NkEntryState &state) {
    (void)NkSocket::PlatformInit();

    bool serverRunning = true;
    std::thread serverThread(RunServerTask, std::ref(serverRunning));
    (void)NkChrono::SleepMilliseconds(500);

    std::cout << "[CLIENT] Ecoute des serveurs sur le reseau local" << std::endl;
    
    NkVector<NkDiscovery::ServerInfo> trouves;
    (void)NkDiscovery::Listen(6000, trouves);

    std::cout << "[CLIENT] Fin de l'ecoute. Serveurs trouves : " << trouves.Size() << std::endl;
    
    for (const auto& server : trouves) {
        std::cout << " - Nom : " << server.name << " | Adresse : " << server.addr.ToString().CStr() << " | Joueurs max : " << server.maxPlayers << std::endl;
    }

    serverRunning = false;
    if (serverThread.joinable()) {
        serverThread.join();
    }

    (void)NkSocket::PlatformShutdown();
    return 0;
}