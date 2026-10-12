#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int main (){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int D, C, N;
    if(!(std::cin >> D >> C>> N)) return 0;
    std::vector<int>t(N);
    for(int i =0; i < N; i++){
        std::cin>> t[i];

    }
    std::vector<int> voix(N);
    std::vector<int> retard(N);
    std::vector<std::string> etat(N);
    int voixMax = 0;
    int retardMax = 0;
    int coupes = 0;

    for(int i = 0; i < N; i++){
        int compteur = 0;
        for (int j= 0; j <= i; j++){
            if(t[j] + D > t[i]){
                compteur++;
            }
        }
        voix[i] = compteur;
        voixMax = std::max(voixMax, compteur);
    }
    int finChargement = 0;
    for(int i =0; i < N; i++){
        int debutCharement= std::max(t[i], finChargement);
        finChargement = debutCharement + C;
        retard[i] = finChargement- t[i];
        retardMax = std::max(retardMax, retard[i]);
    }
    for(int i = 0; i < N ; i++){
        if(i+1 < N && t[i+1] < t[i]+D){
            etat[i] = "COUPE";
            coupes++;
        }else {
            etat[i] = "ENTIER";
        }
    }
    for(int i =0; i < N; i++){
        std::cout<<t[i]<< " "<< voix[i]<< " "<< retard[i]<< " "<< etat[i]<< "\n";
    }
    std::cout << "VOIX_MAX "<< voixMax <<"\n";
    std::cout << "RETARD_MAX "<< retardMax<< "\n";
    std::cout << "COUPES "<< coupes <<"\n";

}