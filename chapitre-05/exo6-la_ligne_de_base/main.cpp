#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

struct Glyphe {
    int avance;
    int x0, y0, x1, y1;
};
struct Rectangle 
{
    int x0, y0, x1, y1;
};

int main (){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int G;
    if(!(std::cin >> G)) return 0;
    std::map<char, Glyphe> table_glyphes;
    for (int i = 0; i < G; ++i){
        char c;
        int avance , x0, y0, x1, y1;
        std::cin >> c >> avance >> x0 >> y0 >> x1 >> y1;
        table_glyphes[c] = {avance, x0, y0, x1, y1};
    }
    int k;
    std::cin >> k;
    std::map<std::string, int> crenage;
    for(int i = 0; i < k; i++){
        std::string paire;
        int k;
        std::cin >> paire >> k;
        crenage[paire] = k;
    }
    std::string texte;
    int ox, oy;
    std::cin >> texte >> ox >> oy;
    int x = ox;
    int absents = 0;
    std::vector<Rectangle> rectangles_dessines;
    int n = texte.length();
    for (int i = 0; i < n; i++){
        char c = texte[i];
        if(table_glyphes.find(c) == table_glyphes.end()){
            std::cout << c << " ABSENT\n";
            absents++;
            continue;
        }
        std::cout << c << " " << x<< "\n";
        Glyphe g = table_glyphes[c];
        if(g.x1 > g.x0 && g.y1 > g.y0){
            int rx0 = x + g.x0;
            int ry0 = oy + g.y0;
            int rx1 = x + g.x1;
            int ry1 = oy + g.y1;
            rectangles_dessines.push_back({rx0, ry0, rx1, ry1});
        }
        x += g.avance;
        if(i+ 1 < n){
            std::string paire = "";
            paire += c;
            paire += texte[i + 1];
            if(crenage.find(paire) != crenage.end()){
                x += crenage[paire];
            }
        }
    }
    std::cout << "CURSEUR " << x << "\n";
    if(rectangles_dessines.empty()){
        std::cout <<"BOITE AUCUNE\n";
        std::cout <<"MONTE 0\n";
        std::cout <<"DESCEND 0\n";
        std::cout <<"ECRAN RIEN\n";
        
    }else {
        int minx = rectangles_dessines[0].x0;
        int miny = rectangles_dessines[0].y0;
        int maxx = rectangles_dessines[0].x1;
        int maxy = rectangles_dessines[0].y1;

        for (const auto& r : rectangles_dessines){
            minx = std::min(minx, r.x0);
            miny = std::min(miny, r.y0);
            maxx = std::max(maxx, r.x1);
            maxy = std::max(maxy, r.y1);
        }
        std::cout <<"BOITE "<< minx << " " <<miny << " " << maxx<< " " <<maxy <<"\n";
        int monte = (miny < oy) ? (oy - miny) : 0;
        int descend = (maxy > oy) ? (maxy - oy): 0;
        std::cout << "MONTE "<< monte <<"\n";
        std::cout<< "DESCEND "<< descend <<"\n";
        std::string ecran;
        if(maxy <= 0){
            ecran = "HORS";
        }else if (miny <0){
            ecran = "COUPE";
        }else {
            ecran = "VISIBLE";
        }
        std::cout << "ECRAN "<< ecran <<"\n";

    }
    std::cout << "ABSENTS "<< absents <<"\n";
   return 0;
}
