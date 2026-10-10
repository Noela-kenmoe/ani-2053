#include <iostream>
#include <string>
#include <vector>
#include <map>

struct FormatInfo {
    long long octets;
    bool couleur;
    bool transparence;
    bool flottants;
};

int main(){
    std::map<std::string, FormatInfo> formats = {
        {"GRAY8",    {1, false, false, false}},
        {"GRAY_A16", {2, false, true, false}},
        {"RGB24",    {3, true, false, false}},
        {"RGBA32",   {4, true, true, false}},
        {"RGB96F",   {12, true, false, true}},
        {"RGBA128F", {16, true, true, true}},
        
    };
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long w = 0, h = 0;
    int N= 0;
    if (!(std::cin >> w >> h >> N)) return 0;

    long long total_octets = 0;
    long long sans__perte_count= 0;
    long long refuses_count= 0;

    for (int i = 0; i< N; i++){
        std::string source, cible;
        std::cin >> source >> cible;
        if(formats.find(source) == formats.end() || formats.find(cible) == formats.end()){
            std::cout << source << " " << cible << " REFUSE\n";
            refuses_count++;
            continue;
        }
        long long octets_source = w * h * formats[source].octets;
        long long octets_cible = w * h * formats[cible].octets;

        std::string pertes = "";
        if (formats[source].transparence && !formats[cible].transparence){
            pertes += "TRANSPARENCE";
        }
        if(formats[source].couleur && !formats[cible].couleur){
            if(!pertes.empty()) pertes += "+";
            pertes += "COULEUR";
        }
        if (formats[source].flottants && !formats[cible].flottants){
            if(!pertes.empty()) pertes += "+";
            pertes += "ETENDUE";
        }
    
        if(pertes.empty()){
            pertes = "AUCUNE";
            sans__perte_count++;
        }
        total_octets += octets_cible;
        std::cout << source << " " << cible << " " << octets_source << " " << octets_cible << " " << pertes << "\n";
    }
    std::cout << "TOTAL " << total_octets << "\n";
    std::cout << "SANS_PERTE " << sans__perte_count << "\n";
    std::cout << "REFUSES " << refuses_count << "\n";

    return 0;
}        