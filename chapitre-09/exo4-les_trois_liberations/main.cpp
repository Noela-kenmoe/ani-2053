#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int S, V, F;
    std::cin >> S >> V >> F;

    int N;
    std::cin >> N;

    // Tableau contenant les numéros des textures encore présentes
    std::vector<int> tableau;

    // Indique si chaque texture a déjà été libérée
    std::vector<bool> liberees(1, false);

    int creees = 0;
    bool plante = false;

    // Libération d'une texture
    auto liberer = [&](int texture, int nombre, const std::string& operation) {

        for (int i = 0; i < nombre; ++i) {

            // Une deuxième libération provoque un plantage
            if (liberees[texture]) {
                std::cout << "PLANTAGE "
                          << operation
                          << " TEXTURE "
                          << texture << '\n';

                plante = true;
                return;
            }

            liberees[texture] = true;
        }
    };

    // Lecture des opérations
    for (int k = 1; k <= N && !plante; ++k) {

        std::string commande;
        std::cin >> commande;

        if (commande == "AJOUTE") {

            ++creees;
            tableau.push_back(creees);
            liberees.push_back(false);

        }
        else if (commande == "SUPPRIME") {

            int index;
            std::cin >> index;

            int texture = tableau[index];

            liberer(texture, S, std::to_string(k));

            if (!plante) {
                tableau.erase(tableau.begin() + index);
            }

        }
        else if (commande == "VIDE") {

            // Parcours du premier au dernier élément
            for (int texture : tableau) {

                liberer(texture, V, std::to_string(k));

                if (plante) {
                    break;
                }
            }

            if (!plante) {
                tableau.clear();
            }
        }
    }

    // Arrêt immédiat si un plantage a déjà eu lieu
    if (plante) {
        return 0;
    }

    // Libération à la fin du programme
    for (int texture : tableau) {

        liberer(texture, F, "FIN");

        if (plante) {
            return 0;
        }
    }

    // Calcul du nombre de textures perdues
    int fuites = 0;

    std::vector<int> perdues;

    for (int i = 1; i <= creees; ++i) {

        if (!liberees[i]) {
            ++fuites;
            perdues.push_back(i);
        }
    }

    // Affichage des résultats
    std::cout << "CREEES " << creees << '\n';
    std::cout << "FUITES " << fuites << '\n';

    std::cout << "PERDUES";

    if (perdues.empty()) {
        std::cout << " AUCUN";
    }
    else {
        for (int texture : perdues) {
            std::cout << " " << texture;
        }
    }

    std::cout << '\n';

    return 0;
}