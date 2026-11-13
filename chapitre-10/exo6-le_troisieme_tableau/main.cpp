#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

// Fonction utilitaire pour parser les lignes de configuration (AJOUTE, SUPPRIME, ECHANGE)
bool contient_tableau(const std::string& ligne, const std::string& nom_tableau) {
    std::stringstream ss(ligne);
    std::string mot;
    ss >> mot; // Ignore le mot-clé (ex: AJOUTE)
    while (ss >> mot) {
        if (mot == nom_tableau) return true;
    }
    return false;
}

int main() {
    // Optimisation des flux d'entrées/sorties
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string ligne_ajoute, ligne_supprime, ligne_echange;
    if (!getline(std::cin, ligne_ajoute)) return 0;
    if (!getline(std::cin, ligne_supprime)) return 0;
    if (!getline(std::cin, ligne_echange)) return 0;

    int N;
    if (!(std::cin >> N)) return 0;

    std::vector<std::string> modele;
    std::vector<std::string> textures;
    std::vector<std::string> sources;

    for (int op = 0; op < N; ++op) {
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "AJOUTE") {
            std::string nom;
            std::cin >> nom;
            modele.push_back(nom);
            if (contient_tableau(ligne_ajoute, "textures")) textures.push_back(nom);
            if (contient_tableau(ligne_ajoute, "sources")) sources.push_back(nom);
        } 
        else if (cmd == "SUPPRIME") {
            int c;
            std::cin >> c;
            std::vector<int> indices(c);
            for (int i = 0; i < c; ++i) {
                std::cin >> indices[i];
            }
            // Tri décroissant pour supprimer du plus grand au plus petit
            sort(indices.rbegin(), indices.rend());

            for (int idx : indices) {
                if (idx >= 0 && idx < (int)modele.size()) {
                    modele.erase(modele.begin() + idx);
                }
                if (contient_tableau(ligne_supprime, "textures")) {
                    if (idx >= 0 && idx < (int)textures.size()) {
                        textures.erase(textures.begin() + idx);
                    }
                }
                if (contient_tableau(ligne_supprime, "sources")) {
                    if (idx >= 0 && idx < (int)sources.size()) {
                        sources.erase(sources.begin() + idx);
                    }
                }
            }
        } 
        else if (cmd == "MONTE") {
            int i;
            std::cin >> i;
            // Vérifie si la voisine (i + 1) existe dans le modèle
            if (i >= 0 && i + 1 < (int)modele.size()) {
                swap(modele[i], modele[i + 1]);
                if (contient_tableau(ligne_echange, "textures")) {
                    if (i < (int)textures.size() && i + 1 < (int)textures.size()) {
                        swap(textures[i], textures[i + 1]);
                    }
                }
                if (contient_tableau(ligne_echange, "sources")) {
                    if (i < (int)sources.size() && i + 1 < (int)sources.size()) {
                        swap(sources[i], sources[i + 1]);
                    }
                }
            }
        } 
        else if (cmd == "DESCEND") {
            int i;
            std::cin >> i;
            // Vérifie si la voisine (i - 1) existe dans le modèle
            if (i - 1 >= 0 && i < (int)modele.size()) {
                swap(modele[i], modele[i - 1]);
                if (contient_tableau(ligne_echange, "textures")) {
                    if (i - 1 < (int)textures.size() && i < (int)textures.size()) {
                        swap(textures[i], textures[i - 1]);
                    }
                }
                if (contient_tableau(ligne_echange, "sources")) {
                    if (i - 1 < (int)sources.size() && i < (int)sources.size()) {
                        swap(sources[i], sources[i - 1]);
                    }
                }
            }
        }
    }

    // Longueur du plus long des trois tableaux
    int L = std::max({(int)modele.size(), (int)textures.size(), (int)sources.size()});
    int decales = 0;

    for (int i = 0; i < L; ++i) {
        std::string m = (i < (int)modele.size()) ? modele[i] : "-";
        std::string t = (i < (int)textures.size()) ? textures[i] : "-";
        std::string s = (i < (int)sources.size()) ? sources[i] : "-";

        std::cout << i << " " << m << " " << t << " " << s << "\n";

        // Une ligne est considérée décalée si les trois éléments ne sont pas tous présents et identiques
        if (m != t || m != s || t != s) {
            decales++;
        }
    }

    std::cout << "DECALES " << decales << "\n";

    return 0;
}
