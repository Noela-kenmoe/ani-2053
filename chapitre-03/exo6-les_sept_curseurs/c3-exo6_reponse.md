# EXERCICE 6
Dans cet exercice je dois faire apparaitre seot zones dans une fentre et change la forme du curseur selon la zone survolée.

Pour cela dans mon code je déclare une structure pour les différents types de curseurs
```
 const NkWindow::NkCursorType zones[7] = {
        NkWindow::NkCursorType::Arrow,	
		NkWindow::NkCursorType::TextInput,	
		NkWindow::NkCursorType::Hand,		
		NkWindow::NkCursorType::ResizeNS,	
		NkWindow::NkCursorType::ResizeWE,	
		NkWindow::NkCursorType::ResizeNWSE, 
		NkWindow::NkCursorType::ResizeNESW	
    };
```
Puis je déclare une variable qui va représenter la zone survolée
```
int currentZoneIndex = -1;
```
Ensuite des structures de controle je :
- recupère la largeur de la fenetre
```
float windowWidth = static_cast<float>(window.GetSize().x);
```
Ensuite je divise la largeur de la fenetre par 7
```
float zone = windowWidth / 7.0f;
```
Je définit la zone de survol pour chaque curseur
```
if(zoneindex < 0) zoneindex=0;
if(zoneindex > 6) zoneindex = 6;
```

Pour finir j'applique les curseur sur chaque zone en utilisant l'énumération définit plus haut pour changer les curseurs en fonction de la zone survolée
```
if(zoneindex != currentZoneIndex){
                currentZoneIndex = zoneindex;

                window.SetCursor(zones[currentZoneIndex]);
        
                std::cout<<"curseur sur la zone" << currentZoneIndex <<"-> nouveau curseur "<<std::endl;
              }
        
```
Je compile ensuite
```
PS C:\Users\NOELA\Desktop\ani-2053\chapitre-03\exo6-les_sept_curseurs> jenga build

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
  1. exercice6 [WINDOWED_APP]

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: exercice6                                                      Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: c3-exo6_main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\exercice6\exercice6.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 4.92s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           4.93s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

```
J'exécute 
```
PS C:\Users\NOELA\Desktop\ani-2053\chapitre-03\exo6-les_sept_curseurs> jenga run

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
  ▶  EXECUTION  —  exercice6.exe
     C:\Users\NOELA\Desktop\ani-2053\chapitre-03\exo6-les_sept_curseurs\Build\Bin\Debug-Windows\exercice6\exercice6.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

curseur sur la zone1-> nouveau curseur 
curseur sur la zone0-> nouveau curseur 
curseur sur la zone1-> nouveau curseur 
curseur sur la zone2-> nouveau curseur 
curseur sur la zone3-> nouveau curseur 
curseur sur la zone4-> nouveau curseur 
curseur sur la zone5-> nouveau curseur 
curseur sur la zone6-> nouveau curseur 

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (32.50s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```
Le resultat est :[les sept curseurs](curseur.mp4)

