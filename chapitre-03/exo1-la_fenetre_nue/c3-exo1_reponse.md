# EXERCICE 1

cette exercice consite a crée une fentre nue avec un code minimal
Une fois le code écrit je compile avec la commande  :
```
jenga build
```
Le resultat de la commande est :
```
PS C:\Users\NOELA\Desktop\ani-2053\chapitre-03\exo1-la_fenetre_nue> jenga build

╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.0             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝

Loading workspace...

Configuration: Debug
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (1 projects):
  1. exercice 1 [WINDOWED_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: exercice 1                                                     Kind: WINDOWED_APP  ║

ℹ Found 1 source file(s)
✓   [1/1] Compiled: c3-exo1_main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\exercice 1\exercice 1.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.90s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           3.90s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

(venv) PS C:\Users\NOELA\Desktop\ani-2053\chapitre-03\exo1-la_fenetre_nue> jenga run

```
Ensuite je lance l'exécution avec la commande :
```
jenga run
```
Le resultat est :
```
(venv) PS C:\Users\NOELA\Desktop\ani-2053\chapitre-03\exo1-la_fenetre_nue> jenga run

╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.0             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ▶  EXECUTION  —  exercice 1.exe
     C:\Users\NOELA\Desktop\ani-2053\chapitre-03\exo1-la_fenetre_nue\Build\Bin\Debug-Windows\exercice 1\exercice 1.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (3.84s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```
## Explication du code ligne par ligne 

Mon code a **27 lignes** au total
Voici mon code annoté :
```
// inclusion des bibliothèques
#include "NKWindow/NKMain.h" // inclusion de la 
#include "NKWindow/NKWindow.h" // onclusion de la classe
#include "NKEvent/NkWindowEvent.h" // inclusion de la gestion des évènements liées a la fenetre

NKENTSEU_DEFINE_APP_DATA(([]() { return nkentseu::NkAppData{}; })()); // elle définie et initiale les données globales de l'application

int nkmain(const nkentseu::NkEntryState &state) { // le point d'entrée ou la fonction principale du progamme
    nkentseu::NkWindowConfig cfg ; // Définir les param-tres initiales de la fenetre tel que son nom, sa taille.
        cfg.title  = "Ma fenetre";
        cfg.width  = 1280 ;
        cfg.height = 720 ;

    nkentseu::NkWindow window(cfg);

    if (!window.Create(cfg)) {
        logger.Error("[app] creation fenetre echouee");
        return -1;
    }

    bool running = true;   // déclaration de la variable utilisée pour la boucle principale 
    while (running) { //Boucle d'évènement
        while (auto* event = nkentseu::NkEvents().PollEvent()) {
            if (event->Is<nkentseu::NkWindowCloseEvent>()) running = false;
        }
    }
    return 0;
}
```
## Les lignes similaires a celles du chapitre sont :
Le programme minimal du chapitre est le suivant : 
```
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"

using namespace nkentseu;

// Métadonnées de l'app — lues par le runtime AVANT nkmain().
// On passe une expression qui retourne un NkAppData (ici une lambda appelée).
NKENTSEU_DEFINE_APP_DATA(([]() {
    NkAppData d{};
    d.appName    = "MonJeu";
    d.appVersion = "0.1.0";
    return d;
})());

int nkmain(const NkEntryState& state) {
    // 1 Décrire la fenêtre
    NkWindowConfig cfg;
    cfg.title  = "Hello NKWindow";
    cfg.width  = 1280;
    cfg.height = 720;

    // 2 Créer la fenêtre
    NkWindow window;
    if (!window.Create(cfg)) {
        return -1;   // échec de création
    }

    // 3 Boucle principale (voir §3)
    while (window.IsOpen()) {
        while (NkEvent* ev = NkEvents().PollEvent()) {
            // traiter les entrées — détaillé dans le guide NKEvent
        }
        // mettre à jour la logique, puis dessiner (NKCanvas)
    }

    return 0;
}
```
- l'inclusion des bibliothèques 
```
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
```
- cette ligne n'est pas présente dans mon code minimal
```
using namespace nkentseu;
```
- Les métadonnées de l'application lue par le runtime
```
NKENTSEU_DEFINE_APP_DATA(([]() {
    NkAppData d{};
    d.appName    = "MonJeu";
    d.appVersion = "0.1.0";
    return d;
})());
```
- Le point d'entré du programme
```
int nkmain(const NkEntryState &state) {
```

- Crée un objet de configuration appartenant a la fentre : 
```
    NkWindowConfig cfg;
```
- Crée la fenetre et tester la création de la fenetre
```
NkWindow window;
    if (!window.Create(cfg)) {
        return -1;   // échec de création
    }
```
- Définir les paramètres de configuration de la fentre
```
    cfg.title  = "Ma fenetre";
    cfg.width  = 1280;
    cfg.height = 720;
``` 
- La boucle principale
```
while (window.IsOpen()) {
        while (NkEvent* ev = NkEvents().PollEvent()) {
            // traiter les entrées — détaillé dans le guide NKEvent
        }
```
- Fin du programme 
```
 return 0 ;
```


