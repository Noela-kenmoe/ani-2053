#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string remove_spaces(const std::string& s) {
    std::string res = "";
    for (char c : s) {
        if (!isspace(static_cast<unsigned char>(c))) {
            res += c;
        }
    }
    return res;
}

std::string get_state(const std::string& clean_line) {
    if (clean_line.rfind("=delete;", clean_line.length() - 8) == clean_line.length() - 8 ||
        clean_line.find("=delete;") != std::string::npos) {
        // Attention au format exact de fin
        if (clean_line.length() >= 8 && clean_line.substr(clean_line.length() - 8) == "=delete;")
            return "SUPPRIME";
    }
    if (clean_line.length() >= 9 && clean_line.substr(clean_line.length() - 9) == "=default;") {
        return "DEFAUT";
    }
    return "ECRIT";
}

int main() {
    std::string class_name;
    std::ios_base ::sync_with_stdio(false) ;
    std::cin.tie(NULL) ;
    if (!(std::cin >> class_name)) return 0;

    // Consommer la fin de la première ligne
    std::string dummy;
    std::getline(std::cin, dummy);

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(std::cin, line)) {
        size_t comment_pos = line.find("//");
        if (comment_pos != std::string::npos) {
            line = line.substr(0, comment_pos);
        }
        std::string clean = remove_spaces(line);
        if (!clean.empty()) {
            lines.push_back(clean);
        }
    }
    std::string destr = "ABSENT";
    std::string copy = "ABSENT";
    std::string copy_assign = "ABSENT";
    std::string move = "ABSENT";
    std::string move_assign = "ABSENT";
    std::string C = class_name;
    // Destructeur : ~C(
    std::string pattern_destr = "~" + C + "(";
    for (const std::string& s : lines) {
        // Destructeur
        if (s.find(pattern_destr) != std::string::npos) {
            destr = get_state(s);
            continue;
        }
        std::string prefix_copy = C + "(const" + C + "&";
        if (s.rfind(prefix_copy, 0) == 0) {
            // Vérifier qu'il n'y a pas un second & juste après (ex: const C&&)
            size_t idx = s.find(prefix_copy) + prefix_copy.length();
            if (idx < s.length() && s[idx] == '&') {
                // C'est un déplacement par const reference ? Non, c'est un piège
            } else {
                // Vérifier s'il y a un '&' supplémentaire juste après
                bool is_rref = false;
                if (idx < s.length() && s[idx] == '&') is_rref = true;
                if (!is_rref) {
                    copy = get_state(s);
                    continue;
                }
            }
        }
        std::string prefix_copy_assign = C + "&operator=(const" + C + "&";
        if (s.rfind(prefix_copy_assign, 0) == 0) {
            size_t idx = s.find(prefix_copy_assign) + prefix_copy_assign.length();
            bool is_rref = (idx < s.length() && s[idx] == '&');
            if (!is_rref) {
                copy_assign = get_state(s);
                continue;
            }
        }
        // Déplacement : C(C&&
        std::string prefix_move = C + "(" + C + "&&";
        if (s.rfind(prefix_move, 0) == 0) {
            move = get_state(s);
            continue;
        }
        // Affectation par déplacement : C&operator=(C&&
        std::string prefix_move_assign = C + "&operator=(" + C + "&&";
        if (s.rfind(prefix_move_assign, 0) == 0) {
            move_assign = get_state(s);
            continue;
        }
    }

    std::cout << "DESTRUCTEUR " << destr << "\n";
    std::cout << "COPIE " << copy << "\n";
    std::cout << "AFFECTATION_COPIE " << copy_assign << "\n";
    std::cout << "DEPLACEMENT " << move << "\n";
    std::cout << "AFFECTATION_DEPLACEMENT " << move_assign << "\n";
    bool d_decl = (destr != "ABSENT");
    bool c_decl = (copy != "ABSENT");
    bool ca_decl = (copy_assign != "ABSENT");
    bool m_decl = (move != "ABSENT");
    bool ma_decl = (move_assign != "ABSENT");

    std::string regle = "INCOMPLETE";

    if (!d_decl && !c_decl && !ca_decl && !m_decl && !ma_decl) {
        regle = "ZERO";
    } else if (d_decl && c_decl && ca_decl && m_decl && ma_decl) {
        regle = "CINQ";
    } else if (d_decl && c_decl && ca_decl && !m_decl && !ma_decl) {
        regle = "TROIS";
    } else {
        regle = "INCOMPLETE";
    }
    std::cout << "REGLE " << regle << "\n";

    if (regle == "INCOMPLETE") {
        bool any_move = m_decl || ma_decl;
        std::vector<std::pair<std::string, std::string>> members = {
            {"DESTRUCTEUR", destr},
            {"COPIE", copy},
            {"AFFECTATION_COPIE", copy_assign},
            {"DEPLACEMENT", move},
            {"AFFECTATION_DEPLACEMENT", move_assign}
        };
        int limit = any_move ? 5 : 3;
        for (int i = 0; i < limit; ++i) {
            if (members[i].second == "ABSENT") {
                std::cout << "MANQUE " << members[i].first << "\n";
            }
        }
    }
    if (destr == "ECRIT") {
        std::cout << "POSSEDE OUI\n";
    } else {
        std::cout << "POSSEDE NON\n";
    }

    if (copy == "SUPPRIME" && (move == "ECRIT" || move == "DEFAUT")) {
        std::cout << "UNIQUE OUI\n";
    } else {
        std::cout << "UNIQUE NON\n";
    }

    return 0;
} 
