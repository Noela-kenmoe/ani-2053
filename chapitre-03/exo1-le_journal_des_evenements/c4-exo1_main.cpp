#include <chrono>
#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKEvent/NkEventSystem.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKEvent/NkMouseEvent.h"
#include <string>

NKENTSEU_DEFINE_APP_DATA(([]() { return nkentseu::NkAppData{}; })());

using namespace nkentseu;

int nkmain(const nkentseu::NkEntryState &state) {
    NkWindowConfig cfg;
    cfg.title = "Rotation Camera (Sans Capture)";
    cfg.width = 1280;
    cfg.height = 720;
    cfg.canFullscreen = false;
   
    NkWindow window(cfg);
   
    bool running = true;
    int numberEvent = 0;
    auto debut = std::chrono::steady_clock::now();
    while (running && window.IsOpen()) {
        while (NkEvent* ev = NkEvents().PollEvent()) {
            numberEvent++;

            auto catégorie = ev->GetCategoryFlags();
            //auto type = ev->GetType();

            /*std::string catégories;

            if(catégories & static_cast<uint32_t>(nkentseu::NkEventCategory::NK_CAT_MOUSE)) {
                catégories += "MOUSE";
            }
            if(!(catégories.empty())) {
                catégories += " +";
                catégories += "INPUT";
            }*/

            //auto* typeTexte = nkentseu::NkEventType::ToString(type);
            /*auto typeTexte = nkentseu::NkEventType::ToString(type);
           logger.Info("Evenement recu : famille = {}, type = {}",catégories,typeTexte);*/

           // auto catégorieTexte = nkentseu::NkEventCategory::Value>(catégorie);
            auto catégorieTexte = nkentseu::NkEventCategory::ToString(static_cast<nkentseu::NkEventCategory::Value>(catégorie));
            //auto typeTexte = nkentseu::NkEventType::ToString(type);
              auto typeTexte = ev->GetTypeStr();
            auto maintenant = std::chrono::steady_clock::now();
            auto duree = std::chrono::duration_cast<std::chrono::seconds>(maintenant - debut).count();

            logger.Info("Evenement recu : categorie = {}, type = {}", catégorieTexte, typeTexte);

            //logger.Info("Evenement recu : {}", ev->ToString());

            if(duree >= 1) {
                //std::cout << "Nombre d'evenements recus en 1 seconde : " << numberEvent << std::endl;
                logger.Info("--- TOTAL : {} evenement(s) recu(s) en 1 seconde ---", numberEvent);
                numberEvent = 0;
                debut = maintenant;
            }
            logger.Info("Evenement recu : categorie = {}, type = {}", catégorieTexte, typeTexte);
            // Fermeture via signal OS (ex: Alt+F4)
            if (ev->Is<NkWindowCloseEvent>()) {
                window.Close();
                running = false;
            }

        }
    }
    return 0;
}
