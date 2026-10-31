#include "NKCanvas/App/NkCanvasApp.h"
#include <iostream>
#include "NKWindow/NKMain.h"
#include <fstream>

using namespace nkentseu;
class MonJeu : public nkentseu ::renderer ::NkCanvasApp {
private :
    int mOrderCounter = 0 ;
    int mFrameCount = 0 ;

public :
    MonJeu() {
        mOrderCounter++ ;
        std ::cout << mOrderCounter << "  - Constructeur " 
                  << "  - Frame : "  << mFrameCount 
                  << "  - Time : "  << Time() << std ::endl ;
    }

    ~MonJeu() override {
        mOrderCounter++ ;
        std ::cout << mOrderCounter << "  - Destructeur " 
                  << "  - Frame : "  << mFrameCount 
                  << "  - Time : "  << Time() << std ::endl ;
    }

    // --- Redéfinition des crochets virtuels de NkCanvasApp ---

    bool OnInit() override {
        bool result = NkCanvasApp ::OnInit() ;
        mOrderCounter++ ;
        std ::cout << mOrderCounter << "  - OnInit " 
                  << "  - Frame : "  << mFrameCount 
                  << "  - Frame : "  << Time() << std ::endl ;
                  return result;
    }

    void OnLayout(const nkentseu::renderer::NkLayoutInfo &layout) override {
        NkCanvasApp ::OnLayout(layout) ;
        mOrderCounter++ ;
        std ::cout << mOrderCounter << "  - OnLayout " 
                  << "  - Frame : "  << mFrameCount 
                  << "  - Time : "  << Time() << std ::endl ;
    }

    void OnUpdate(float deltaTime) override {
        NkCanvasApp ::OnUpdate(deltaTime) ;
        mFrameCount++ ;

        // Enregistre uniquement les 5 premières images pour ne pas inonder la console
        if (mFrameCount <= 5) {
            mOrderCounter++ ;
            std ::cout << mOrderCounter << "  - OnUpdate " 
                      << "  - Frame : "  << mFrameCount 
                      << "  - Time : "  << Time() << std ::endl ;
        }

        // Le programme s’arrête seul après 5 images
        if (mFrameCount >= 5) {
            Quit() ;
        }
    }

    void OnRender(nkentseu::renderer::NkRenderWindow &target) override {
        NkCanvasApp ::OnRender(target) ;
        if (mFrameCount <= 5) {
            mOrderCounter++ ;
            std ::cout << mOrderCounter << "- OnRender" 
                      << "  - Frame : "  << mFrameCount 
                      << "  - Time : "  << Time() << std ::endl ;
        }
    }

    void OnShutdown() override {
        mOrderCounter++ ;
        std ::cout << mOrderCounter << "  - OnShutdown " 
                  << " - Frame : " << mFrameCount 
                  << "  - Time : "  << Time() << std ::endl ;
        NkCanvasApp ::OnShutdown() ;
    }
} ;

int nkmain(const nkentseu ::NkEntryState &state) {
    return nkentseu ::renderer ::NkCanvasApp ::Run<MonJeu>(state) ;
}



/*
class MonJeu : public renderer::NkCanvasApp {
private:
    //std::ofstream mLog;
    int mOrderCounter = 0;
    int mFrameCount = 0;

public:
    MonJeu() {
        mOrderCounter++;
        //mLog.open("crochets_journal.txt", std::ios::out | std::ios::trunc);
        std::cout<<"Constructeur"<<std::endl;
    }

    ~MonJeu() override {
        if (mLog.is_open()) {
            mLog.close();
        }
       mOrderCounter++;
       std::cout<<"Destructeur"<<std::endl;
    }

    // Redéfinissez ici chaque crochet trouvé dans NkCanvasApp.h
    // Exemple de squelette pour un crochet (adaptez selon les noms réels de l'en-tête) :
    bool OnInit() override {
        NkCanvasApp::OnInit();
        std::cout<<OnInit<<std::endl;
        return 0;
    }

    void OnLayout() override { 
        nkentseu::renderer ::NkCanvasApp ::OnLayout() ;
        std ::cout << "OnLayout" << std ::endl ;
    }

    void OnUpdate(float deltaTime) override {
        NkCanvasApp::OnUpdate(deltaTime);
        mFrameCount++;
        if (mFrameCount <= 5) {
            std ::cout << "OnUpdate (Frame "<< mFrameCount << ", Time : "  << Time() << " ) " << std ::endl ;
        }

        // Arrêt automatique du programme après 5 trames
        if (mFrameCount >= 5) {
            Quit() ;
        }
    }

    void OnRender(nkentseu::renderer::NkRenderWindow  &target) override {
        NkCanvasApp::OnRender(target);
        if (mFrameCount <= 5) {
            std ::cout << "OnRender" << std ::endl ;
        }
    }

    void OnShutdown() override {
        std ::cout << "OnShutdown" << std ::endl ;
        NkCanvasApp::OnShutdown();
    }

// Point d'entrée requis par le kit Canvas
int nkmain(const NkEntryState &state) {
    return renderer::NkCanvasApp::Run<MonJeu>(state);
}
*/
/*Class MonJeu : public renderer ::NkCanvasApp {
Private :
    Int mFrameCount = 0 ;

Public :
    MonJeu() {
        Std ::cout << « Constructeur » << std ::endl ;
    }

    ~MonJeu() override {
        Std ::cout << « Destructeur » << std ::endl ;
    }

    // --- Redéfinition des crochets virtuels ---

    Void OnInit() override {
        Renderer ::NkCanvasApp ::OnInit() ;
        Std ::cout << « OnInit » << std ::endl ;
    }

    Void OnLayout() override {
        Renderer ::NkCanvasApp ::OnLayout() ;
        Std ::cout << « OnLayout » << std ::endl ;
    }

    Void OnUpdate(float deltaTime) override {
        Renderer ::NkCanvasApp ::OnUpdate(deltaTime) ;
        mFrameCount++ ;
        
        if (mFrameCount <= 5) {
            std ::cout << « OnUpdate (Frame «  << mFrameCount << « , Time : «  << Time() << « ) » << std ::endl ;
        }

        // Arrêt automatique du programme après 5 trames
        If (mFrameCount >= 5) {
            Quit() ;
        }
    }

    Void OnRender(NKCanvas &target) override {
        Renderer ::NkCanvasApp ::OnRender(target) ;
        If (mFrameCount <= 5) {
            Std ::cout << « OnRender » << std ::endl ;
        }
    }

    Void OnShutdown() override {
        Std ::cout << « OnShutdown » << std ::endl ;
        Renderer ::NkCanvasApp ::OnShutdown() ;
    }
} ;

// Point d’entrée obligatoire
Int nkmain(const NkEntryState &state) {
    Return renderer ::NkCanvasApp ::Run<MonJeu>(state) ;
}
*/

