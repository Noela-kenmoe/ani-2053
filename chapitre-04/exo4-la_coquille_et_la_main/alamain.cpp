#include "NKWindow/NKMain.h"
#include "NKWindow/Core/NkWindow.h"
#include "NKLogger/NkLog.h"
#include "NKCanvas/Core/NkGraphicsApi.h"
#include "NKCanvas/Core/NkContextDesc.h"
#include "NKCanvas/Renderer/Targets/NkRenderWindow.h"
#include "NKCanvas/Renderer/Core/NkRenderer2D.h"
 

#include "NKMath/NKMath.h"
#include "NKMath/NkColor.h"
#include "NKTime/NkTime.h"

NKENTSEU_DEFINE_APP_DATA(([](){
   nkentseu::NkAppData d{};
   d.appName = "fenetre";
   d. appVersion = "1.0.0";
   return d;
})());

int nkmain(const nkentseu::NkEntryState &state){
   nkentseu::NkWindowConfig cfg;
    cfg.title = "Rotation Camera (Sans Capture)";
    cfg.width = 1280;
    cfg.height = 720;

    nkentseu::NkWindow window;

    if (!window.Create(cfg)) {
        logger.Error("Failed to create window") ;
        return 1;
    }

     nkentseu::NkContextDesc contextDesc;
     contextDesc.api = nkentseu::NkGraphicsApi::NK_GFX_API_SOFTWARE;
     nkentseu::renderer::NkRenderWindow renderWindow(window, contextDesc);

     if(!renderWindow.IsValid()){
        logger.Error("Failed to initialize render window");
        return 2;
     }

     bool running = true;
     auto &eventSystem = nkentseu::NkEvents();

     nkentseu::NkClock clock;
     nkentseu::NkChrono chrono;
     nkentseu::float32 t = 0.f;
     nkentseu::float32 posX= 100.0f;

     while(running){
        nkentseu::float32 dt = clock.Tick().delta;
       if(dt > 0.1f)
            dt = 1.0f / 60.0f;
            //t += dt;
       
            
        nkentseu::NkEvent *event;
         while(eventSystem.PollEvent(event)){
            if(event->Is<nkentseu::NkWindowCloseEvent>()){
                running = false;
            }
         }
         posX += 100.0f; 
         if (posX > 800.0f){
            posX = -50.0f;
         }
         renderWindow.Clear(nkentseu::renderer::NkColor2D(50,50,50,255));
            nkentseu::renderer::NkRenderer2D &r2d = renderWindow.GetRenderer2D();

            const nkentseu::math::NkRect2f box{posX, 300.0f, 50.0f, 50.0f};
            r2d.DrawFilledRect(box, nkentseu::renderer::NkColor2D{255,0,0,255});
            renderWindow.Display();
     }
     return 0;
}
