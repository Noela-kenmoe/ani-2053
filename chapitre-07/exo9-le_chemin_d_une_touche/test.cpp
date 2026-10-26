#include "NKCanvas/App/NkCanvasApp.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkEvent.h"
#include <iostream>

using namespace nkentseu;
class ToucheApp : public nkentseu::renderer::NkCanvasApp {
public:
    bool OnInit() override {
        // Initialisation de l'application
        return true;
    }

    // Point d'arrivée de l'événement clavier dans votre code
    /*void OnKeyPress(const nkentseu::NkKeyPressEvent& event) {
        // Vous pouvez inspecter l'événement ici (ex: code de la touche)
        std::cout << "Touche detectee dans OnKeyPress !" << std::endl;
    }*/
     bool OnKeyPress(const NkKeyPressEvent &event) override {
        (void)event;
        std::cout << "Touche detectee dans OnKeyPress !" << std::endl;
        return false;
    }

    void OnRender(nkentseu::renderer::NkRenderWindow &target) override {
        // Boucle de rendu
        target.Clear(nkentseu::renderer::NkColor2D(255, 0, 0, 255));
    }
};

int nkmain(const nkentseu::NkEntryState &state) {
    ToucheApp app;
    return renderer::NkCanvasApp::Run<ToucheApp>(state);
}



