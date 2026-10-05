#include "NKWindow/NKMain.h"
#include "NKWindow/Core/NkWindow.h"
#include "NKCanvas/App/NkCanvasApp.h"


using namespace nkentseu;
using namespace nkentseu::renderer;

class fenetre : public NkCanvasApp{
    public :
       fenetre()
       {
        Config().title= "fenetre nue";
        Config().width= 900;
        Config().height= 500;
        Config().clearColor = NkColor2D(255,255,24,255);
       }
};

int nkmain(const NkEntryState& state) {
    return NkCanvasApp::Run<fenetre>(state);
}