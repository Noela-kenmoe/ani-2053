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
    std::vector<int> lib_counts ; // taille = total_creees + 1
    bool crashed = false ;
    std::string crash_msg = " " ;
    auto liberer_sequence = [&](int texture_id, int op_id, int count) {
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
               tableau.erase(tableau.begin() + idx);
                liberer_sequence(t_id, op, S);
                if (crashed) break;
            }
        } else if (cmd == "VIDE") {
            /*for (int t_id : tableau) {
                liberer_texture(t_id, op, V, crashed, crash_msg) ;
                if (crashed) break ;
            }*/
           if (!tableau.empty()) {
                std::vector<int> temp_textures = tableau;
                tableau.clear();
                for (int t_id : temp_textures) {
                    liberer_sequence(t_id, op, V);
                    if (crashed) break;
                }
                if (crashed) break ;
                 //tableau.clear() ;
           }
       }
    }
    if (!crashed && !tableau.empty()) {
        std::vector<int> temp_textures = tableau;
        tableau.clear();
        for (int t_id : temp_textures) {
            liberer_sequence(t_id, -1, F);
            if (crashed) break;
        }
    }
    /*if ( !crashed) {
        for (int t_id : tableau) {
            liberer_texture(t_id, -1, F, crashed, crash_msg) ;
            if (crashed) break ;
        }
    }*/

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

