#include "NKCanvas/App/NkCanvasApp.h"
#include "NKWindow/NKMain.h"
#include "NKLogger/NkLogger.h"
#include <iostream>

using namespace nkentseu;
class SondeApp : public nkentseu::renderer::NkCanvasApp {
private:
    uint64 compteur = 0;

public:
    /*void OnConfigure()  {
        // Pour tester le cas sans plafond, décommentez la ligne ci-dessous :
        Config().imagesParSeconde = 0;
    }*/
   bool OnInit() override {
    Config().imagesParSeconde = 60;
    compteur = 0;
    return true;
   }

    void OnRender(nkentseu::renderer::NkRenderWindow &target) override {
        compteur++;
        float32 t = Time();
        //std::cout<<"Passage : "<< compteur <<" Temps : " << t<<"s"<<std::endl; 
        if(t >= 10.0f){
            std::cout<<"fin du test. Compte total : "<< compteur <<" paasages en "<< t<<" secondes."<< std::endl;
            Quit();
        }
        // Sonde / Ligne de journal
        // (À conserver pour les tests avec journal, à commenter pour le test "Sans la ligne")
        //NkLog("Passage : {}, Temps : {}s", compteur, t);
        //std::cout<<"Passage : "<< compteur <<" Temps : " << t<<"s"<<std::endl; 
    }
};
NKENTSEU_DEFINE_APP_DATA(([](){
   nkentseu::NkAppData d{};
   d.appName = "fenetre";
   d. appVersion = "1.0.0";
   
   return d;
})());
int nkmain(const nkentseu::NkEntryState &state) {
    SondeApp app;
    return renderer::NkCanvasApp::Run<SondeApp>(state);
}