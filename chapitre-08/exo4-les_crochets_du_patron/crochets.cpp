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
    virtual NkOptional<int> OnCommandLine(const NkVector<NkString> &args)override {
		(void)args;
        mOrderCounter++ ;
        std ::cout << mOrderCounter << "  - OnInit " 
                  << "  - Frame : "  << mFrameCount 
                  << "  - Frame : "  << Time() << std ::endl ;
		return NkOptional<int>();
	}
    bool OnInit() override {
        bool result = NkCanvasApp ::OnInit() ;
        mOrderCounter++ ;
        std ::cout << mOrderCounter << "  - OnInit " 
                  << "  - Frame : "  << mFrameCount 
                  << "  - Frame : "  << Time() << std ::endl ;
                  return result;
    }

    void OnLayout(const nkentseu::renderer::NkLayoutInfo &layout) override {
        NkCanvasApp::OnLayout(layout) ;
        mOrderCounter++ ;
        std ::cout << mOrderCounter << "  - OnLayout " 
                  << "  - Frame : "  << mFrameCount 
                  << "  - Time : "  << Time() << std ::endl ;
    }

    void OnUpdate(float deltaTime) override {
        NkCanvasApp::OnUpdate(deltaTime) ;
        mFrameCount++ ;

        // Enregistre uniquement les 5 premières images pour ne pas inonder la console
        if (mFrameCount <= 30) {
            mOrderCounter++ ;
            std::cout << mOrderCounter << "  - OnUpdate " 
                      << "  - Frame : "  << mFrameCount 
                      << "  - Time : "  << Time() << std ::endl ;
        }

        // Le programme s’arrête seul après 5 images
        if (mFrameCount >= 30) {
            Quit() ;
        }
    }

    void OnRender(nkentseu::renderer::NkRenderWindow &target) override {
        NkCanvasApp ::OnRender(target) ;
        if (mFrameCount <= 5) {
            mOrderCounter++ ;
            std::cout << mOrderCounter << "- OnRender" 
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
    virtual bool OnEvent(const NkEvent &event)override {
		(void)event;
        mOrderCounter++ ;
        std ::cout << mOrderCounter << "  - OnEvent " 
                  << " - Frame : " << mFrameCount 
                  << "  - Time : "  << Time() << std ::endl ;
		return false;
	}
    virtual bool OnPointer(const NkPointer &pointer) override{
		(void)pointer;
        mOrderCounter++ ;
        std ::cout << mOrderCounter << "  - OnPointer " 
                  << "  - Frame : "  << mFrameCount 
                  << "  - Frame : "  << Time() << std ::endl ;
		return false;
	}
    virtual bool OnKeyPress(const NkKeyPressEvent &event) override{
		(void)event;
        mOrderCounter++ ;
        std ::cout << mOrderCounter << "  - OnKeyPress " 
                  << "  - Frame : "  << mFrameCount 
                  << "  - Frame : "  << Time() << std ::endl ;
		return false;
	}
    virtual bool OnCloseRequested() override{
        mOrderCounter++ ;
        std ::cout << mOrderCounter << "  - OnCloseRequested " 
                  << "  - Frame : "  << mFrameCount 
                  << "  - Frame : "  << Time() << std ::endl ;
		return true;
	}
	virtual void OnPause() override{
        mOrderCounter++ ;
        std ::cout << mOrderCounter << "  - OnPause " 
                  << "  - Frame : "  << mFrameCount 
                  << "  - Frame : "  << Time() << std ::endl ;
	}
	virtual void OnResume()override {
        mOrderCounter++ ;
        std ::cout << mOrderCounter << "  - OnResume " 
                  << "  - Frame : "  << mFrameCount 
                  << "  - Frame : "  << Time() << std ::endl ;
	}

} ;

int nkmain(const nkentseu ::NkEntryState &state) {
    return nkentseu ::renderer ::NkCanvasApp ::Run<MonJeu>(state) ;
}



