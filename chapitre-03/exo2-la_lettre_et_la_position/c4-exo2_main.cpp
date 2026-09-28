#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKEvent/NkEventSystem.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKEvent/NkMouseEvent.h"
#include "NKEvent/NkKeycodeMap.h"
#include <string>
#include <iostream>

NKENTSEU_DEFINE_APP_DATA(([]() { return nkentseu::NkAppData{}; })());

using namespace nkentseu;

int nkmain(const nkentseu::NkEntryState &state) {
    NkWindowConfig cfg;
    cfg.title = "Rotation Camera (Sans Capture)";
    cfg.width = 1280;
    cfg.height = 720;
    
   
    NkWindow window(cfg);
   
    bool running = true;
   
    while (running && window.IsOpen()) {
        while (NkEvent* ev = NkEvents().PollEvent()) {
            
            // Fermeture via signal OS (ex: Alt+F4)
            if (ev->Is<NkWindowCloseEvent>()) {
                window.Close();
                running = false;
            }
            

            else if (auto* kp = ev->As<NkKeyPressEvent>()) {
                // 1. Récupération de la lettre / code logique (NkKey)
                NkKey key = kp->GetKey();

                // 2. Récupération du code physique (NkScancode)
                NkScancode scancode = NkKeycodeMap::NkKeyToScancode(key);

                // Affichage des deux informations
                std::cout << "Lettre / Touche (NkKey) : " << static_cast<int>(key)
                          << " | Code physique (NkScancode) : " << static_cast<int>(scancode)
                          << std::endl;
            }
        }
        }

      return 0;
    }
        
