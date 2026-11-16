#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

// Representation pour DANS_ITEM
struct ItemDansItem {
    string nom;
    bool selected = false;
};

// Representation pour PAR_INDEX
struct EtatParIndex {
    vector<string> planche;
    set<int> selected_indices;
};

// Representation pour PAR_ID
struct EtatParID {
    vector<string> planche;
    set<string> selected_names;
};

// Affichage d'une liste
void afficherListe(const string& prefix,
                   const vector<string>& liste) {
    cout << prefix;

    if (liste.empty()) {
        cout << " AUCUN";
    } else {
        for (const string& nom : liste) {
            cout << " " << nom;
        }
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Les trois conceptions
    vector<ItemDansItem> items_item;
    EtatParIndex state_index;
    EtatParID state_id;

    string ligne;

    // Lecture des operations
    while (getline(cin, ligne)) {
        if (ligne.empty())
            continue;

        stringstream ss(ligne);
        string cmd;

        ss >> cmd;

        // AJOUTE
        if (cmd == "AJOUTE") {
            string nom;
            ss >> nom;

            items_item.push_back({nom, false});

            state_index.planche.push_back(nom);

            state_id.planche.push_back(nom);
        }

        // CLIC
        else if (cmd == "CLIC") {
            int i;
            ss >> i;

            // DANS_ITEM
            for (auto& item : items_item) {
                item.selected = false;
            }

            if (i >= 0 && i < (int)items_item.size()) {
                items_item[i].selected = true;
            }

            // PAR_INDEX
            state_index.selected_indices.clear();

            if (i >= 0 && i < (int)state_index.planche.size()) {
                state_index.selected_indices.insert(i);
            }

            // PAR_ID
            state_id.selected_names.clear();

            if (i >= 0 && i < (int)state_id.planche.size()) {
                state_id.selected_names.insert(state_id.planche[i]);
            }
        }

        // AJOUTE_SEL
        else if (cmd == "AJOUTE_SEL") {
            int i;
            ss >> i;

            // DANS_ITEM
            if (i >= 0 && i < (int)items_item.size()) {
                items_item[i].selected = true;
            }

            // PAR_INDEX
            if (i >= 0 && i < (int)state_index.planche.size()) {
                state_index.selected_indices.insert(i);
            }

            // PAR_ID
            if (i >= 0 && i < (int)state_id.planche.size()) {
                state_id.selected_names.insert(state_id.planche[i]);
            }
        }

        // ECHANGE
        else if (cmd == "ECHANGE") {
            int i, j;
            ss >> i >> j;

            // DANS_ITEM
            if (i >= 0 && j >= 0 &&
                i < (int)items_item.size() &&
                j < (int)items_item.size()) {
                swap(items_item[i], items_item[j]);
            }

            // PAR_INDEX
            if (i >= 0 && j >= 0 &&
                i < (int)state_index.planche.size() &&
                j < (int)state_index.planche.size()) {
                swap(state_index.planche[i], state_index.planche[j]);
            }

            // PAR_ID
            if (i >= 0 && j >= 0 &&
                i < (int)state_id.planche.size() &&
                j < (int)state_id.planche.size()) {
                swap(state_id.planche[i], state_id.planche[j]);
            }

            // Les selections ne changent pas.
        }

        // RETIRE
        else if (cmd == "RETIRE") {
            int i;
            ss >> i;

            // DANS_ITEM
            if (i >= 0 && i < (int)items_item.size()) {
                items_item.erase(items_item.begin() + i);
            }

            // PAR_INDEX
            if (i >= 0 && i < (int)state_index.planche.size()) {
                state_index.planche.erase(
                    state_index.planche.begin() + i
                );
            }

            // PAR_ID
            if (i >= 0 && i < (int)state_id.planche.size()) {
                state_id.planche.erase(
                    state_id.planche.begin() + i
                );
            }

            // IMPORTANT :
            // On ne modifie ni les index selectionnes
            // ni les noms selectionnes.
        }

        // SUPPRIME
        else if (cmd == "SUPPRIME") {

            // DANS_ITEM
            vector<ItemDansItem> nouveaux_items;

            for (const auto& item : items_item) {
                if (!item.selected) {
                    nouveaux_items.push_back(item);
                }
            }

            items_item = nouveaux_items;

            // PAR_INDEX
            vector<string> nouvelle_planche_index;

            for (int i = 0;
                 i < (int)state_index.planche.size();
                 i++) {

                if (state_index.selected_indices.count(i) == 0) {
                    nouvelle_planche_index.push_back(
                        state_index.planche[i]
                    );
                }
            }

            state_index.planche = nouvelle_planche_index;

            // PAR_ID
            vector<string> nouvelle_planche_id;

            for (const string& nom : state_id.planche) {
                if (state_id.selected_names.count(nom) == 0) {
                    nouvelle_planche_id.push_back(nom);
                }
            }

            state_id.planche = nouvelle_planche_id;

            // Les selections sont videes
            state_index.selected_indices.clear();
            state_id.selected_names.clear();
        }
    }

    // =====================================
    // COLLECTE DES RESULTATS
    // =====================================

    vector<string> planche_item;
    vector<string> sel_item;

    // DANS_ITEM
    for (const auto& item : items_item) {
        planche_item.push_back(item.nom);

        if (item.selected) {
            sel_item.push_back(item.nom);
        }
    }

    // PAR_INDEX
    vector<string> planche_index = state_index.planche;
    vector<string> sel_index;

    // La selection est affichee dans l'ordre
    // actuel de la planche.
    for (int i = 0; i < (int)planche_index.size(); i++) {
        if (state_index.selected_indices.count(i) > 0) {
            sel_index.push_back(planche_index[i]);
        }
    }

    // PAR_ID
    vector<string> planche_id = state_id.planche;
    vector<string> sel_id;

    // La selection est affichee dans l'ordre
    // actuel de la planche.
    for (const string& nom : planche_id) {
        if (state_id.selected_names.count(nom) > 0) {
            sel_id.push_back(nom);
        }
    }

    // =====================================
    // AFFICHAGE DES TROIS CONCEPTIONS
    // =====================================

    afficherListe("DANS_ITEM PLANCHE", planche_item);
    afficherListe("DANS_ITEM SELECTION", sel_item);

    afficherListe("PAR_INDEX PLANCHE", planche_index);
    afficherListe("PAR_INDEX SELECTION", sel_index);

    afficherListe("PAR_ID PLANCHE", planche_id);
    afficherListe("PAR_ID SELECTION", sel_id);

    // =====================================
    // COMPARAISON DES CONCEPTIONS
    // =====================================

    vector<string> faux_list;

    // PAR_INDEX compare a DANS_ITEM
    if (planche_index != planche_item ||
        sel_index != sel_item) {

        faux_list.push_back("PAR_INDEX");
    }

    // PAR_ID compare a DANS_ITEM
    if (planche_id != planche_item ||
        sel_id != sel_item) {

        faux_list.push_back("PAR_ID");
    }

    // Affichage de FAUX
    cout << "FAUX";

    if (faux_list.empty()) {
        cout << " AUCUN";
    } else {
        for (const string& nom : faux_list) {
            cout << " " << nom;
        }
    }

    cout << '\n';

    return 0;
}
