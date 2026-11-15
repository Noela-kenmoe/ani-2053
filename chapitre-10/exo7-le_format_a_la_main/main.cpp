#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdint>


// Fonction utilitaire pour nettoyer l’affichage de -0.00
double clean_val(double val) {
    if (std ::abs(val) < 0.005) {
        return 0.0 ;
    }
    return val ;
}

int main() {
    // Optimisation des flux d’entrées/sorties
    std::ios ::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;

    int T ;
    if ( !(std::cin >> T)) return 0 ;

    std::vector<unsigned char> data(T) ;
    for (int i = 0 ; i < T ; ++i) {
        std::string hex_str ;
        if ( !(std::cin >> hex_str)) {
            std::cout << "TRONQUE\n" ;
            return 0 ;
        }
        data[i] = (unsigned char)stoul(hex_str, nullptr, 16) ;
    }

    size_t pos = 0 ;

    // Fonction lambda pour vérifier et lire des octets en little-endian
    auto check_and_read = [&](size_t n) -> bool {
        return (pos + n <= (size_t)T) ;
    } ;

    // 1. Nombre magique « NKRF » (4 octets)
    if ( !check_and_read(4)) { 
        std::cout << "TRONQUE\n" ; 
        return 0 ; 
    }
    if (data[pos] != 'N' || data[pos+1] != 'K' || data[pos+2] != 'R' || data[pos+3] != 'F') {
        std::cout << "PAS_UNE_PLANCHE\n" ;
        return 0 ;
    }
    pos += 4 ;

    // 2. Version (u32)
    if ( !check_and_read(4)) { 
        std::cout << "TRONQUE\n"; 
        return 0 ; 
    }
    uint32_t version = 0 ;
    std::memcpy(&version, &data[pos], 4) ;
    pos += 4 ;

    if (version != 1) {
        std::cout << "VERSION_INCONNUE " << version << "\n" ;
        return 0 ;
    }

    // 3. Vue : cx, cy, zoom (3 x f32)
    if ( !check_and_read(12)) { 
        std::cout << "TRONQUE\n" ; 
        return 0 ; 
    }
    float cx, cy, zoom ;
    std::memcpy(&cx, &data[pos], 4) ; pos += 4 ;
    std::memcpy(&cy, &data[pos], 4) ; pos += 4 ;
    std::memcpy(&zoom, &data[pos], 4) ; pos += 4 ;

    // 4. Thème (u8), Grille (u8), Remplissage (2 x u8)
    if ( !check_and_read(4)) { std::cout << "TRONQUE\n" ; return 0 ; }
    std::uint8_t theme = data[pos++] ;
    uint8_t grille = data[pos++] ;
    pos += 2 ; // ignorer les deux octets de remplissage

    // 5. Images
    if ( !check_and_read(4)) { std::cout << "TRONQUE\n" ; return 0 ; }
    uint32_t nb_images = 0 ;
    std ::memcpy(&nb_images, &data[pos], 4) ;
    pos += 4 ;

    struct ImageInfo {
        float x, y, echelle, rotation, opacite ;
        uint8_t miroirX, miroirY ;
        uint32_t largeur, hauteur, taille ;
    } ;
    std::vector<ImageInfo> images(nb_images) ;

    for (uint32_t i = 0 ; i < nb_images ; ++i) {
        // 5 x f32 (20 octets) + 2 x u8 (miroirs) + 2 octets ignorés + 3 x u32 (12 octets) = 36 octets minimum par image (hors octets source)
        if ( !check_and_read(36)) { std::cout << "TRONQUE\n" ; return 0 ; }
        std::memcpy(&images[i].x, &data[pos], 4) ; pos += 4 ;
        std::memcpy(&images[i].y, &data[pos], 4) ; pos += 4 ;
        std::memcpy(&images[i].echelle, &data[pos], 4) ; pos += 4 ;
        std::memcpy(&images[i].rotation, &data[pos], 4) ; pos += 4 ;
        std::memcpy(&images[i].opacite, &data[pos], 4) ; pos += 4 ;

        images[i].miroirX = data[pos++] ;
        images[i].miroirY = data[pos++] ;
        pos += 2 ; // ignorer les 2 octets

        std::memcpy(&images[i].largeur, &data[pos], 4) ; pos += 4 ;
        std::memcpy(&images[i].hauteur, &data[pos], 4) ; pos += 4 ;
        std::memcpy(&images[i].taille, &data[pos], 4) ; pos += 4 ;

        if ( !check_and_read(images[i].taille)) { std::cout << "TRONQUE\n" ; return 0 ; }
        pos += images[i].taille ; // sauter les octets source
    }

    // 6. Traits
    if ( !check_and_read(4)) { std::cout << "TRONQUE\n" ; return 0 ; }
    uint32_t nb_traits = 0 ;
    std::memcpy(&nb_traits, &data[pos], 4) ;
    pos += 4 ;

    struct Point { float x, y ; } ;
    struct Trait {
        uint8_t r, g, b, a ;
        float epaisseur ;
        std::vector<Point> points ;
    } ;
    std::vector<Trait> traits(nb_traits) ;

    for (uint32_t i = 0 ; i < nb_traits ; ++i) {
        if ( !check_and_read(4 + 4 + 4)) { std::cout << "TRONQUE\n" ; return 0 ; }
        traits[i].r = data[pos++] ;
        traits[i].g = data[pos++] ;
        traits[i].b = data[pos++] ;
        traits[i].a = data[pos++] ;

        std::memcpy(&traits[i].epaisseur, &data[pos], 4) ; pos += 4 ;

        uint32_t nb_points = 0 ;
        std::memcpy(&nb_points, &data[pos], 4) ; pos += 4 ;

        traits[i].points.resize(nb_points) ;
        for (uint32_t p = 0 ; p < nb_points ; ++p) {
            if ( !check_and_read(8)) { std::cout << "TRONQUE\n" ; return 0 ; }
            std::memcpy(&traits[i].points[p].x, &data[pos], 4) ; pos += 4 ;
            std::memcpy(&traits[i].points[p].y, &data[pos], 4) ; pos += 4 ;
        }
    }

    // --- Affichage des résultats validés ---
    std::cout << std::fixed << std::setprecision(2) ;
    std::cout << "VUE "  << clean_val(cx) << " "  << clean_val(cy) << " "  << clean_val(zoom) << "\n" ;
    std::cout << (theme != 0 ? "THEME SOMBRE" : "THEME CLAIR") << "\n" ;
    std::cout << (grille == 0 ? "GRILLE AFFICHEE" : "GRILLE CACHEE") << "\n" ;

    std::cout << "IMAGES "  << nb_images << "\n" ;
    for (uint32_t i = 0 ; i < nb_images ; ++i) {
        int mx = (images[i].miroirX != 0) ? 1 : 0 ;
        int my = (images[i].miroirY != 0) ? 1 : 0 ;
        std::cout << "IMAGE "  << (i + 1) << " "
             << clean_val(images[i].x) << " " 
             << clean_val(images[i].y) << " " 
             << clean_val(images[i].echelle) <<" " 
             << clean_val(images[i].rotation) << " " 
             << clean_val(images[i].opacite) << " " 
             << mx << " "  << my << " " 
             << images[i].largeur << " "
             << images[i].hauteur << " "
             << images[i].taille << "\n" ;
    }

    std::cout << "TRAITS "   << nb_traits << "\n" ;
    for (uint32_t i = 0 ; i < nb_traits ; ++i) {
        std::cout << "TRAIT "  << (i + 1) << " "
             << (int)traits[i].r << " "
             << (int)traits[i].g << " "
             << (int)traits[i].b << " "
             << (int)traits[i].a << " "
             << clean_val(traits[i].epaisseur) << " "
             << traits[i].points.size() << "\n" ;
        for (const auto& pt : traits[i].points) {
            std::cout << "POINT "  << clean_val(pt.x) << " "  << clean_val(pt.y) << "\n" ;
        }
    }

    return 0 ;
}






