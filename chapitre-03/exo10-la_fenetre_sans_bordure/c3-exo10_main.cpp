#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKEvent/NkEventSystem.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKEvent/NkMouseEvent.h"
#include <string>

NKENTSEU_DEFINE_APP_DATA(([]() { return nkentseu::NkAppData{}; })());

using namespace nkentseu;

int nkmain(const nkentseu::NkEntryState &state) {
    NkWindowConfig cfg;
    cfg.title = "Rotation Camera (Sans Capture)";
    cfg.width = 1280;
    cfg.height = 720;
    cfg.canFullscreen = false;
   
    NkWindow window(cfg);
   
    bool running = true;
    while (running && window.IsOpen()) {
        while (NkEvent* ev = NkEvents().PollEvent()) {

            // Fermeture via signal OS (ex: Alt+F4)
            if (ev->Is<NkWindowCloseEvent>()) {
                window.Close();
                running = false;
            }

            if (auto* press = ev->As<NkMouseButtonPressEvent>()) {
                if (press->IsLeft()) {
                    float x = press->GetX();
                    float y = press->GetY();
                    float winWidth = static_cast<float>(window.GetSize().x);


                    if (y >= 0 && y <= 40) {
                        // BOUTON RÉDUIRE (zone relative au bord droit)
                        if (x >= winWidth - 150 && x < winWidth - 100) {
                            window.Minimize();
                            ev->MarkHandled();
                        }
                        // BOUTON MAXIMISER / RESTAURER
                        else if (x >= winWidth - 100 && x < winWidth - 50) {
                            if (window.IsMaximized()) {
                                window.Restore();
                            } else {
                                window.Maximize();
                            }
                            ev->MarkHandled();
                        }
                        // BOUTON FERMER
                        else if (x >= winWidth - 50 && x <= winWidth) {
                            window.Close(); // Ferme réellement la fenêtre
                            running = false;
                            ev->MarkHandled();
                        }
                        // BARRE DE TITRE (Déplacement)
                        else {
                            window.BeginDragMove();
                            ev->MarkHandled();
                        }
                    }
                }
            }

            // DOUBLE CLIC (Maximiser / Restaurer sur la barre de titre)
            if (auto* dbl = ev->As<NkMouseDoubleClickEvent>()) {
                if (dbl->IsLeft()) {
                    float x = dbl->GetX();
                    float y = dbl->GetY();
                
                    float winWidth = static_cast<float>(window.GetSize().x);

                    if (y >= 0 && y <= 40 && x < winWidth - 150) {
                        if (window.IsMaximized()) {
                            window.Restore();
                        } else {
                            window.Maximize();
                        }
                        ev->MarkHandled();
                    }
                }
            }

            if (auto* release = ev->As<NkMouseButtonReleaseEvent>()) {
                if (release->IsLeft()) {
                    ev->MarkHandled();
                }
            }*/
        }
    }
    return 0;
}