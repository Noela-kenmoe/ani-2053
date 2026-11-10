#include "NkRef/src/NkRef/NkRefView.h"
#include <iostream>

using namespace nkentseu;
int main() {
    const nkref::NkRefView vue{};
    
    // Appels valides sur un objet const (garantis par les promesses de la signature)
     auto worldPos = vue.PixelToWorld({0.0f, 0.0f}, {800.0f, 600.0f});
    float pixelspos = vue.GridSpacing(80.0f);
    std::cout << "Test const reussi !" << std::endl;

    // Ligne testée pour provoquer l'erreur du compilateur (remise en commentaire pour rendre le fichier)
    // Erreur typique : passing 'const nkref::NkRefView' as 'this' argument discards qualifiers
    //vue.PanByPixels(1.0f, 0.0f);

    return 0;
}

