#include <iostream>
#include <string>
#include <vector>
#include <cmath>
struct Image {
    std ::string nom ;
    double x, y ;
    double largeur, hauteur ;
    double echelle ;

    // Vérifie si un point (px, py) touche l’image (bords inclus)
    bool contains(double px, double py) const {
        double half_w = (largeur * echelle) / 2.0 ;
        double half_h = (hauteur * echelle) / 2.0 ;
        return (std ::abs(px - x) <= half_w) && (std ::abs(py - y) <= half_h) ;
    }
} ;

int main() {
    // Optimisation des flux d’entrées/sorties
    std ::ios ::sync_with_stdio(false) ;
    std ::cin.tie(nullptr) ;

    int N ;
    if ( !( std ::cin >> N)) return 0 ;

    std ::vector<Image> images(N) ;
    for (int i = 0 ; i < N ; ++i) {
        std ::cin >> images[i].nom >> images[i].x >> images[i].y 
            >> images[i].largeur >> images[i].hauteur >> images[i].echelle ;
    }

    int Q ;
    if ( !(std::cin >> Q)) return 0 ;

    int erreurs = 0 ;

    for (int k = 1 ; k <= Q ; ++k) {
        double qx, qy ;
        std ::cin >> qx >> qy ;

        // 1. Recherche à rebours (de la dernière image lue vers la première)
        std ::string A = "AUCUN" ;
        for (int i = N - 1 ; i >= 0 ; --i) {
            if (images[i].contains(qx, qy)) {
                A = images[i].nom ;
                break ;
            }
        }

        // 2. Recherche à l’endroit (de la première image lue vers la dernière)
        std::string B = "AUCUN" ;
        for (int i = 0 ; i < N ; ++i) {
            if (images[i].contains(qx, qy)) {
                B = images[i].nom ;
                break ;
            }
        }

        // Si les images trouvées diffèrent, on incrémente les erreurs
        if (A != B) {
            erreurs++ ;
        }

        std::cout << "CLIC " << k << " "  << A << " "  << B << "\n" ;
    }

    std::cout << "ERREURS "  << erreurs << "\n" ;

    return 0 ;
}
