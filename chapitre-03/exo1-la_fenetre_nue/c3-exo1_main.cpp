#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKEvent/NkWindowEvent.h"

NKENTSEU_DEFINE_APP_DATA(([]() { return nkentseu::NkAppData{}; })());

int nkmain(const nkentseu::NkEntryState &state) {
    nkentseu::NkWindowConfig cfg ;
        cfg.title  = "Ma fenetre";
        cfg.width  = 1280 ;
        cfg.height = 720 ;

    nkentseu::NkWindow window(cfg);

    if (!window.Create(cfg)) {
        logger.Error("[app] creation fenetre echouee");
        return -1;
    }
    
    bool running = true;
    while (running) {
        while (auto* event = nkentseu::NkEvents().PollEvent()) {
            if (event->Is<nkentseu::NkWindowCloseEvent>()) running = false;
        }
    }
    return 0;
}