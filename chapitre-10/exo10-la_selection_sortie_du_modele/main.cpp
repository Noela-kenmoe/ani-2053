
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

// Représentation pour DANS_ITEM
struct ItemDansItem {
    std::string nom;
    bool selected;
};

// Représentation pour PAR_INDEX (on stocke les index sélectionnés)
struct EtatParIndex {
    std::vector<std::string> planche;
    std::vector<int> selected_indices;
};

// Représentation pour PAR_ID (on stocke les noms sélectionnés)
struct EtatParID {
    std::vector<std::string> planche;
    std::vector<std::string> selected_names;
};

int main() {
    // Optimisation des flux d'entrées/sorties
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<ItemDansItem> items_item;
    EtatParIndex state_index;
    EtatParID state_id;

    std::string ligne;
    while (std::getline(std::cin, ligne)) {
        if (ligne.empty()) continue;
        std::stringstream ss(ligne);
        std::string cmd;
        ss >> cmd;

        if (cmd == "AJOUTE") {
            std::string nom;
            ss >> nom;
            // 1. DANS_ITEM
            items_item.push_back({nom, false});
            // 2. PAR_INDEX
            state_index.planche.push_back(nom);
            // 3. PAR_ID
            state_id.planche.push_back(nom);
        }
        else if (cmd == "CLIC") {
            int i;
            ss >> i;
            // 1. DANS_ITEM
            for (auto& item : items_item) item.selected = false;
            if (i >= 0 && i < (int)items_item.size()) {
                items_item[i].selected = true;
            }

            // 2. PAR_INDEX
            state_index.selected_indices.clear();
            if (i >= 0 && i < (int)state_index.planche.size()) {
                state_index.selected_indices.push_back(i);
            }

            // 3. PAR_ID
            state_id.selected_names.clear();
            if (i >= 0 && i < (int)state_id.planche.size()) {
                state_id.selected_names.push_back(state_id.planche[i]);
            }
        }
        else if (cmd == "AJOUTE_SEL") {
            int i;
            ss >> i;
            // 1. DANS_ITEM
            if (i >= 0 && i < (int)items_item.size()) {
                items_item[i].selected = true;
            }

            // 2. PAR_INDEX
            if (i >= 0 && i < (int)state_index.planche.size()) {
                if (find(state_index.selected_indices.begin(), state_index.selected_indices.end(), i) == state_index.selected_indices.end()) {
                    state_index.selected_indices.push_back(i);
                }
            }

            // 3. PAR_ID
            if (i >= 0 && i < (int)state_id.planche.size()) {
                std::string nom = state_id.planche[i];
                if (find(state_id.selected_names.begin(), state_id.selected_names.end(), nom) == state_id.selected_names.end()) {
                    state_id.selected_names.push_back(nom);
                }
            }
        }
        else if (cmd == "ECHANGE") {
            int i, j;
            ss >> i >> j;
            // 1. DANS_ITEM
            if (i >= 0 && i < (int)items_item.size() && j >= 0 && j < (int)items_item.size()) {
                std::swap(items_item[i], items_item[j]);
            }

            // 2. PAR_INDEX (les index gardés ne bougent pas avec l'échange)
            if (i >= 0 && i < (int)state_index.planche.size() && j >= 0 && j < (int)state_index.planche.size()) {
                std::swap(state_index.planche[i], state_index.planche[j]);
            }

            // 3. PAR_ID
            if (i >= 0 && i < (int)state_id.planche.size() && j >= 0 && j < (int)state_id.planche.size()) {
                std::swap(state_id.planche[i], state_id.planche[j]);
            }
        }
        else if (cmd == "RETIRE") {
            int i;
            ss >> i;
            // 1. DANS_ITEM
            if (i >= 0 && i < (int)items_item.size()) {
                items_item.erase(items_item.begin() + i);
            }

            // 2. PAR_INDEX (les index pointant sur ou après i bougent ou deviennent obsolètes)
            if (i >= 0 && i < (int)state_index.planche.size()) {
                state_index.planche.erase(state_index.planche.begin() + i);
                std::vector<int> new_indices;
                for (int idx : state_index.selected_indices) {
                    if (idx < i) {
                        new_indices.push_back(idx);
                    } else if (idx > i) {
                        new_indices.push_back(idx - 1);
                    }
                    // Note: si idx == i, l'élément est retiré de la sélection
                }
                state_index.selected_indices = new_indices;
            }

            // 3. PAR_ID
            if (i >= 0 && i < (int)state_id.planche.size()) {
                state_id.planche.erase(state_id.planche.begin() + i);
            }
        }
        else if (cmd == "SUPPRIME") {
            // 1. DANS_ITEM
            std::vector<ItemDansItem> new_items_item;
            for (const auto& item : items_item) {
                if (!item.selected) {
                    new_items_item.push_back(item);
                }
            }
            items_item = new_items_item;

            // 2. PAR_INDEX
            std::vector<std::string> new_planche_index;
            std::vector<int> new_indices_index;
            for (int k = 0; k < (int)state_index.planche.size(); ++k) {
                bool is_selected = (find(state_index.selected_indices.begin(), state_index.selected_indices.end(), k) != state_index.selected_indices.end());
                if (!is_selected) {
                    new_planche_index.push_back(state_index.planche[k]);
                }
            }
            state_index.planche = new_planche_index;
            state_index.selected_indices.clear();

            // 3. PAR_ID
            std::vector<std::string> new_planche_id;
            for (const auto& nom : state_id.planche) {
                bool is_selected = (find(state_id.selected_names.begin(), state_id.selected_names.end(), nom) != state_id.selected_names.end());
                if (!is_selected) {
                    new_planche_id.push_back(nom);
                }
            }
            state_id.planche = new_planche_id;
            state_id.selected_names.clear();
        }
    }

    // --- Collecte des résultats ---
    // 1. DANS_ITEM
    std::vector<std::string> planche_item, sel_item;
    for (const auto& it : items_item) {
        planche_item.push_back(it.nom);
        if (it.selected) sel_item.push_back(it.nom);
    }

    // 2. PAR_INDEX
    std::vector<std::string> planche_index = state_index.planche;
    std::vector<std::string> sel_index;
    for (int idx : state_index.selected_indices) {
        if (idx >= 0 && idx < (int)planche_index.size()) {
            sel_index.push_back(planche_index[idx]);
        }
    }

    // 3. PAR_ID
    std::vector<std::string> planche_id = state_id.planche;
    std::vector<std::string> sel_id;
    for (const auto& nom : state_id.selected_names) {
        if (find(planche_id.begin(), planche_id.end(), nom) != planche_id.end()) {
            sel_id.push_back(nom);
        }
    }

    // --- Fonction d'affichage d'une liste ---
    auto print_list = [](const std::string& prefix, const std::vector<std::string>& vec) {
        std::cout << prefix;
        if (vec.empty()) {
            std::cout << " AUCUN";
        } else {
            for (const auto& s : vec) {
                std::cout << " " << s;
            }
        }
        std::cout << "\n";
    };

    // Affichage DANS_ITEM
    print_list("DANS_ITEM PLANCHE", planche_item);
    print_list("DANS_ITEM SELECTION", sel_item);

    // Affichage PAR_INDEX
    print_list("PAR_INDEX PLANCHE", planche_index);
    print_list("PAR_INDEX SELECTION", sel_index);

    // Affichage PAR_ID
    print_list("PAR_ID PLANCHE", planche_id);
    print_list("PAR_ID SELECTION", sel_id);

    // --- Comparaison pour FAUX ---
    std::vector<std::string> faux_list;
    
    // Comparaison PAR_INDEX vs DANS_ITEM
    if (planche_index != planche_item || sel_index != sel_item) {
        faux_list.push_back("PAR_INDEX");
    }
    // Comparaison PAR_ID vs DANS_ITEM
    if (planche_id != planche_item || sel_id != sel_item) {
        faux_list.push_back("PAR_ID");
    }

    std::cout << "FAUX";
    if (faux_list.empty()) {
        std::cout << " AUCUN";
    } else {
        for (const auto& f : faux_list) {
            std::cout << " " << f;
        }
    }
    std::cout << "\n";

    return 0;
}

