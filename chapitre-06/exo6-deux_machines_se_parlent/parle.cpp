#include "NKWindow/NKMain.h"
#include <iostream>
#include <cstring>
#include <thread>
#include "NKNetwork/NKNetwork.h"
#include  "NKTime/NkChrono.h"
#include "NKNetwork/Protocol/NkConnection.h"
#include "NKNetwork/Transport/NkSocket.h"

using namespace nkentseu ;
using namespace net ;

void RunServerTask(bool& keepRunning, uint16 port) {
    NkConnectionManager serverManager ;
    serverManager.onPeerConnected = [](NkPeerId peerId) {
        std ::cout <<  "[SERVEUR] Pair connecte ! ID value = "  << peerId.value << std ::endl ;
    } ;

    if (serverManager.StartServer(port, 8) != NkNetResult ::NK_NET_OK) {
        return ;
    }

    while (keepRunning) {
        NkVector<NkReceiveMsg> messages ;
        serverManager.DrainAll(messages) ;
        for (usize i = 0 ; i < messages.Size() ; ++i) {
            std ::cout << "[SERVEUR] Message recu de l'expediteur (from) ID = "  << messages[i].from.value 
                      <<   " | Contenu : "  << reinterpret_cast<const char*>(messages[i].data) << std ::endl ;
        }
        NkChrono ::SleepMilliseconds(10) ;
    }
    serverManager.Shutdown() ;
}

int nkmain(const nkentseu ::NkEntryState &state) {
  
    (void)NkSocket ::PlatformInit() ;

    constexpr uint16 kPort = 7777 ;
    Bool serverRunning = true ;

    std ::thread serverThread(RunServerTask, std ::ref(serverRunning), kPort) ;
    NkChrono ::SleepMilliseconds(200) ;

    NkConnectionManager clientManager ;

    clientManager.onPeerConnected = [](NkPeerId peerId) {
        std ::cout << "[CLIENT] Connecte au serveur ! ID value du pair = "  << peerId.value << std ::endl ;
    } ;

    NkAddress serverAddr( "127.0.0.1", kPort) ;
    uint16 localPort = 0 ;
    
    if (clientManager.Connect(serverAddr, localPort) != NkNetResult ::NK_NET_OK) {
        std ::cerr <<  "[CLIENT] Erreur de connexion au serveur." << std ::endl ;
        serverRunning = false ;
        if (serverThread.joinable()) serverThread.join() ;
        (void)NkSocket ::PlatformShutdown() ;
        return 1 ;
    }
    NkPeerId serverPeer {} ;
    Bool connected = false ;
    for (int i = 0 ; i < 200 ; ++i) {
        if (clientManager.ConnectedPeerCount() >= 1) {
            connected = true ;
            break ;
        }
        NkChrono ::SleepMilliseconds(10) ;
    }

    if (connected) {

        const char* texte = "Bonjour Serveur !" ;
        std ::cout <<  "[CLIENT] Envoi du message… " << std ::endl ;
    }
    NkChrono ::SleepMilliseconds(500) ;

    clientManager.Shutdown() ;
    serverRunning = false ;
    if (serverThread.joinable()) {
        serverThread.join() ;
    }
    (void)NkSocket ::PlatformShutdown() ;

    std ::cout <<  "Exercice 6 execute avec succes !" << std ::endl ;
    return 0 ;
}


