#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>


// Fonction pour éviter l'affichage de -0.00
double clean_val(double val) {
    if (std::abs(val) < 0.005) {
        return 0.0;
    }
    return val;
}

int main() {
    // Optimisation des flux d'entrées/sorties
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double W, H;
    if (!(std::cin >> W >> H)) return 0;

    double cx = 0.0;
    double cy = 0.0;
    double zoom = 1.0;

    std::string cmd;
    while (std::cin >> cmd) {
        if (cmd == "VERS_MONDE") {
            double px, py;
            std::cin >> px >> py;
            double x = cx + (px - W / 2.0) / zoom;
            double y = cy + (py - H / 2.0) / zoom;
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "MONDE " << clean_val(x) << " " << clean_val(y) << "\n";
        } 
        else if (cmd == "VERS_PIXEL") {
            double mx, my;
            std::cin >> mx >> my;
            double x = (mx - cx) * zoom + W / 2.0;
            double y = (my - cy) * zoom + H / 2.0;
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "PIXEL " << clean_val(x) << " " << clean_val(y) << "\n";
        } 
        else if (cmd == "DEPLACE") {
            double dx, dy;
            std::cin >> dx >> dy;
            cx = cx - dx / zoom;
            cy = cy - dy / zoom;
        } 
        else if (cmd == "ZOOM") {
            double f, px, py;
            std::cin >> f >> px >> py;
            // 1. Noter le point du monde sous le curseur AVANT de changer le zoom
            double ax = cx + (px - W / 2.0) / zoom;
            double ay = cy + (py - H / 2.0) / zoom;
            
            // 2. Modifier et borner le zoom
            zoom = zoom * f;
            if (zoom < 0.02) zoom = 0.02;
            if (zoom > 64.0) zoom = 64.0;
            
            // 3. Recalculer le centre pour garder le point fixe sous le curseur
            cx = ax - (px - W / 2.0) / zoom;
            cy = ay - (py - H / 2.0) / zoom;
        } 
        else if (cmd == "GRILLE") {
            double m;
            std::cin >> m;
            double s = 1.0;
            while (s * zoom < m) {
                s *= 2.0;
            }
            while (s * 0.5 * zoom >= m) {
                s /= 2.0;
            }
            std::cout << std::fixed << std::setprecision(6);
            std::cout << "GRILLE " << s << "\n";
        } 
        else if (cmd == "ORIGINE") {
            cx = 0.0;
            cy = 0.0;
            zoom = 1.0;
        }
    }

    // Affichage final requis
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "CENTRE " << clean_val(cx) << " " << clean_val(cy) << "\n";
    std::cout << "ZOOM " << clean_val(zoom) << "\n";

    return 0;
}
