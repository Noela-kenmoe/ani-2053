#include "NKCanvas/App/NkCanvasApp.h"
#include "NKCanvas/Renderer/Core/NkTransformable.h"
#include <iostream>
#include <fstream>
#include "NKGui/Core/NkGuiDrawList.h"
#include "NKCanvas/Renderer/Resources/NkSprite.h"
#include "NKWindow/NKMain.h"

using namespace nkentseu;
using namespace renderer;
using namespace nkgui;

// Classe composite héritant de NkTransformable et NkDrawable pour contenir un autre élément
class NkCompositeNode : public nkentseu::renderer::NkTransformable, public NkDrawable {
public:
    NkDrawable* mChild = nullptr;

    void SetChild(NkDrawable* child) {
        mChild = child;
    }

    virtual void Draw(NkRenderTarget& target, const NkRenderStates& states) const override {
        NkRenderStates local = states;
        local.transform *= GetTransform(); // Compose l'état avec notre transform
       
        if (mChild != nullptr) {
            mChild->Draw(target, local);
        }
    }
    virtual void Draw(nkgui::NkGuiDrawList &dl, const NkRenderStates& states)  {
        NkRenderStates local = states;
        local.transform *= GetTransform(); // Compose l'état avec notre transform
        if(auto* compositeChild = dynamic_cast<NkCompositeNode*>(mChild)){
        compositeChild->Draw(dl, local);
       }
       /* else if (auto* spriteChild = dynamic_cast<NkSprite*>(mChild)) {
            spriteChild->Draw(dl, local);
        }*/
    }
};

class CompositeApp : public NkCanvasApp {
public:
    NkCompositeNode mRoot;
    NkCompositeNode mMiddle;
    nkentseu::renderer::NkSprite mSprite;

    bool OnInit() override{
        std::cout<<"ERREUR";
        // Configuration de la hiérarchie à 3 niveaux
        mRoot.SetChild(&mMiddle);
        mMiddle.SetChild(&mSprite);

        // Positionnements et rotation (niveau milieu)
        mRoot.SetPosition(nkentseu::math::NkVector2f(100.f, 100.f));
        mMiddle.SetPosition(nkentseu::math::NkVector2f(50.f, 0.f));
        mMiddle.SetRotation(nkentseu::math::NkAngle(90.f)); // Rotation de 90 degrés au niveau du milieu
        mSprite.SetPosition(nkentseu::math::NkVector2f(20.f, 0.f));

        // Calcul et écriture de la position mesurée via le transform composé (TransformPoint)
        NkTransform totalTransform = mRoot.GetTransform() * mMiddle.GetTransform() * mSprite.GetTransform();
        nkentseu::math::NkVector2f measuredPos = totalTransform.TransformPoint(nkentseu::math::NkVector2f(0.f, 0.f));
        std::ofstream fichier("C:/Users/NOELA/Desktop/ani-2053/chapitre-08/exo8-le_composite_a_trois_niveaux/composite.txt");
        if(!fichier.is_open()){
            fichier<< "Mesuré : x=" << measuredPos.x << " y=" << measuredPos.y << std::endl;
            fichier.close();
        }else {
            std::cout<<"ERREUR";
        }
        std::cout<< "Mesuré : x=" << measuredPos.x << " y=" << measuredPos.y << std::endl;
        return true;
        
    }

    void OnUpdate(float dt) override {
        // Boucle de mise à jour si nécessaire
    }

    void OnDraw(nkgui::NkGuiDrawList &dl) {
        NkRenderStates states; 
        /*if(auto* compositeChild = dynamic_cast<NkCompositeNode*>(mChild)){
        compositeChild->Draw(dl, local);
       }else if (auto* spriteChild = dynamic_cast<NkSprite*>(mChild)){
        spriteChild->Draw(dl, local);
       }*/
        mRoot.Draw(dl, states);
    }
};

 int nkmain(const nkentseu ::NkEntryState &state) {
        CompositeApp app;
    return nkentseu::renderer::NkCanvasApp::Run<CompositeApp>(state);
}



