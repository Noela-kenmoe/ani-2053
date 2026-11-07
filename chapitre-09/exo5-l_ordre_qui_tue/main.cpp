#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Les objets de chaque bloc
    stack<vector<string>> blocks;
    blocks.push({});

    // Les dépendances de chaque objet
    map<string, vector<string>> dependencies;

    // Les objets déjà libérés
    set<string> released;

    // Fonction qui libère un objet
    auto liberer = [&](const string& objet,
                       const string& type) -> bool {

        // Un objet déjà libéré ne fait rien
        if (released.count(objet)) {
            return true;
        }

        // Vérification des dépendances
        for (const string& besoin : dependencies[objet]) {
            if (released.count(besoin)) {
                cout << "PLANTAGE "
                     << objet << " " << besoin << '\n';
                return false;
            }
        }

        // La libération est possible
        released.insert(objet);

        cout << type << " " << objet << '\n';

        return true;
    };

    // Fonction qui ferme le bloc courant
    auto fermerBloc = [&]() -> bool {

        vector<string> objets = blocks.top();
        blocks.pop();

        // Destruction dans l'ordre inverse
        for (auto it = objets.rbegin();
             it != objets.rend(); ++it) {

            if (!liberer(*it, "DETRUIT")) {
                return false;
            }
        }

        return true;
    };

    string ligne;
    bool plante = false;

    // Lecture des commandes
    while (getline(cin, ligne)) {

        stringstream ss(ligne);
        string commande;

        ss >> commande;

        if (commande.empty()) {
            continue;
        }

        if (commande == "DECL") {
            string objet;
            ss >> objet;

            blocks.top().push_back(objet);
        }

        else if (commande == "DEPEND") {
            string a, b;
            ss >> a >> b;

            dependencies[a].push_back(b);
        }

        else if (commande == "FERME") {
            string objet;
            ss >> objet;

            if (!liberer(objet, "FERME")) {
                plante = true;
                break;
            }
        }

        else if (commande == "{") {
            blocks.push({});
        }

        else if (commande == "}") {

            if (!fermerBloc()) {
                plante = true;
                break;
            }
        }
    }

    // Si aucun plantage, fermer les blocs restants
    if (!plante) {

        while (!blocks.empty()) {

            if (!fermerBloc()) {
                plante = true;
                break;
            }
        }
    }

    // Résultat final
    if (!plante) {
        cout << "PROPRE\n";
    }

    return 0;
}
