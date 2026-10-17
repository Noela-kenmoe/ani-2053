#include "NKWindow/NKMain.h"
#include "NKNetwork/Protocol/NkBitStream.h"
#include "NKNetwork/NkNetworkApi.h"
#include "NKNetwork/Transport/NkSocket.h"
#include "NKMath/NkFunctions.h"
#include "NKMath/NkVec.h"
#include <iostream>
#include <cmath>
#include <cstdint>
#include <vector>

using namespace nkentseu;
struct joueur {
    bool vivant;
    uint8_t numero;
    float x;
    float y;
    float angle;
    int32_t sante;
};

int nkmain(const nkentseu::NkEntryState &state)
{
    joueur player;
    player.vivant= true;
    player.numero = 41;
    player.x = 133.37f;
    player.y = -52.66f;
    player.angle = 135.5f;
    player.sante = 75;
   
    uint8_t bufferComplet[128]= {};
    uint8_t bufferQuantifie[128] = {};

    nkentseu::net::NkBitWriter writer(bufferComplet, sizeof(bufferComplet));
     writer.WriteU8(player.vivant ? 1:0);
	 writer.WriteU8(player.numero);
	 writer.WriteF32(player.x/*/, -500.f, 500.f, 0.01f*/);  // 1cm précision
	 writer.WriteF32(player.y/*, -500.f, 500.f, 0.01f*/);
	 writer.WriteF32(player.angle);
     writer.WriteI32(player.sante);

     if (!writer.IsOverflowed()) {
		    /*socket.SendTo(bufferComplet, writer.BytesWritten(), remoteAddr);
            
		  } else {*/
		      NK_NET_LOG_ERROR("Buffer trop petit pour le paquet");
		  }
    size_t tailleComplete = writer.BytesWritten();
    size_t bitsComplets = writer.BitsWritten();
     nkentseu::net::NkBitWriter writerQuantifie(bufferQuantifie, sizeof(bufferQuantifie));
    writerQuantifie.WriteBool(player.vivant);
    writerQuantifie.WriteU8(player.numero);
    writerQuantifie.WriteF32Q(player.x, -500.0f, 500.0f, 0.01f);
    writerQuantifie.WriteF32Q(player.y, -500.0f, 500.0f, 0.01f);
    writerQuantifie.WriteF32Q(player.angle, 0.0f, 360.0f, 0.5f);
    writerQuantifie.WriteInt(player.sante, 0, 100);

    if (writerQuantifie.IsOverflowed())
    {
        std::cerr << "Erreur : debordement du paquet quantifie." << std::endl;
        return 1;
    }

    size_t tailleQuantifiee = writerQuantifie.BytesWritten();
    size_t bitsQuantifies = writerQuantifie.BitsWritten();

    std::cout << "=== TAILLES DES PAQUETS ===" << std::endl;
    std::cout << "Types complets : " << tailleComplete << " octets" << std::endl;
    std::cout << "Bits complets : " << bitsComplets << " bits" << std::endl;
    std::cout << "Quantifie : " << tailleQuantifiee << " octets" << std::endl;
    std::cout << "Bits quantifies : " << bitsQuantifies << " bits" << std::endl;

    std::vector<uint8_t> receptionComplete(
        bufferComplet,
        bufferComplet + tailleComplete
    );

    std::vector<uint8_t> receptionQuantifiee(
        bufferQuantifie,
        bufferQuantifie + tailleQuantifiee
    );

    nkentseu::net::NkBitReader readerComplet(
        receptionComplete.data(),
        receptionComplete.size()
    );

    bool vivantComplet = readerComplet.ReadU8() != 0;
    uint8_t numeroComplet = readerComplet.ReadU8();
    float xComplet = readerComplet.ReadF32();
    float yComplet = readerComplet.ReadF32();
    float angleComplet = readerComplet.ReadF32();
    int32_t santeComplete = readerComplet.ReadI32();

    nkentseu::net::NkBitReader readerQuantifie(
        receptionQuantifiee.data(),
        receptionQuantifiee.size()
    );

    bool vivantQuantifie = readerQuantifie.ReadBool();
    uint8_t numeroQuantifie = readerQuantifie.ReadU8();
    float xQuantifie = readerQuantifie.ReadF32Q(
        -500.0f, 500.0f, 0.01f
    );
    float yQuantifie = readerQuantifie.ReadF32Q(
        -500.0f, 500.0f, 0.01f
    );
    float angleQuantifie = readerQuantifie.ReadF32Q(
        0.0f, 360.0f, 0.5f
    );
    int32_t santeQuantifie = readerQuantifie.ReadInt(0, 100);

    std::cout << "\n=== RELECTURE DU PAQUET COMPLET ===" << std::endl;
    std::cout << "Vivant : " << vivantComplet << std::endl;
    std::cout << "Numero : " << static_cast<int>(numeroComplet) << std::endl;
    std::cout << "Position X : " << xComplet << std::endl;
    std::cout << "Position Y : " << yComplet << std::endl;
    std::cout << "Angle : " << angleComplet << std::endl;
    std::cout << "Sante : " << santeComplete << std::endl;

    std::cout << "\n- RELECTURE DU PAQUET QUANTIFIE -" << std::endl;
    std::cout << "Vivant : " << vivantQuantifie << std::endl;
    std::cout << "Numero : " << static_cast<int>(numeroQuantifie) << std::endl;
    std::cout << "Position X : " << xQuantifie << std::endl;
    std::cout << "Position Y : " << yQuantifie << std::endl;
    std::cout << "Angle : " << angleQuantifie << std::endl;
    std::cout << "Sante : " << santeQuantifie << std::endl;

    std::cout << "\n -ECARTS -" << std::endl;
    std::cout << "Etat : "<< (player.vivant != vivantQuantifie) << std::endl;

    std::cout << "Numero : "<< abs(static_cast<int>(player.numero) - static_cast<int>(numeroQuantifie)) << std::endl;

    std::cout << "Position X : "<< fabs(player.x - xQuantifie) << std::endl;

    std::cout << "Position Y : "<< fabs(player.y - yQuantifie) << std::endl;

    std::cout << "Angle : "<< fabs(player.angle - angleQuantifie) << std::endl;

    std::cout << "Sante : "<< abs(player.sante - santeQuantifie) << std::endl;

    std::cout << "\n=== COMPARAISON ===" <<std:: endl;

    if (tailleQuantifiee < tailleComplete)
    {
        std::cout << "Le paquet quantifie est plus petit." << std::endl;
    }
    else if (tailleQuantifiee > tailleComplete)
    {
        std::cout << "Le paquet complet est plus petit." << std::endl;
    }
    else
    {
        std::cout << "Les deux paquets ont la meme taille." << std::endl;
    }

    return 0;
}
        