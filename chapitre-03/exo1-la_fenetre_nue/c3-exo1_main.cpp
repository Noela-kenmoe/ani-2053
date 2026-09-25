#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"

int nkmain(const nkentseu::NkEntryState &state) {
    // 1. Création unique de la fenêtre (utilise la config par défaut pour réduire le code)
    nkentseu::NkWindow window;

    // 2. Boucle principale basée sur l'état de la fenêtre (sans drapeau superflu)
    while (window.IsOpen()) {
        while (auto* event = nkentseu::NkEvents().PollEvent()) {
            if (event->Is<nkentseu::NkWindowCloseEvent>()) {
                window.Close(); // Ferme proprement la fenêtre
            }
        }
    }

    return 0;
}

