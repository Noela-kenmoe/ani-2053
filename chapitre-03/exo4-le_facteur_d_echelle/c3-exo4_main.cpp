#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKEvent/NkWindowEvent.h"
#include <iostream>

NKENTSEU_DEFINE_APP_DATA(([]() { return nkentseu::NkAppData{}; })());

int nkmain(const nkentseu::NkEntryState &state) {
    nkentseu::NkWindowConfig cfg ;
        cfg.title  = "Ma fenetre";
        /*cfg.width  = 1280 ;
        cfg.height = 720 ;*/
        cfg.minHeight = 50;
        cfg.minWidth = 100;

    nkentseu::NkWindow window(cfg);
    if (!window.Create(cfg)) {
        logger.Error("[app] creation fenetre echouee");
        return -1;
    }

    nkentseu::math::NkVec2u windowSize = window.GetSize();        
    nkentseu::math::NkVec2u renderTargetSize = window.GetDisplaySize(); 
    nkentseu::float32 dpiScale = window.GetDpiScale();             

     
       std::cout << "Fenetre: " << windowSize.x << "x" << windowSize.y << " | "
          << "Cible de rendu: " << renderTargetSize.x << "x" << renderTargetSize.y << " | "
          << "Echelle DPI: " << dpiScale << std::endl;

    bool running = true;
    while (running) {
        while (auto* event = nkentseu::NkEvents().PollEvent()) {
            if (event->Is<nkentseu::NkWindowCloseEvent>()) running = false;
        }
    }
    return 0;
}