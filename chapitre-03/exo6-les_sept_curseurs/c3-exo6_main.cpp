#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKEvent/NkEventSystem.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKEvent/NkMouseEvent.h"
#include <iostream>
#include <string>

NKENTSEU_DEFINE_APP_DATA(([]() { return nkentseu::NkAppData{}; })());

using namespace nkentseu;

int nkmain(const nkentseu::NkEntryState &state) {
    NkWindowConfig cfg;
    cfg.title = "Sept curseurs";
    cfg.width = 1280;
    cfg.height = 720;
    cfg.canFullscreen = false;
   
    NkWindow window(cfg);

    const NkWindow::NkCursorType zones[7] = {
        NkWindow::NkCursorType::Arrow,	
		NkWindow::NkCursorType::TextInput,	
		NkWindow::NkCursorType::Hand,		
		NkWindow::NkCursorType::ResizeNS,	
		NkWindow::NkCursorType::ResizeWE,	
		NkWindow::NkCursorType::ResizeNWSE, 
		NkWindow::NkCursorType::ResizeNESW	
    };
    int currentZoneIndex = -1;

    bool running = true;
    while (running && window.IsOpen()) {
        while (NkEvent* ev = NkEvents().PollEvent()) {

            // Fermeture via signal OS (ex: Alt+F4)
            if (ev->Is<NkWindowCloseEvent>()) {
                window.Close();
                running = false;
            }
            if(auto* move = ev->As<NkMouseMoveEvent>()){
              float mousex = move->GetX();
              float windowWidth = static_cast<float>(window.GetSize().x);
              

              float zone = windowWidth / 7.0f;
              int zoneindex = static_cast<int>(mousex / zone);
         

              if(zoneindex < 0) zoneindex=0;
              if(zoneindex > 6) zoneindex = 6;

              if(zoneindex != currentZoneIndex){
                currentZoneIndex = zoneindex;

                window.SetCursor(zones[currentZoneIndex]);
        
                std::cout<<"curseur sur la zone" << currentZoneIndex <<"-> nouveau curseur "<<std::endl;
              }
            }
        }
    }
    return 0;
}
