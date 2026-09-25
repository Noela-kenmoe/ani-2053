#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKEvent/NkEventSystem.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKEvent/NkMouseEvent.h"
#include <string> // Nécessaire pour std::string et std::to_string

struct Camera {
    void Rotate(float dx, float dy) {
        // Logique de rotation de la caméra
    }
};

NKENTSEU_DEFINE_APP_DATA(([]() { return nkentseu::NkAppData{}; })());

using namespace nkentseu;

int nkmain(const nkentseu::NkEntryState &state) {
    NkWindowConfig cfg;
    cfg.title = "Rotation Camera avec Capture";
    cfg.width = 1280;
    cfg.height = 720;

    NkWindow window(cfg);
    Camera camera;

    while (window.IsOpen()) {
        while (NkEvent* ev = NkEvents().PollEvent()) {

            // 1. Fermeture de la fenêtre
            if (ev->Is<NkWindowCloseEvent>()) {
                window.Close();
            }
            else if (auto* press = ev->As<NkMouseButtonPressEvent>()) {
                if (press->GetButton() == NkMouseButton::NK_MB_RIGHT) {
                    window.CaptureMouse(true);
                }
            }

            // 3. Clic droit relâché (Libération de la souris)
            else if (auto* release = ev->As<NkMouseButtonReleaseEvent>()) {
                if (release->GetButton() == NkMouseButton::NK_MB_RIGHT) {
                    window.CaptureMouse(false);
                    window.SetTitle("Rotation Camera avec Capture"); 
                }
            }

            // 4. Déplacement de la souris (Regroupé)
            else if (auto* move = ev->As<NkMouseMoveEvent>()) {
                if (move->IsButtonDown(NkMouseButton::NK_MB_RIGHT)) {
                    int32 dx = move->GetDeltaX();
                    int32 dy = move->GetDeltaY();

                    // Action 1 : Modifier la caméra
                    camera.Rotate(static_cast<float>(dx), static_cast<float>(dy));

                    // Action 2 : Afficher les variations dans le titre
                    std::string t = "Dx: " + std::to_string(dx) + " | Dy: " + std::to_string(dy);
                    window.SetTitle(t.c_str());
                }
            }
        }
    }

    return 0;
}