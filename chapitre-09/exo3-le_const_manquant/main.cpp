#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

struct Method {
    std::string name ;
    bool is_const ;
    bool modifies ;
    std::vector<std::string> calls ;
} ;

int main (){
    std::ios_base ::sync_with_stdio(false) ;
    std::cin.tie(NULL) ;
    int N;
    if (!(std::cin >> N)) return 0;
     std::vector<Method> methods(N) ;
    std::map<std::string, int> name_to_index ;

    
        for (int i = 0 ; i < N ; ++i) {
        std::string name, declaree_str ;
        int modifies_flag, k ;
        std::cin >> name >> declaree_str >> modifies_flag >> k ;
        methods[i].name = name ;
        methods[i].is_const = (declaree_str == "const") ;
        methods[i].modifies = (modifies_flag == 1) ;
        for (int j = 0 ; j < k ; ++j) {
            std::string callee ;
            std::cin >> callee ;
            methods[i].calls.push_back(callee) ;
        }
        name_to_index[name] = i ;
    }
    std::vector<bool> can_be_const(N, false) ;
       for (int i = 0 ; i < N ; ++i) {
           if ( !methods[i].modifies) {
            can_be_const[i] = true ;
           }
        }
    bool changed = true ;
    while (changed) {
        changed = false ;
        for (int i = 0 ; i < N ; ++i) {
            if (can_be_const[i]) {
                for (const auto& callee_name : methods[i].calls) {
                    int c_idx = name_to_index[callee_name] ;
                    if ( !methods[c_idx].is_const && !can_be_const[c_idx]) {
                        can_be_const[i] = false ;
                        changed = true ;
                        break ;
                    }
                }
            }
        }
    }
     std::vector<std::string> pourrait ;
    for (int i = 0 ; i < N ; ++i) {
        if (can_be_const[i] && !methods[i].is_const) {
            pourrait.push_back(methods[i].name) ;
        }
    }
     std::vector<std::string> racines ;
    for (int i = 0 ; i < N ; ++i) {
        if (can_be_const[i] && !methods[i].is_const) {
            bool all_called_init_const = true ;
            for (const auto& callee_name : methods[i].calls) {
                int c_idx = name_to_index[callee_name] ;
                if ( !methods[c_idx].is_const) {
                    all_called_init_const = false ;
                    break ;
                }
            }
            if (all_called_init_const) {
                racines.push_back(methods[i].name) ;
            }
        }
    }
      std::set<std::string> currently_const ;
    for (int i = 0 ; i < N ; ++i) {
        if (methods[i].is_const) {
            currently_const.insert(methods[i].name) ;
        }
    }

    int passes = 0 ;
    std::set<std::string> pourrait_set(pourrait.begin(), pourrait.end()) ;

    while ( !pourrait_set.empty()) {
        std::vector<std::string> newly_const ;
        for (const auto& name : pourrait_set) {
            int idx = name_to_index[name] ;
            bool all_const = true ;
            for (const auto& callee_name : methods[idx].calls) {
                if (currently_const.find(callee_name) == currently_const.end()) {
                    all_const = false ;
                    break ;
                }
            }
            if (all_const) {
                newly_const.push_back(name) ;
            }
        }

        if (newly_const.empty()) break ;

        for (const auto& name : newly_const) {
            currently_const.insert(name) ;
            pourrait_set.erase(name) ;
        }
        passes++ ;
    }
     std::cout << "POURRAIT" ;
    if (pourrait.empty()) {
        std::cout << "AUCUN" ;
    } else {
        for (const auto& name : pourrait) {
            std::cout << " "  << name ;
        }
    }
    std::cout << "\n" ;

    std::cout << "RACINES" ;
    if (racines.empty()) {
        std::cout << "AUCUN" ;
    } else {
        for (const auto& name : racines) {
            std ::cout << " "  << name ;
        }
    }
    std::cout << "\n" ;

    std::cout << "PASSES "  << passes << "\n" ;

    return 0 ;
}
