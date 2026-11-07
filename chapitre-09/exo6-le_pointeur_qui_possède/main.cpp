#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>

struct Commande {
    std::string type;
    std::string a;
    std::string b;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    std::cin.ignore();

    std::vector<Commande> commandes;
    std::vector<std::string> ordreVariables;
    std::set<std::string> variablesConnues;

    std::vector<int> lignesCopie;

    for (int i = 1; i <= N; i++) {
        std::string ligne;
        std::getline(std::cin, ligne);

        std::stringstream ss(ligne);
        Commande c;

        ss >> c.type;

        if (c.type == "NEW" ||
            c.type == "RESET" ||
            c.type == "USE") {

            ss >> c.a;

            if (variablesConnues.insert(c.a).second) {
                ordreVariables.push_back(c.a);
            }
        }

        else if (c.type == "MOVE" ||
                 c.type == "COPY") {

            ss >> c.a >> c.b;

            if (variablesConnues.insert(c.a).second) {
                ordreVariables.push_back(c.a);
            }

            if (variablesConnues.insert(c.b).second) {
                ordreVariables.push_back(c.b);
            }

            if (c.type == "COPY") {
                lignesCopie.push_back(i);
            }
        }

        commandes.push_back(c);
    }
    if (!lignesCopie.empty()) {
        for (int numero : lignesCopie) {
            std::cout << "REFUSE " << numero << '\n';
        }

        return 0;
    }
    std::map<std::string, int> possession;

    int crees = 0;
    int detruits = 0;
    int nuls = 0;
    auto detruire = [&](int objet) {
        if (objet != 0) {
            std::cout << "DETRUIT " << objet << '\n';
            detruits++;
        }
    };

    for (const Commande& c : commandes) {

        if (c.type == "NEW") {

            int nouvelObjet = ++crees;
            detruire(possession[c.a]);
            possession[c.a] = nouvelObjet;
        }

        else if (c.type == "MOVE") {
            int objet = possession[c.a];
            possession[c.a] = 0;
            detruire(possession[c.b]);
            possession[c.b] = objet;
        }

        else if (c.type == "RESET") {

            detruire(possession[c.a]);

            possession[c.a] = 0;
        }

        else if (c.type == "USE") {

            if (possession[c.a] == 0) {
                std::cout << "NUL " << (&c - commandes.data() + 1)
                     << " " << c.a << '\n';

                nuls++;
            }
        }
    }
    for (auto it = ordreVariables.rbegin();
         it != ordreVariables.rend(); ++it) {

        detruire(possession[*it]);

        possession[*it] = 0;
    }
    std::cout << "CREES " << crees << '\n';
    std::cout << "DETRUITS " << detruits << '\n';
    std::cout << "NULS " << nuls << '\n';

    return 0;
}