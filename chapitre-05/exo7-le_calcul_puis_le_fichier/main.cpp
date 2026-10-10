#include <iostream>
#include <string>
#include <vector>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long S;
    int N;
    if (!(std::cin >> S)) return 0;
    if (!(std::cin >> N)) return 0;
    long long memoire = 0;
    int flux = 0;
    int refuses = 0;

    std::vector<std::string> results;
    for( int i = 0; i < N; i++){
        std::string nom;
        long long frequence;
        int canaux;
        long long bits;
        long long duree;
        long long fichier = 0;

        std::cin>> nom >> frequence >> canaux >> bits >> duree>> fichier;
        if (bits != 8 && bits != 16 && bits != 24 && bits != 32 ){
            results.push_back(nom + " REFUSE");
            refuses++;
            continue;
        }

        long long brut = (frequence *canaux * (bits/8) * duree) /1000;
        long long pourcent= (brut > 0) ? (fichier* 100)/ brut : 0;
 
        std::string mode =" ";
        if (brut > S){
            mode = "FLUX";
            flux++;
        }else {
            mode = "MEMOIRE";
            memoire += brut;
        }
        results.push_back(nom + " "  + std::to_string(brut) + " " + std::to_string(pourcent) + " " + mode);

    }
    for (const auto& r : results){
        std::cout<< r << "\n";
    }
    std::cout << "MEMOIRE "<<memoire <<"\n";
    std::cout <<"FLUX " << flux << "\n";
    std::cout << "REFUSES " << refuses << "\n";

    return 0;
    
}