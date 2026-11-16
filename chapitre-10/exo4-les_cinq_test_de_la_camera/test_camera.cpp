#include <iostream>
#include <cmath>
#include "NkRef/src/NkRef/NkRefView.h"

bool aproapeEgal(float a, float b, float tol = 0.001f) {
    return std::fabs(a - b) <= tol;
}

bool aproapeEgalV(const nkentseu::math::NkVec2f& p1, const nkentseu::math::NkVec2f& p2, float tol = 0.001f) {
    return aproapeEgal(p1.x, p2.x, tol) && aproapeEgal(p1.y, p2.y, tol);
}

bool test_aller_retour() {
    nkref::NkRefView view;
    view.center = {10.0f, -5.0f};
    view.zoom = 2.5f;
    nkentseu::math::NkVec2f vp{640.0f, 400.0f}; // Point dans le viewport
    nkentseu::math::NkVec2f worldPt = view.PixelToWorld(vp, vp); // Note: signature selon vos sources
    // Test direct avec PixelToWorld et WorldToPixel si la signature prend (pixel, viewport)
    // Ajustez selon votre surcharge exacte de PixelToWorld / WorldToPixel
    nkentseu::math::NkVec2f backPixel = view.WorldToPixel(worldPt, vp);

    return aproapeEgalV(vp, backPixel, 0.001f);
}

// 2. point_fixe : après ZoomAtPixel(f, p, vp), PixelToWorld(p) donne le même point du monde qu'avant
bool test_point_fixe() {
    nkref::NkRefView view;
    nkentseu::math::NkVec2f vp{400.0f, 300.0f};
    
    nkentseu::math::NkVec2f worldBefore = view.PixelToWorld(vp, vp);
    view.ZoomAtPixel(2.0f, vp, vp);
    nkentseu::math::NkVec2f worldAfter = view.PixelToWorld(vp, vp);

    return aproapeEgalV(worldBefore, worldAfter, 0.001f);
}

// 3. bornes : un zoom x1000 puis x0.00001 laissent le zoom entre kZoomMin et kZoomMax
bool test_bornes() {
    nkref::NkRefView view;
    nkentseu::math::NkVec2f vp{100.0f, 100.0f};

    view.ZoomAtPixel(1000.0f, vp, vp);
    float z1 = view.zoom;

    view.ZoomAtPixel(0.00001f / z1, vp, vp); // pour descendre très bas
    float z2 = view.zoom;

    bool okMin = (z2 >= view.kZoomMin);
    bool okMax = (z1 <= view.kZoomMax);

    return okMin && okMax && (view.zoom >= view.kZoomMin && view.zoom <= view.kZoomMax);
}

bool test_grille() {
    nkref::NkRefView view;
    float minPixels = 50.0f;

    view.zoom = 10.0f;
    float g1 = view.GridSpacing(minPixels);

    view.zoom = 1.0f; 
    float g2 = view.GridSpacing(minPixels);

    view.zoom = 0.1f; // zoom diminue encore
    float g3 = view.GridSpacing(minPixels);

    return (g2 >= g1) && (g3 >= g2);
}

bool test_origine() {
    nkref::NkRefView view;
    view.zoom = 15.4f;
    view.center = {123.4f, -56.7f};

    view.Reset();

    return aproapeEgal(view.zoom, 1.0f, 0.0001f) && aproapeEgal(view.center.x, 0.0f, 0.0001f) && aproapeEgal(view.center.y, 0.0f, 0.0001f);
}

int main() {
    bool r1 = test_aller_retour();
    bool r2 = test_point_fixe();
    bool r3 = test_bornes();
    bool r4 = test_grille();
    bool r5 = test_origine();

    std::cout << "TEST aller_retour : " << (r1 ? "OK" : "ECHEC") << std::endl;
    std::cout << "TEST point_fixe : " << (r2 ? "OK" : "ECHEC") << std::endl;
    std::cout << "TEST bornes : " << (r3 ? "OK" : "ECHEC") << std::endl;
    std::cout << "TEST grille : " << (r4 ? "OK" : "ECHEC") << std::endl;
    std::cout << "TEST origine : " << (r5 ? "OK" : "ECHEC") << std::endl;

    return (r1 && r2 && r3 && r4 && r5) ? 0 : 1;
}