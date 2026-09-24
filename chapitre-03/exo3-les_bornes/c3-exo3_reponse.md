# EXERCICE 3 
Dans cet exercice il est question de fixer une taille mminimale et d'essaie de reduire la taille en dessous, recommencer jsuqu'a trouver la taille minimale aceptable par le système

- La première taille testée est :
```
#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKEvent/NkWindowEvent.h"

NKENTSEU_DEFINE_APP_DATA(([]() { return nkentseu::NkAppData{}; })());

int nkmain(const nkentseu::NkEntryState &state) {
    nkentseu::NkWindowConfig cfg ;
        cfg.title  = "Ma fenetre";
        /*cfg.width  = 1280 ;
        cfg.height = 720 ;*/
        cfg.minHeight = 800;
        cfg.minWidth = 600;

    nkentseu::NkWindow window(cfg);
    bool running = true;
    while (running) {
        while (auto* event = nkentseu::NkEvents().PollEvent()) {
            if (event->Is<nkentseu::NkWindowCloseEvent>()) running = false;
        }
    }
    return 0;
}
```

Après plusieurs modification je tombe sur la taille :
```
#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKEvent/NkWindowEvent.h"

NKENTSEU_DEFINE_APP_DATA(([]() { return nkentseu::NkAppData{}; })());

int nkmain(const nkentseu::NkEntryState &state) {
    nkentseu::NkWindowConfig cfg ;
        cfg.title  = "Ma fenetre";
        /*cfg.width  = 1280 ;
        cfg.height = 720 ;*/
        cfg.minHeight = 50;
        cfg.minWidth = 100;

    nkentseu::NkWindow window(cfg);
    bool running = true;
    while (running) {
        while (auto* event = nkentseu::NkEvents().PollEvent()) {
            if (event->Is<nkentseu::NkWindowCloseEvent>()) running = false;
        }
    }
    return 0;
}
```
Arriver à cette taille la fenetre ne peut plus etre réduire. La taille minimale du système est donc :
- **minHeight = 40**
- **minWidth = 100**