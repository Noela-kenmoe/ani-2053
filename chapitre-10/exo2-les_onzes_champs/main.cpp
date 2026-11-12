#include <iostream>
#include <string>
#include <vector>

struct Image {
    int id ;
    double x ;
    double y ;
    double echelle ;
    double rotation ;
    double opacite ;
    int miroirX ;
    int miroirY ;
    int largeur ;
    int hauteur ;
    int selectionne ;
    std::string chemin ;
    long long octets ;
} ;

int main() {
    std::ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;

    int N ;
    std::cin >> N ;

    std::vector<Image> images(N) ;

    // Lecture des images
    for (int i = 0 ; i < N ; i++) {
        Image& image = images[i] ;

        std::cin >> image.id  >> image.x  >> image.y  >> image.echelle >> image.rotation >> image.opacite >> image.miroirX   >> image.miroirY >> image.largeur  >> image.hauteur >> image.selectionne >> image.chemin >> image.octets ;
    }

    int restent = 0 ;
    int changements = 0 ;

    // Traitement de chaque image
    for (int i = 0 ; i < N ; i++) {
        const Image& image = images[i] ;

        // Une image sans octets est sautée
        if (image.octets == 0) {
            std::cout << " ITEM "  << i + 1 <<" SAUTE\n" ;
            continue ;
        }

        // Nouvelle position dans la planche
        restent++ ;

        std::cout << " ITEM "  << i + 1 << " "  << restent ;

        int changementsImage = 0 ;

        // Vérification de l’identifiant
        if (image.id != 0) {
            std::cout << " id" ;
            changementsImage++ ;
        }

        // Vérification de la sélection
        if (image.selectionne == 1) {
            std::cout << " selected" ;
            changementsImage++ ;
        }

        // Vérification du chemin source
        if (image.chemin != "-") {
         std::cout <<" sourcePath" ;
            changementsImage++ ;
        }

        // Aucun champ modifié
        if (changementsImage == 0) {
            std::cout <<" AUCUN" ;
        }

        changements += changementsImage ;

        std::cout << "\n" ;
    }

    // Affichage du bilan
    std::cout << "RESTENT "  << restent << "\n";
    std::cout << "CHANGES "  << changements << "\n" ;

    return 0 ;
}
