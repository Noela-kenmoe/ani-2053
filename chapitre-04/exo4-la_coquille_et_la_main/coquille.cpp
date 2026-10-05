#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKLogger/NkLog.h"

#include "NKCanvas/Core/NkContextDesc.h"
#include "NKCanvas/Core/NkGraphicsApi.h"
#include "NKCanvas/Renderer/Targets/NkRenderWindow.h"
#include "NKCanvas/Renderer/Core/NkRenderer2D.h"
#include "NKCanvas/App/NkCanvasApp.h"

#include "NKMath/NKMath.h"
#include "NKMath/NkColor.h"
#include "NKTime/NkTime.h"

NKENTSEU_DEFINE_APP_DATA(([]() {
    nkentseu::NkAppData d{} ;
    d.appName = "Tetris" ;
    d.appVersion = "1.0.0";
    return d ;
})()) ;

class Coquille : public nkentseu::renderer::NkCanvasApp {
    private:
        nkentseu::math::NkRect2f tete{100, 100, 50, 50};
        //nkentseu::float32 speed = 50;

        //nkentseu::float32 t = 0.f;
        //kentseu::float32 deltaTime = 0.f;
    public:
        Coquille() {
            Config().title = "coquille";
            Config().width = 800;
            Config().height = 600;
        }

        bool OnInit() override {
             tete.x = 0.0f;
            return true;
        }

        void OnUpdate(nkentseu::float32 deltaTime) override {
            tete.x += 100.0f * deltaTime;
            
            if (tete.x > 800.0f )
                tete.x = -50.0f;
        }

        void OnRender(nkentseu::renderer::NkRenderWindow &target) override {
            //renderWindow.Clear(nkentseu::renderer::NkColor2D(50,50,50,255));
            nkentseu::renderer::NkRenderer2D &r2d = target.GetRenderer2D();
            r2d.DrawFilledRect(tete, nkentseu::renderer::NkColor2D{255, 255,0, 255});}
        };

int nkmain(const nkentseu::NkEntryState &state) {
    return nkentseu::renderer::NkCanvasApp::Run<Coquille>(state) ;
}
