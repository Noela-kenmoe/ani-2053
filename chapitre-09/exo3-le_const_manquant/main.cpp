
#include <iostream>
#include <string>
#include <vector>
#include <map>

struct Method {
    std::string name ;
    bool is_const ;
    bool modifies ;
    std::vector<std ::string> calls ;
} ;

void afficherListe(
    const std ::string& titre,
    const std ::vector<std ::string>& noms
) {
    std::cout << titre ;

    if (noms.empty()) {
        std::cout <<"AUCUN " ;
    } else {
        for (const std::string& nom : noms) {
            std::cout << " "  << nom ;
        }
    }

    std::cout << "\n" ;
}

int main() {
    std::ios_base ::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;

    int N ;

    if ( !(std ::cin >> N)) {
        return 0 ;
    }

    std::vector<Method> methods(N) ;
    std::map<std ::string, int> name_to_index ;

    // Lecture des méthodes
    for (int i = 0 ; i < N ; ++i) {
        std ::string name ;
        std ::string declaree ;
        int modifies ;
        int k ;

        std::cin >> name >> declaree >> modifies >> k ;

        methods[i].name = name ;
        methods[i].is_const = (declaree == "const") ;
        methods[i].modifies = (modifies == 1) ;

        for (int j = 0 ; j < k ; ++j) {
            std::string callee ;
            std::cin >> callee ;
            methods[i].calls.push_back(callee) ;
        }

        name_to_index[name] = i ;
    }

    // Déterminer les méthodes qui pourraient être const
    std::vector<bool> can_be_const(N, false) ;

    for (int i = 0 ; i < N ; ++i) {
        can_be_const[i] = methods[i].modifies || !methods[i].modifies;
    }

    bool changed = true ;

    while (changed) {
        changed = false ;

        for (int i = 0 ; i < N ; ++i) {
            if ( !can_be_const[i]) {
                continue ;
            }

            for (const std ::string& callee : methods[i].calls) {
                int index = name_to_index[callee] ;

                if ( !can_be_const[index]) {
                    can_be_const[i] = false ;
                    changed = true ;
                    break ;
                }
            }
        }
    }

    // Construire POURRAIT
    std::vector<std ::string> pourrait ;

    for (int i = 0 ; i < N ; ++i) {
        if (can_be_const[i] && !methods[i].is_const) {
            pourrait.push_back(methods[i].name) ;
        }
    }

    // Construire RACINES
    std::vector<std ::string> racines ;

    for (int i = 0 ; i < N ; ++i) {
        if ( !can_be_const[i] || methods[i].is_const) {
            continue ;
        }

        bool all_called_const = true ;

        for (const std ::string& callee : methods[i].calls) {
            int index = name_to_index[callee] ;

            if ( !methods[index].is_const) {
                all_called_const = false ;
                break ;
            }
        }

        if (all_called_const) {
            racines.push_back(methods[i].name) ;
        }
    }

    // Calculer le nombre de passes
    std::vector<bool> is_now_const(N, false) ;

    for (int i = 0 ; i < N ; ++i) {
        is_now_const[i] = methods[i].is_const ;
    }

    int passes = 0 ;
    int remaining = static_cast<int>(pourrait.size()) ;

    while (remaining > 0) {
        std ::vector<int> newly_const ;

        // Identifier toutes les méthodes corrigeables
        for (int i = 0 ; i < N ; ++i) {
            if ( !can_be_const[i] || is_now_const[i]) {
                continue ;
            }

            bool all_const = true ;

            for (const std ::string& callee : methods[i].calls) {
                int index = name_to_index[callee] ;

                if ( !is_now_const[index]) {
                    all_const = false ;
                    break ;
                }
            }

            if (all_const) {
                newly_const.push_back(i) ;
            }
        }

        if (newly_const.empty()) {
            break ;
        }

        // Déclarer toutes les méthodes trouvées simultanément
        for (int index : newly_const) {
            is_now_const[index] = true ;
            --remaining ;
        }

        ++passes ;
    }

    afficherListe("POURRAIT", pourrait) ;
    afficherListe("RACINES", racines) ;

    std::cout << "PASSES " << passes << "\n" ;

    return 0 ;
}
