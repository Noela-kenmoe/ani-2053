#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

struct TypeInfo {
    std::string nom ;
    bool inclure = false ;
} ;

int main() {
    std::ios ::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;

    int U ;
    std::cin >> U ;

    std::vector<TypeInfo> types ;
    std::unordered_map<std::string, int> positions ;

    // Lecture des utilisations
    for (int i = 0 ; i < U ; i++) {
        std::string nom, emploi ;
        std::cin >> nom >> emploi ;

        // Vérifier si le type existe déjà
        if (positions.find(nom) == positions.end()) {
            positions[nom] = static_cast<int>(types.size()) ;
            types.push_back({nom, false}) ;
        }

        // Les emplois qui nécessitent une définition complète
        if (emploi == "VALEUR" ||
            emploi == "BASE" ||
            emploi == "CORPS" ||
            emploi == "TAILLE") {

            int index = positions[nom] ;
            types[index].inclure = true ;
        }
    }

    // Lecture des inclusions actuelles
    int A ;
    std::cin >> A ;

    std::unordered_set<std::string> inclusions ;

    for (int i = 0 ; i < A ; i++) {
        std::string nom ;
        std::cin >> nom ;
        inclusions.insert(nom) ;
    }

    // Calcul des résultats
    int nombreInclure = 0 ;
    int nombreAnticiper = 0 ;
    int inclusionsRetirees = 0 ;

    // Affichage des types dans leur ordre d’apparition
    for (const TypeInfo& type : types) {

        if (type.inclure) {
            std::cout << type.nom <<   " INCLURE\n " ;
            nombreInclure++ ;
        }
        else {
            std::cout << type.nom <<   " ANTICIPER\n " ;
            nombreAnticiper++ ;

            // Une inclusion ne peut être retirée
            // que si elle existe déjà.
            if (inclusions.find(type.nom) != inclusions.end()) {
                inclusionsRetirees++ ;
            }
        }
    }

    // Affichage du bilan
    std::cout << "INCLURE "  << nombreInclure << "\n" ;
    std::cout << "ANTICIPER "  << nombreAnticiper << "\n" ;
    std::cout << "INCLUSIONS_RETIREES " << inclusionsRetirees << "\n" ;

    return 0 ;
}

