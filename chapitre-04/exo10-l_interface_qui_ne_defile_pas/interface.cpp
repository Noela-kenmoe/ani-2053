#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKEvent/NkEventSystem.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKCanvas/Renderer/Targets/NkRenderWindow.h"
#include "NKCanvas/Renderer/Shapes/NkRectangleShape.h"
#include "NKMath/NKMath.h"
#include "NKTime/NkTime.h"
#include <iostream>

NKENTSEU_DEFINE_APP_DATA(([]() { return nkentseu::NkAppData{}; })());
int nkmain (const nkentseu::NkEntryState &state){
    nkentseu::NkWindowConfig cfg;
    cfg.title = "fenetre";
    cfg.width = 1280;
    cfg.height = 720;

    nkentseu::NkWindow window;
    if (!window.Create(cfg)) {
        logger.Error("Failed to create window") ;
        return 1;
    }
    nkentseu::NkContextDesc contextDesc;
    contextDesc.api = nkentseu::NkGraphicsApi::NK_GFX_API_OPENGL;
    nkentseu::renderer::NkRenderWindow renderWindow(window, contextDesc);

    if(!renderWindow.IsValid()){
        logger.Error("Failed to initialize render window");
        return 2;
     }

    /*nkentseu::renderer::NkView2D worldView = renderWindow.GetDefaultView();
    float viewCenterX = 400.0f;
    worldTile.SetFillColor(nkentseu::renderer::NkColor2D::Blue);*/

    nkentseu::renderer::NkRectangleShape worldTile({80.0f, 80.f});
    worldTile.SetFillColor(nkentseu::renderer::NkColor2D::Blue);

    nkentseu::renderer::NkRectangleShape uiBar({1280.0f, 50.0f});
    uiBar.SetFillColor(nkentseu::renderer::NkColor2D{250, 0, 0, 255});
    uiBar.SetPosition({0.f, 0.f});
    float elapsedTime = 0.0f;
    float viewCenterX = 400.0f;

    nkentseu::renderer::NkView2D worldView;
    worldView.center = {viewCenterX, 300.f};
    worldView.size = {800.f, 600.f};

    bool captureWithReset = false;
    bool captureWithoutReset = false;
   
    nkentseu::NkClock clock;
    bool running = true;
    const bool useResetView = true;
    float targets[] = {400.0f, 700.0f, 1040.0f};
    int targetIndex = 0;

    while(running && window.IsOpen()){
        float dt = clock.Tick().delta;
        if(dt>0.1f)
        dt= 0.016f;
        auto &eventSystem = nkentseu::NkEvents();
        while(nkentseu::NkEvent* ev = nkentseu::NkEvents().PollEvent()){
            if(ev->Is<nkentseu::NkWindowCloseEvent>()){
                window.Close();
                running = false;
            }
        
        }
        viewCenterX += 200.0f * dt; 
        worldView.center.x = viewCenterX ;
        elapsedTime += dt;

        renderWindow.Clear(nkentseu::renderer::NkColor2D(30, 30, 30, 255));
        renderWindow.SetView(worldView);

        for (int i = 0; i < 20; ++i) {
            worldTile.SetPosition({i * 100.0f, 260.0f});
            renderWindow.Draw(worldTile);
        }
        
        float barX = 0.0f;
        if (useResetView) {
            //renderWindow.ResetView();
            barX = 0.0f;
        } else {
            
            barX = -(viewCenterX - 400.0f);
        } 

        //renderWindow.ResetView();
        renderWindow.Draw(uiBar);
        renderWindow.Display();

        if (elapsedTime >= 3.2f) {
            if (useResetView && !captureWithReset) {
                renderWindow.Capture("avec.png");
                captureWithReset = true;
            } else if (!useResetView && !captureWithoutReset) {
                renderWindow.Capture("sans.png");
                captureWithoutReset = true;
            }
        }
    if (targetIndex < 3 && viewCenterX >= targets[targetIndex]) {
        std::cout << "reset : yes, centre_x : " << static_cast<int>(viewCenterX) 
                  << ", bar_x : 0" << std::endl;
        targetIndex++;
    }
    }
    
    return 0;

}