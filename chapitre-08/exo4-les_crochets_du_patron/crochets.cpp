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



