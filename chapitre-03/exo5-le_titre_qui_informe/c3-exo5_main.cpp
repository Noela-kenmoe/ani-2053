#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKMath/NKMath.h"
#include "NKEvent/NkEventSystem.h"
#include "NKEvent/NkKeyboardEvent.h"
#include <string>
#include <iostream>

NKENTSEU_DEFINE_APP_DATA(([]() { return nkentseu::NkAppData{}; })());


nkentseu::NkString docName = "Document1.txt";

bool isModified = false;

using namespace nkentseu;

// Fonction de mise à jour du titre
void UpdateWindowTitle(nkentseu::NkWindow& window, const nkentseu::NkString& docName, bool isModified) {
    
    nkentseu::math::NkVec2u size = window.GetSize(); 
   
    std::string titleStr = docName.Data();
    
    if (isModified) {
        titleStr += "*";
    }
    
    titleStr += " - " + std::to_string(size.x) + "x" + std::to_string(size.y);

    window.SetTitle(titleStr.c_str()); 
}

int nkmain(const nkentseu::NkEntryState &state) {
    nkentseu::NkWindowConfig cfg ;
        cfg.title  = "Ma fenetre";
        cfg.width  = 1280;
        cfg.height = 720;
        
    nkentseu::NkWindow window(cfg);

        
// A. Mise à jour initiale du titre au lancement
    UpdateWindowTitle(window, docName, isModified);

    while (window.IsOpen()) {
    
    while (nkentseu::NkEvent* ev = nkentseu::NkEvents().PollEvent()) {

        
        if (ev->Is<nkentseu::NkWindowCloseEvent>()) {
            window.Close();
        }

        // B. Redimensionnement de la fenêtre
        else if (ev->Is<nkentseu::NkWindowResizeEvent>()) {
            UpdateWindowTitle(window, docName, isModified);
        }

        // C. & D. Gestion des touches du clavier
        else if (auto* kp = ev->As<NkKeyPressEvent>()) {
            
            // D. Sauvegarde (Ctrl + S)
            if (kp->GetKey() == NkKey::NK_S && kp->HasCtrl()) {
                isModified = false;
                UpdateWindowTitle(window, docName, isModified);
                ev->MarkHandled(); // Marquer l'événement comme consommé
            }
            // C. Modification du fichier sur n'importe quelle autre frappe
            else if (!isModified) {
                isModified = true;
                UpdateWindowTitle(window, docName, isModified);
            }
        }
    }

    
}
    return 0;
}


