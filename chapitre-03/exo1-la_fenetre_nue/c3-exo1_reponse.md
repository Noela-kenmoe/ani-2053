# EXERCICE 1

cette exercice consite a crée une fentre nue avec un code minimal
Une fois le code écrit je compile avec la commande  :
```
jenga build
```
Le resultat de la commande est :
```
jenga build 

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
  1. window [WINDOWED_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: window                                                         Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\window\window.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 5.66s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           5.66s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

```
Ensuite je lance l'exécution avec la commande :
```
jenga run
```
Le resultat est :
```
jenga run                                                      
           
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
  ▶  EXECUTION  —  window.exe
     C:\Users\NOELA\Desktop\jen\FirstWindow\Build\Bin\Debug-Windows\window\window.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (7.86s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```
## Explication du code ligne par ligne 

Mon code a **21 lignes** au total
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
- l'inclusion des bibliothèques 
```
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
```
- Le point d'entré du programme
```
int nkmain(const NkEntryState &state) {
```
- Crée un objet de configuration appartenant a la fentre : 
```
    NkWindowConfig cfg;
```
- Définir les paramètres de configuration de la fentre
```
    cfg.title  = "Ma fenetre";
    cfg.width  = 1280;
    cfg.height = 720;
``` 


