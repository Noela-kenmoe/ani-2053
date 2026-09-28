# EXERCICE 2 DU CHAPITRE 4
Dans cet exercice je dois 
Pour cela je commence par écrire mon programme puis dans des strucutres de cntrole je :
- Récupère la lettre ou son code logique
```
NkKey key = kp->GetKey();
```

- Je récupère ensuite son code physique 
```
NkScancode scancode = NkKeycodeMap::NkKeyToScancode(key);
```
- j"affiche dans le terminal
```
std::cout << "Lettre / Touche (NkKey) : " << static_cast<int>(key)
                          << " | Code physique (NkScancode) : " << static_cast<int>(scancode)
                          << std::endl;
```
- Je compile 
```
PS C:\Users\NOELA\Desktop\ani-2053\chapitre-03\exo2-la_lettre_et_la_position> jenga build

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
  1. exercice.2 [WINDOWED_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: exercice.2                                                     Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: c4-exo2_main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\exercice.2\exercice.2.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.79s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           3.79s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```
- J'exécute 
```

```
1 Dans le clavier AZERTI :
* la touche préssée est : la touche **A**
* code virtuel :
```

```
PS C:\Users\NOELA\Desktop\ani-2053\chapitre-03\exo2-la_lettre_et_la_position> jenga run  

╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.0             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ▶  EXECUTION  —  exercice.2.exe
     C:\Users\NOELA\Desktop\ani-2053\chapitre-03\exo2-la_lettre_et_la_position\Build\Bin\Debug-Windows\exercice.2\exercice.2.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

Lettre / Touche (NkKey) : 41 | Code physique (NkScancode) : 0

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (4.13s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
* code physique :

2. Clavier QWERTY
* la touche préssée est : la touche **A**
* code virtuel :
```
PS C:\Users\NOELA\Desktop\ani-2053\chapitre-03\exo2-la_lettre_et_la_position> jenga run

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
  ▶  EXECUTION  —  exercice.2.exe
     C:\Users\NOELA\Desktop\ani-2053\chapitre-03\exo2-la_lettre_et_la_position\Build\Bin\Debug-Windows\exercice.2\exercice.2.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

Lettre / Touche (NkKey) : 42
Lettre / Touche (NkKey) : 80
Lettre / Touche (NkKey) : 42
Lettre / Touche (NkKey) : 80
Lettre / Touche (NkKey) : 42
Lettre / Touche (NkKey) : 80
Lettre / Touche (NkKey) : 43

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (19.35s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
````
* code physique :
Conclusion : ce qui ne change pas c'est le **keycode** mat"riel renvoye par **NkPressedEvent** ce qui change c'est le caratère envoyé peut importe le clavier 