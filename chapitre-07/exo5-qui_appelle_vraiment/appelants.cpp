#include "NKCanvas/App/NkCanvasApp.h"
#include "NKWindow/NKMain.h"
#include <iostream>
#include "NKCanvas/Renderer/Targets/NkRenderTarget.h"
#include "NKCanvas/Renderer/Core/NkRenderer2DTypes.h"

using namespace nkentseu;
class MonObjetDessiner : public nkentseu::renderer::NkDrawable {
    public :
    void Draw(nkentseu::renderer::NkRenderTarget &target, const nkentseu::renderer::NkRenderStates &states) const override {
        nkentseu::renderer::NkVertex2D vertices[4] = {
            {-0.5f, -0.5f, 0.0f, 0.0f, 255, 255, 255, 255},
            {0.5f, -0.5f, 0.0f, 0.0f, 255, 255, 255, 255},
            {-0.5f, 0.5f, 0.0f, 0.0f, 255, 255, 255, 255},
            {-0.5f, 0.5f, 0.0f, 0.0f, 255, 255, 255, 255}
        };
        target.Draw(vertices, 4, nkentseu::renderer::NkPrimitiveType::NK_LINES, states);
    }
};

class MonApp : public nkentseu::renderer::NkCanvasApp {
    private :
    MonObjetDessiner objet;
    public :
      void OnUpdate(float32 dt) override {

      }
      void OnRender(nkentseu::renderer::NkRenderWindow  &target) override {
        target.Clear(nkentseu::renderer::NkColor2D(255, 0, 0, 255));
        target.Draw(objet);
      }
};
NKENTSEU_DEFINE_APP_DATA(([](){
   nkentseu::NkAppData d{};
   d.appName = "fenetre";
   d. appVersion = "1.0.0";
   return d;
})());
int nkmain(const nkentseu::NkEntryState &state) {
    MonApp app;
    return renderer::NkCanvasApp::Run<MonApp>(state);
}