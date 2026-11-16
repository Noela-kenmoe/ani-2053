
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std ;

struct item {
    string nom ;
    bool selectionne = false ;
} ;

struct conception {
    vector<item> dans_item ;
    vector<string> par_index ;
    vector<string> par_id ;

    set<int> index_selectionnes ;
    set<string> id_selectionnes ;
} ;

void afficherliste(const vector<string>& liste) {
    if (liste.empty()) {
        cout << "AUCUN" ;
        return ;
    }

    for (const string& nom : liste) {
        cout << " " << nom ;
    }
}

vector<string> plancheitem(const conception& c) {
    vector<string> resultat ;

    for (const item& item : c.dans_item)
        resultat.push_back(item.nom) ;

    return resultat ;
}

vector<string> plancheindex(const conception& c) {
    return c.par_index ;
}

vector<string> plancheid(const conception& c) {
    return c.par_id ;
}

vector<string> selectionitem(const conception& c) {
    vector<string> resultat ;

    for (const item& item : c.dans_item) {
        if (item.selectionne)
            resultat.push_back(item.nom) ;
    }

    return resultat ;
}

vector<string> selectionindex(const conception& c) {
    vector<string> resultat ;

    for (int i = 0 ; i < (int)c.par_index.size() ; i++) {
        if (c.index_selectionnes.count(i))
            resultat.push_back(c.par_index[i]) ;
    }

    return resultat ;
}

vector<string> selectionid(const conception& c) {
    vector<string> resultat ;

    for (const string& nom : c.par_id) {
        if (c.id_selectionnes.count(nom))
            resultat.push_back(nom) ;
    }

    return resultat ;
}

void appliqueroperation(conception& c, const string& ligne) {
    istringstream flux(ligne) ;
    string operation ;

    flux >> operation ;

    if (operation == "ajoute") {
        string nom ;
        flux >> nom ;

        c.dans_item.push_back({nom, false}) ;
        c.par_index.push_back(nom) ;
        c.par_id.push_back(nom) ;
    }

    else if (operation == "clic") {
        int i ;
        flux >> i ;

        for (item& item : c.dans_item)
            item.selectionne = false ;

        c.index_selectionnes.clear() ;
        c.id_selectionnes.clear() ;

        if (i >= 0 && i < (int)c.dans_item.size())
            c.dans_item[i].selectionne = true ;

        if (i >= 0 && i < (int)c.par_index.size())
            c.index_selectionnes.insert(i) ;

        if (i >= 0 && i < (int)c.par_id.size())
            c.id_selectionnes.insert(c.par_id[i]) ;
    }

    else if (operation == "ajoute_sel") {
        int i ;
        flux >> i ;

        if (i >= 0 && i < (int)c.dans_item.size())
            c.dans_item[i].selectionne = true ;

        if (i >= 0 && i < (int)c.par_index.size())
            c.index_selectionnes.insert(i) ;

        if (i >= 0 && i < (int)c.par_id.size())
            c.id_selectionnes.insert(c.par_id[i]) ;
    }

    else if (operation == "echange") {
        int i, j ;
        flux >> i >> j ;

        if (i >= 0 && j >= 0 &&
            i < (int)c.dans_item.size() &&
            j < (int)c.dans_item.size()) {
            swap(c.dans_item[i], c.dans_item[j]) ;
        }

        if (i >= 0 && j >= 0 &&
            i < (int)c.par_index.size() &&
            j < (int)c.par_index.size()) {
            swap(c.par_index[i], c.par_index[j]) ;
        }

        if (i >= 0 && j >= 0 &&
            i < (int)c.par_id.size() &&
            j < (int)c.par_id.size()) {
            swap(c.par_id[i], c.par_id[j]) ;
        }
    }

    else if (operation == "retire") {
        int i ;
        flux >> i ;

        if (i >= 0 && i < (int)c.dans_item.size())
            c.dans_item.erase(c.dans_item.begin() + i) ;

        if (i >= 0 && i < (int)c.par_index.size())
            c.par_index.erase(c.par_index.begin() + i) ;

        if (i >= 0 && i < (int)c.par_id.size())
            c.par_id.erase(c.par_id.begin() + i) ;

        // les index et les identifiants selectionnes
        // ne sont volontairement pas mis a jour.
    }

    else if (operation == "supprime") {
        vector<item> nouveauxitems ;

        for (const item& item : c.dans_item) {
            if ( !item.selectionne)
                nouveauxitems.push_back(item) ;
        }

        c.dans_item = nouveauxitems ;

        vector<string> nouveauxindex ;

        for (int i = 0 ; i < (int)c.par_index.size() ; i++) {
            if ( !c.index_selectionnes.count(i))
                nouveauxindex.push_back(c.par_index[i]) ;
        }

        c.par_index = nouveauxindex ;

        vector<string> nouveauxid ;

        for (const string& nom : c.par_id) {
            if ( !c.id_selectionnes.count(nom))
                nouveauxid.push_back(nom) ;
        }

        c.par_id = nouveauxid ;

        c.index_selectionnes.clear() ;
        c.id_selectionnes.clear() ;
    }
}

int main() {
    ios ::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    conception c ;

    string ligne ;

    while (getline(cin, ligne)) {
        if (ligne.empty())
            continue ;

        appliqueroperation(c, ligne) ;
    }

    vector<string> p1 = plancheitem(c) ;
    vector<string> p2 = plancheindex(c) ;
    vector<string> p3 = plancheid(c) ;

    vector<string> s1 = selectionitem(c) ;
    vector<string> s2 = selectionindex(c) ;
    vector<string> s3 = selectionid(c) ;

    cout << "DANS_ITEM PLANCHE" ;
    afficherliste(p1) ;
    cout << "\n" ;

    cout << "DANS_ITEM SELECTION"  ;
    afficherliste(s1) ;
    cout << "\n" ;

    cout << "PAR_INDEX PLANCHE" ;
    afficherliste(p2) ;
    cout << "\n" ;

    cout << "PAR_INDEX SELECTION " ;
    afficherliste(s2) ;
    cout << "\n" ;

    cout << "PAR_ID PLANCHE " ;
    afficherliste(p3) ;
    cout << "\n" ;

    cout << "PAR_ID SELECTION " ;
    afficherliste(s3) ;
    cout << "n" ;

    cout << "FAUX" ;

    if (p1 != p2 || s1 != s2)
        cout << " PAR_INDEX" ;

    if (p1 != p3 || s1 != s3)
        cout << " PAR_ID" ;

    if (p1 == p2 && s1 == s2 &&
        p1 == p3 && s1 == s3)
        cout << " AUCUN" ;

    cout << "\n" ;

    return 0 ;
}



