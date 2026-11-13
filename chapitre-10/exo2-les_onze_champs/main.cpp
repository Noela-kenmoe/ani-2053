#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ImageRecord {
    long long id;
    double x, y, echelle, rotation, opacite;
    int miroirX, miroirY, selectionne;
    long long largeur, hauteur;
    string chemin;
    long long octets;
};

int main() {
    // Optimisation des flux d'entrées/sorties
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) {
        cout << "RESTENT 0\nCHANGES 0\n";
        return 0;
    }

    vector<ImageRecord> images(N);
    for (int i = 0; i < N; ++i) {
        cin >> images[i].id
            >> images[i].x
            >> images[i].y
            >> images[i].echelle
            >> images[i].rotation
            >> images[i].opacite
            >> images[i].miroirX
            >> images[i].miroirY
            >> images[i].largeur
            >> images[i].hauteur
            >> images[i].selectionne
            >> images[i].chemin
            >> images[i].octets;
    }

    int restent = 0;
    int changes = 0;
    int current_j = 0;

    for (int k = 0; k < N; ++k) {
        int item_num = k + 1;
        if (images[k].octets == 0) {
            cout << "ITEM " << item_num << " SAUTE\n";
        } else {
            current_j++;
            restent++;

            bool change_id = (images[k].id != 0);
            bool change_selected = (images[k].selectionne == 1);
            bool change_path = (images[k].chemin != "-");

            vector<string> changed_fields;
            if (change_id) changed_fields.push_back("id");
            if (change_selected) changed_fields.push_back("selected");
            if (change_path) changed_fields.push_back("sourcePath");

            changes += changed_fields.size();

            cout << "ITEM " << item_num << " " << current_j;
            if (changed_fields.empty()) {
                cout << " AUCUN";
            } else {
                for (const auto& field : changed_fields) {
                    cout << " " << field;
                }
            }
            cout << "\n";
        }
    }

    cout << "RESTENT " << restent << "\n";
    cout << "CHANGES " << changes << "\n";

    return 0;
}
