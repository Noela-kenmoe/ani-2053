#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKEvent/NkEvent.h"
#include "NKLogger/NkLog.h"
#include "NKTime/NkTime.h"
#include "NKTime/NkChrono.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKEvent/NkKeyboardEvent.h"

NKENTSEU_DEFINE_APP_DATA (([]() {
    nkentseu::NkAppData d{};
    d.appName = "bob";
    d.appVersion = "1.0.0";
    return d;
})());

int nkmain(const nkentseu::NkEntryState &state) {
    nkentseu::NkWindowConfig cfg;
    cfg.title  = "Ma fenetre";
    cfg.width  = 1280;
    cfg.height = 720;
    cfg.minimizable = true;
    cfg.resizable = true;
    cfg.maximizable = false;
    cfg.modal = true;
    cfg.closable = true;
    cfg.canFullscreen = true;
    cfg.movable = true;
    
    nkentseu::NkWindow window;
    
    if (!window.Create(cfg)) {
        logger.Error("[app] creation fenetre echouee");
        return -1;
    }

    bool running = true;
   
    while (running) {
        nkentseu::NkEvent* event = nullptr;
        while ((event = nkentseu::NkEvents().PollEvent()) != nullptr) {
            if (event->Is<nkentseu::NkWindowCloseEvent>()){
                running = false;
            }
         

            /*if (auto* keyEvent = event->As<nkentseu::NkKeyboardEvent>()){
                if (keyEvent->GetKey() == nkentseu::NkKey::NK_ESCAPE) {
                  running = false ;
                }
            }*/
         }
        // sans la fermeture
    }
    return 0;
}
