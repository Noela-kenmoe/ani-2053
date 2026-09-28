#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKEvent/NkEvent.h"
#include "NKLogger/NkLog.h"
#include "NKTime/NkTime.h"
#include "NKTime/NkChrono.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKEvent/NkKeyboardEvent.h"
#include "NKEvent/NkMouseEvent.h"

NKENTSEU_DEFINE_APP_DATA (([]() {
    nkentseu::NkAppData d{};
    d.appName = "bob";
    d.appVersion = "1.0.0";
    return d;
})());

int nkmain(const nkentseu::NkEntryState &state) {
    nkentseu::NkWindowConfig cfg;
    cfg.title  = "Ma fenetre";
    /*cfg.width  = 1280;
    cfg.height = 720;
    cfg.minimizable = true;*/
    /*cfg.resizable = false;
    cfg.maximizable = true;
    cfg.modal = true;
    cfg.closable = true;
    cfg.canFullscreen = true;
    cfg.movable = false;

    cfg.resizable = true;*/ // Doit être à true pour permettre le redimensionnement à la souris

// 1. Définition de la taille minimale
    cfg.minWidth  = 800;
    cfg.minHeight = 600;
    


    nkentseu::NkWindow fen1, fen2;
    
    if (!fen1.Create(cfg)) {
        logger.Error("creation fenetre echouee");
        return -2;
    }
    
    if (!fen2.Create(cfg)) {
        logger.Error("creation fenetre echouee");
        return -2;
    }
    
    int numberfen =2;
    bool running = true;
   
   
    while (running) {
        nkentseu::NkEvent* event = nullptr;
        while ((event = nkentseu::NkEvents().PollEvent()) != nullptr) {
            if (auto* fen = event->As<nkentseu::NkWindowCloseEvent>()){
               if(fen->GetWindowId() == fen1.GetId()){
                  logger.Info("fermeture de la première fenetre");
                  fen1.Close();
                  numberfen--;
               } else if (fen->GetWindowId() == fen2.GetId()){
                  logger.Info("fermeture de la seconde fenetre");
                  fen2.Close();
                  numberfen--;
               }
               if(numberfen <= 0){
                running = false;
               }
               
            }
            
            if(auto* clic = event->As<nkentseu::NkMouseButtonPressEvent>()){
                   if(clic->GetWindowId() == fen1.GetId()){
                   logger.Info("clic sur la première fenetre");
            }
            if(clic->GetWindowId() == fen1.GetId()){
                logger.Info("clic sur la première fenetre");

            }else if (clic->GetWindowId()== fen2.GetId()){
                logger.Info("clic sur la deuxième fenetre");
             }
            }
            
              if (auto* keyEvent = event->As<nkentseu::NkKeyPressEvent>()){
                if (keyEvent->GetKey() == nkentseu::NkKey::NK_ESCAPE) {
                  running = false ;
                }
            }
         }
        
    }
    return 0;
}