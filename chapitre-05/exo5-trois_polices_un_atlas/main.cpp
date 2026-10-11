#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

struct Groupe {
   std::string nom;
    int n, w, h;
};
struct point {
    long long x, y;
};

int main (){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long p, l_val;
    if(!(std::cin >> p>>l_val)) return 0;
    int g_count;
    if(!(std::cin >> g_count)) return 0;
    if(g_count == 0){
        std::cout << "AUCUN\n";
        return 0;
    }
    std::vector<Groupe> groupes(g_count);
    long long total = 0;
    for (int i =0; i< g_count; i++){
        std::cin>> groupes[i].nom >> groupes[i].n >> groupes[i].w>> groupes[i].h;
        long long rw = groupes[i].w + p;
        long long rh = groupes[i].h + p;
        total += (long long)groupes[i].n * rw * rh;
    }   
    long long w_courant;
    if (l_val == 0) {
        w_courant = 512;
        while (w_courant * w_courant < 2 * total && w_courant < 4096) {
            w_courant *= 2;
        }
    } else {
        w_courant = l_val;
    }

    long long h_courant = w_courant;
    for (int essai = 1; essai <= 8; ++essai) {
        long long x = p;
        long long y = p;
        long long e = 0;
        bool reussi = true;

        std::vector<std::pair<point, point>> positions(g_count);

        for (int i = 0; i < g_count; ++i) {
            long long w = groupes[i].w;
            long long h = groupes[i].h;
            int n = groupes[i].n;
            long long rw = w + p;
            long long rh = h + p;

            point premier = {-1, -1};
            point dernier = {-1, -1};

            for (int j = 0; j < n; ++j) {
                
                if (x + rw > w_courant - p) {
                    x = p;
                    y = y + e + p;
                    e = 0;
                }

                if (x + rw > w_courant - p || y + rh > h_courant - p) {
                    reussi = false;
                    break;
                }

                point actuel = {x, y};
                if (j == 0) premier = actuel;
                dernier = actuel;
                x += rw;
                if (rh > e) {
                    e = rh;
                }
            }

            if (!reussi) break;
            positions[i] = {premier, dernier};
        }

        if (reussi) {
            std::cout << "ESSAIS " << essai << "\n";
            std::cout << "TEXTURE " << w_courant << " " << h_courant << "\n";

            long long occupe = 0;
            for (int i = 0; i < g_count; ++i) {
                std::cout << groupes[i].nom << " " << positions[i].first.x << " " << positions[i].first.y << " " << positions[i].second.x << " " << positions[i].second.y << "\n";
                occupe += (long long)groupes[i].n * groupes[i].w * groupes[i].h;
            }

            long long total_surface = w_courant * h_courant;
            long long perdu = ((total_surface - occupe) * 100) / total_surface;

            std::cout << "OCCUPE " << occupe << "\n";
            std::cout << "PERDU " << perdu << "\n";
            return 0;
        } else {
            if (w_courant == h_courant) {
                w_courant *= 2;
            } else {
                h_courant = w_courant;
            }
        }
    }
    std::cout << "ESSAIS 8\n";
    std::cout << "ECHEC\n";
    return 0;
}
    
