#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
	
	int main() {
	    // Optimisation des flux d'entrées/sorties
	    std::ios::sync_with_stdio(false);
	    std::cin.tie(nullptr);
	
	    int N;
	    if (!(std::cin >> N)) return 0;
	
	    std::vector<int> ordre; // Stocke les identifiants des images présentes dans l'ordre de la planche
	    int prochain_id = 1;
	
	    long long occasions = 0;
	    long long repercutes = 0;
	    long long recherches = 0;
	
	    for (int op = 0; op < N; ++op) {
	        std::string cmd;
	        std::cin >> cmd;	
	        if (cmd == "AJOUTE") {
	            ordre.push_back(prochain_id++);
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
	                if (idx >= 0 && idx < (int)ordre.size()) {
	                    ordre.erase(ordre.begin() + idx);
	                }
	            }
	
	            occasions += 1;
	            repercutes += (2 * c);
	        } 
	        else if (cmd == "MONTE") {
	            int i;
	            std::cin >> i;
	            // Vérifie si la voisine (i + 1) existe dans le modèle
	            if (i >= 0 && i + 1 < (int)ordre.size()) {
	                std::swap(ordre[i], ordre[i + 1]);
	                occasions += 1;
	                repercutes += 2;
	            }
	        } 
	        else if (cmd == "DESCEND") {
	            int i;
	            std::cin >> i;
	            // Vérifie si la voisine (i - 1) existe dans le modèle
	            if (i - 1 >= 0 && i < (int)ordre.size()) {
	                std::swap(ordre[i], ordre[i - 1]);
	                occasions += 1;
	                repercutes += 2;
	            }
	        } 
	        else if (cmd == "DESSINE") {
	            recherches += ordre.size();
	        }
	    }
	
	    // 1. Affichage de l'ordre final
	    std::cout << "ORDRE";
	    if (ordre.empty()) {
	        std::cout << " AUCUN";
	    } else {
	        for (int id : ordre) {
	            std::cout << " " << id;
	        }
	    }
	    std::cout << "\n";
	
	    // 2. Affichage des métriques de coût
	    std::cout << "OCCASIONS " << occasions << "\n";
	    std::cout << "REPERCUTES " << repercutes << "\n";
	    std::cout << "RECHERCHES " << recherches << "\n";
	
	    return 0;	
}

