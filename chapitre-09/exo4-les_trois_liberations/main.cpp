#include <iostream>
#include <string>
#include <vector>
#include <algorithm>



int main() {
    std::ios_base ::sync_with_stdio(false) ;
    std::cin.tie(NULL) ;

    int S, V, F, N ;
    if ( !(std::cin >> S >> V >> F)) return 0 ;

    if ( !(std::cin >> N)) return 0 ;

    std::vector<int> tableau ; // Contient les numéros des textures actuellement dans le tableau
    int total_creees = 0 ;
    
    // Suivi du nombre de fois que chaque texture a été libérée (indexée par numéro de texture)
    // Comme on ne connait pas le max à l’avance, on peut utiliser un vecteur dynamique ou une table.
    // Une texture de numéro t aura lib_count[t].
    std::vector<int> lib_counts ; // taille = total_creees + 1
    auto liberer_texture = [&](int texture_id, int op_id, int count, bool& crashed, std::string& crash_msg) {
        if (crashed) return ;
        if (texture_id >= (int)lib_counts.size()) {
            lib_counts.resize(texture_id + 1, 0) ;
        }
        for (int c = 0 ; c < count ; ++c) {
            lib_counts[texture_id]++ ;
            if (lib_counts[texture_id] > 1) {
                crashed = true ;
                if (op_id == -1) {
                    crash_msg = "PLANTAGE FIN TEXTURE "  + std::to_string(texture_id) ;
                } else {
                    crash_msg = "PLANTAGE "  + std::to_string(op_id) +  "TEXTURE "  + std::to_string(texture_id) ;
                }
                return ;
            }
        }
    } ;

    bool crashed = false ;
    std::string crash_msg = " " ;

    for (int op = 1 ; op <= N ; ++op) {
        std::string cmd ;
        std::cin >> cmd ;
        if (cmd == "AJOUTE") {
            total_creees++ ;
            tableau.push_back(total_creees) ;
        } else if (cmd == "SUPPRIME") {
            int idx ;
            std::cin >> idx ;
            if (idx >= 0 && idx < (int)tableau.size()) {
                int t_id = tableau[idx] ;
                liberer_texture(t_id, op, S, crashed, crash_msg) ;
                if (crashed) break ;
                tableau.erase(tableau.begin() + idx) ;
            }
        } else if (cmd == "VIDE") {
            for (int t_id : tableau) {
                liberer_texture(t_id, op, V, crashed, crash_msg) ;
                if (crashed) break ;
            }
            if (crashed) break ;
            tableau.clear() ;
        }
    }
    if ( !crashed) {
        for (int t_id : tableau) {
            liberer_texture(t_id, -1, F, crashed, crash_msg) ;
            if (crashed) break ;
        }
    }

    if (crashed) {
        std::cout << crash_msg << "\n" ;
        return 0 ;
    }
    std::vector<int> perdues ;
    int fuites = 0 ;
    for (int t = 1 ; t <= total_creees ; ++t) {
        if (t >= (int)lib_counts.size() || lib_counts[t] == 0) {
            fuites++ ;
            perdues.push_back(t) ;
        }
    }

    std::cout << "CREEES "  << total_creees << "\n" ;
    std::cout << "FUITES "  << fuites << "\n";
    std::cout << "PERDUES" ;
    if (perdues.empty()) {
        std::cout << "AUCUN\n" ;
    } else {
        for (int id : perdues) {
            std::cout << " "  << id ;
        }
        std::cout << "\n";
    }

    return 0 ;
}
