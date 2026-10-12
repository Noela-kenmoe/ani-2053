#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKLogger/NkLog.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <cstddef>
#include "NKCanvas/Core/NkContextDesc.h"
#include "NKCanvas/Renderer/Targets/NkRenderWindow.h"
/*

#include "NKCanvas/Core/NkGraphicsApi.h"


#include "NKCanvas/App/NkCanvasApp.h"
#include "NKCanvas/Renderer/Resources/NkFont.h"
#include "NKCanvas/Renderer/Resources/NkSprite.h"
#include "NKCanvas/Renderer/Shapes/NkRectangleShape.h"

#include "NKFont/Embedded/NkFontEmbedded.h"
#include "NKImage/NKImage.h"

#include "NKMath/NKMath.h"
#include "NKMath/NkColor.h"
#include "NKTime/NkTime.h"
*/

NKENTSEU_DEFINE_APP_DATA (([]() {
    nkentseu::NkAppData d{};
    d.appName = "image";
    d.appVersion = "1.0.0";
    return d;
})());
struct ImageTask {
    std::string path;
    size_t fileSizeOnDisk; 
};
using namespace nkentseu;
namespace fs =std::filesystem;
int nkmain(const nkentseu::NkEntryState &state) {
    ImageTask items[5] = {
    {"facebook.png", 10265},
    {"screenshot.png", 1931063},
    {"dessin.png", 108774},
    {"photo1.jpg", 1136881 },
    {"photo2.jpg", 137650}
    };
    NkImage images[5];

    bool running = true;
    auto& eventSystem = nkentseu::NkEvents();
    for(int i =0; i<5; i++){
        std::cout<<"\nImage :"<< items[i].path<<"\n";
        std::cout << "Relever la RAM avant le chargement, "<< "puis appuyer sur Enter.\n";
        std::cin.get();
        /*logger.Info("image %d : %s", i+1, items[i].path.c_str());
        std::error_code erreur;
        if(!fs::exists(items[i].path, erreur)|| erreur){
            logger.Error("Fichier introuvable ");
            continue;
        }
        erreur.clear();
        std::uintmax_t tailleFichier =fs::file_size(items[i].path, erreur);
        if (erreur) {
            logger.Error("Impossible de lire la taille du fichier");
            continue;
        }*/
    if (!images[i].Load(items[i].path.c_str())) {
            logger.Error("Echec du chargement de %s",items[i].path.c_str());
            continue;
        }
        std::cout << "Relever la RAM avant le chargement, "<< "puis appuyer sur Enter.\n";
        std::cin.get();
         int largeur = images[i].Width();
        int hauteur = images[i].Height();
        int bpp = images[i].BytesPP();
        std::uintmax_t calcul = static_cast<std::uintmax_t>(largeur)* hauteur * bpp;
        std::cout << "Image : " << items[i].path << '\n';
        std::cout << "Largeur : " << largeur << " pixels\n";
        std::cout << "Hauteur : " << hauteur << " pixels\n";
        std::cout << "BytesPP : " << bpp << '\n';
        std::cout << "Memoire calculee : "<< calcul << " octets\n";
        std::cout << "Taille du fichier : "<< items[i].fileSizeOnDisk << " octets\n";
        
    }
    return 0;
}
