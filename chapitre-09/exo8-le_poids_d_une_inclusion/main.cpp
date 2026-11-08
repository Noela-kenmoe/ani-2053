#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>


// Vérifier si un fichier est un .cpp
bool estCpp(const std::string& nom) {
    return nom.size() >= 4 && nom.substr(nom.size() - 4) == ".cpp"  ;
}

// Vérifier si un fichier est un .h
bool estHeader(const std::string& nom) {
    return nom.size() >= 2 && nom.substr(nom.size() - 2) == ".h" ;
}

// Parcours des fichiers qui dépendent du fichier de départ
int compterRecompilations(
    const std::string& depart,
    const std::unordered_map<std::string, std::vector<std::string>>& dependances
) {
    std::vector<std::string> pile ;
    std::unordered_set<std::string> visites ;

    pile.push_back(depart) ;

    int compteur = 0 ;

    while ( !pile.empty()) {
        std::string courant = pile.back() ;
        pile.pop_back() ;

        // Ne pas traiter deux fois le même fichier
        if (visites.find(courant) != visites.end()) {
            continue ;
        }

        visites.insert(courant) ;

        // On compte uniquement les fichiers .cpp
        if (estCpp(courant)) {
            compteur++ ;
        }

        // Chercher les fichiers qui incluent courant
        auto it = dependances.find(courant) ;

        if (it != dependances.end()) {
            for (const std::string& fichier : it->second) {
                if (visites.find(fichier) == visites.end()) {
                    pile.push_back(fichier) ;
                }
            }
        }
    }

    return compteur ;
}

int main() {
    std::ios ::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;

    int N ;
    std::cin >> N ;

    // Conserver les fichiers dans leur ordre de lecture
    std::vector<std::string> fichiers ;

    // Graphe inversé : fichier inclus -> fichiers qui l’incluent
    std::unordered_map<std::string, std::vector<std::string>> dependances ;

    // Lecture des fichiers
    for (int i = 0 ; i < N ; i++) {
        std::string nom ;
        int k ;

        std::cin >> nom >> k ;

        fichiers.push_back(nom) ;

        for (int j = 0 ; j < k ; j++) {
            std::string inclus ;
            std::cin >> inclus ;

            dependances[inclus].push_back(nom) ;
        }
    }

    // Lecture des questions
    int Q ;
    std::cin >> Q ;

    for (int i = 0 ; i < Q ; i++) {
        std::string nom ;
        std::cin >> nom ;

        int resultat = compterRecompilations(
            nom, dependances
        ) ;

        std::cout << nom << " "  << resultat << "\n" ;
    }

    // Recherche du .h le plus lourd
    std::string plusLourd ;
    int maximum = -1 ;
    bool trouve = false ;

    for (const std::string& fichier : fichiers) {
        if ( !estHeader(fichier)) {
            continue ;
        }

        trouve = true ;

        int resultat = compterRecompilations( fichier, dependances
) ;

        // Le signe > conserve le premier en cas d’égalité
        if (resultat > maximum) {
            maximum = resultat ;
            plusLourd = fichier ;
        }
    }

    if (trouve) {
        std::cout << "PLUS_LOURD " 
             << plusLourd << " " 
             << maximum << "\n" ;
    }
    else {
        std::cout <<  "PLUS_LOURD AUCUN\n" ;
    }

    return 0 ;
}
