# EXERCICE 4 
Dans cet exercice il est question de affichez cote à cote le taille rendue par la fenetre, celle rendue par la cible de rendu, et le facteur d'échelle.

Pour cela je commence par créer une fentre avec le code minimal suivant :
```

```
La formule du facteur d'échelle est :
- Facteur d'échelle : **S**
```
S =Wcible/Wfenetre
```
Ces valeurs sont données grace a l'utilisation de :
```
void SetTitle(const NkString &title);
			math::NkVec2u GetSize() const;
			
			float32 GetDpiScale() const;
			math::NkVec2u GetDisplaySize() const;
```
j'ajoutant ces varibles a des instruction de sortie et je compile
```
PS C:\Users\NOELA\Desktop\ani-2053\chapitre-03\exo4-le_facteur_d_echelle> jenga build

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
  1. exercice 4 [WINDOWED_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: exercice 4                                                     Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: c3-exo4_main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\exercice 4\exercice 4.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 4.86s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘
════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           4.87s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```
Je lance ensuite l'exécution et j'obtient :
```
PS C:\Users\NOELA\Desktop\ani-2053\chapitre-03\exo4-le_facteur_d_echelle> jenga run

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
  ▶  EXECUTION  —  exercice 4.exe
     C:\Users\NOELA\Desktop\ani-2053\chapitre-03\exo4-le_facteur_d_echelle\Build\Bin\Debug-Windows\exercice 4\exercice 4.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

Fenetre: 1280x720 | Cible de rendu: 1920x1080 | Echelle DPI: 1.25

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (3.35s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```
Avec cette sortie nous avons donc :
- Fenetre : 1280*720
- Cible de rendu : 1920*1080
- Echelle DPI : 1.25