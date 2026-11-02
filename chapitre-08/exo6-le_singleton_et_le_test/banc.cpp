#include "NKCanvas/App/NkCanvasApp.h"
#include "NKEvent/NkEventDispatcher.h"
#include <iostream>
#include "NKWindow/NKMain.h"

using namespace nkentseu ;
// Version 1 : Directe (interroge le singleton global NkInput)
bool PeutSauterDirect(bool estAuSol) {
    // Supposons que l’on vérifie si le joueur est au sol et appuie sur espace
    return estAuSol && nkentseu::NkInput.IsKeyDown(nkentseu ::NkKey ::NK_SPACE) ;
}

// Version 2 : Testable (pure, reçoit l’état de la touche en paramètre)
bool PeutSauterTestable(bool estAuSol, bool espaceAppuye) {
    return estAuSol && espaceAppuye ;
}

class MonBancApp : public nkentseu ::renderer ::NkCanvasApp {
public :
    // OnCommandLine s’exécute avant la création de la fenêtre.
    // Retourner une valeur entière arrête immédiatement le programme avec ce code de sortie.
    NkOptional<int> OnCommandLine(const NkVector<NkString> &args) override {
        (void)args ;
        int erreurs = 0 ;

        // --- Exécution du banc de test pour la version testable ---
        // Cas 1 : Au sol + Espace enfoncé : Doit sauter (true)
        if (PeutSauterTestable(true, true) != true) erreurs++ ;
        
        // Cas 2 : Au sol + Pas d’espace : Ne doit pas sauter (false)
        if (PeutSauterTestable(true, false) != false) erreurs++ ;
        
        // Cas 3 : En l’air + Espace enfoncé : Ne doit pas sauter (false)
        if (PeutSauterTestable(false, true) != false) erreurs++ ;
        
        // Cas 4 : En l’air + Pas d’espace : Ne doit pas sauter (false)
        if (PeutSauterTestable(false, false) != false) erreurs++ ;
        bool resultatDirectSansFenetre = PeutSauterDirect(true) ;
        (void)resultatDirectSansFenetre ;
        return erreurs ;
    }
} ;

int nkmain(const nkentseu::NkEntryState &state) {
    return nkentseu::renderer ::NkCanvasApp ::Run<MonBancApp>(state) ;
}


