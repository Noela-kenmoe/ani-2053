# EXERCICE 1
Dans cet exercice je dois afficher le journal des évènements.
Je commence par écrire mon code et définir chaque catégories 
```
auto catégorie = ev->GetCategoryFlags();
            auto type = ev->GetType();
```
J'utilise ensuite la durée grace a la bibliothèque **chrono** pour calculer le temps qui sépare chaque évènement :
```
auto maintenant = std::chrono::steady_clock::now();
            auto duree = std::chrono::duration_cast<std::chrono::seconds>(maintenant - debut).count();

            if(duree >= 1) {

                logger.Info("--- TOTAL : {} evenement(s) recu(s) en 1 seconde ---", numberEvent);
                numberEvent = 0;
                debut = maintenant;
            }
```

Je compile :
```
PS C:\Users\NOELA\Desktop\ani-2053\chapitre-03\exo1-le_journal_des_evenements> jenga build

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
  1. exercice.1 [CONSOLE_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: exercice.1                                                      Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: c4-exo1_main.cpp
✓ Built: Build\Bin\Debug-Windows\exercice.1\exercice.1.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 4.51s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           4.51s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```
J'exécute le programme :
```
PS C:\Users\NOELA\Desktop\ani-2053\chapitre-03\exo1-le_journal_des_evenements> jenga run  

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
  ▶  EXECUTION  —  exercice.1.exe
     C:\Users\NOELA\Desktop\ani-2053\chapitre-03\exo1-le_journal_des_evenements\Build\Bin\Debug-Windows\exercice.1\exercice.1.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[2026-09-28 23:36:14.556] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:14.570] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:14.571] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:14.571] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:14.573] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:14.574] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:14.574] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:14.575] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:14.575] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:14.576] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:14.576] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:14.576] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:14.577] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:14.577] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:14.583] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:14.583] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:14.587] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:14.588] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:14.592] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:14.603] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:14.603] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:14.605] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:15.396] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.396] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.397] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.397] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.401] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.401] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.401] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.402] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.553] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.553] [INF] [default] [c4-exo1_main.cpp:59 in nkmain] -> --- TOTAL : 16 evenement(s) recu(s) en 1 seconde ---
[2026-09-28 23:36:15.553] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.563] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.563] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.611] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.611] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.612] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.612] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.693] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.693] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.693] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.694] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.717] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.718] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.718] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.718] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.790] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.790] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.794] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.795] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.804] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:15.805] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:16.030] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:16.030] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:16.030] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:16.031] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:16.309] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:16.309] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:16.309] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:16.310] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:16.314] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:16.314] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:16.314] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:16.315] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:16.584] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:16.584] [INF] [default] [c4-exo1_main.cpp:59 in nkmain] -> --- TOTAL : 17 evenement(s) recu(s) en 1 seconde ---
[2026-09-28 23:36:16.585] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:16.623] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:16.623] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:16.632] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:16.632] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:16.828] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:16.828] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:16.828] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:16.829] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:17.071] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:17.071] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:17.072] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:17.072] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:17.129] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:17.129] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:17.129] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:17.129] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:17.272] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:17.272] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:17.286] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:17.286] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:17.309] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:17.310] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|KEYBOARD, type = INPUT|KEYBOARD
[2026-09-28 23:36:17.703] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.703] [INF] [default] [c4-exo1_main.cpp:59 in nkmain] -> --- TOTAL : 12 evenement(s) recu(s) en 1 seconde ---
[2026-09-28 23:36:17.703] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.716] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.716] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.728] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.728] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.729] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.729] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.741] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.741] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.742] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.742] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.753] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.756] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.757] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.757] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.758] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.758] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.767] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.768] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.768] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.768] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.769] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.769] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.781] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.783] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.784] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.785] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.785] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.786] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.792] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.792] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.792] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.792] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.793] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.793] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.804] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.804] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.805] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.805] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.806] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.806] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.817] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.817] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.818] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.818] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.818] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.819] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.829] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.830] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.834] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.834] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.835] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.835] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.842] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.842] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.843] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.843] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.846] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.847] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.855] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.856] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.857] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.857] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.857] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.857] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.868] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.869] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.869] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.870] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.870] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.870] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.881] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.882] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.883] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.883] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.883] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.883] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.892] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.893] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.894] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.895] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.897] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.898] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.905] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.906] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.906] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.907] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.907] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.907] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.917] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.918] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.918] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.918] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.930] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:17.932] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.068] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.068] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.081] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.081] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.081] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.081] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.093] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.094] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.106] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.106] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.107] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.107] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.118] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.119] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.119] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.119] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.169] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.170] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.182] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.186] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.187] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.188] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.188] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.189] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.344] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.344] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.344] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.345] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.346] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.346] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.584] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.585] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.585] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.585] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.597] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.597] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.598] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.598] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.619] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.638] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.646] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.686] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.687] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.687] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.689] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.689] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.690] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.691] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.692] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.692] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.692] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.693] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.693] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.694] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.695] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.699] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.734] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.735] [INF] [default] [c4-exo1_main.cpp:59 in nkmain] -> --- TOTAL : 76 evenement(s) recu(s) en 1 seconde ---
[2026-09-28 23:36:18.736] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.736] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.736] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.752] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.753] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.753] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.753] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.754] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.754] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.786] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.786] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.799] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.801] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.801] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.802] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.811] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.812] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.812] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.812] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.824] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.824] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.836] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.837] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.849] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.849] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.861] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.861] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.873] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.874] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.887] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.888] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.889] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.889] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.899] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.900] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.911] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.912] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.912] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.912] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.914] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.926] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.927] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.928] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.928] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.928] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.929] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.929] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.929] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.929] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.934] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:18.936] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.038] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.038] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.038] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.038] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.050] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.050] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.050] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.051] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.051] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.051] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.063] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.063] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.063] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.063] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.064] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.064] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.075] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.075] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.076] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.076] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.076] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.077] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.087] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.088] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.090] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.091] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.091] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.092] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.101] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.102] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.102] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.102] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.102] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.103] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.113] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.116] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.118] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.119] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.120] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.120] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.125] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.126] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.126] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.127] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.127] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.127] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.138] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.139] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.140] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.140] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.140] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.140] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.151] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.152] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.153] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.153] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.153] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.154] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.163] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.165] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.166] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.166] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.166] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.167] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.176] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.177] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.178] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.181] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.181] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.182] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.199] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.200] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.200] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.202] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.203] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.204] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.204] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.204] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.205] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.205] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.205] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.205] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.214] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.219] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.221] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.221] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.222] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.222] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.227] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.228] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.231] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.241] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.242] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.243] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.244] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.244] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.244] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.244] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.251] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.252] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.253] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.253] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.253] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.254] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.264] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.270] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.272] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.273] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.273] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.273] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.276] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.277] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.278] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.278] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.278] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.278] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.289] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.289] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.302] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.303] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.303] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.304] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.402] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.402] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.402] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.403] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.415] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.415] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.428] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.428] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.429] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.430] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.440] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.441] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.441] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.441] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.454] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.454] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.455] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.455] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.502] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.502] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.515] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.516] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.517] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.517] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.518] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.518] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.692] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.692] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.692] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.692] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.704] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.704] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.705] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.705] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.705] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.705] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.717] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.717] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.718] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.720] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.720] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.720] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.729] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.731] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.732] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.734] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.734] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.735] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.742] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.742] [INF] [default] [c4-exo1_main.cpp:59 in nkmain] -> --- TOTAL : 111 evenement(s) recu(s) en 1 seconde ---
[2026-09-28 23:36:19.742] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.743] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.743] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.743] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.744] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.755] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.757] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.759] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.760] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.760] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.761] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.767] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.769] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.769] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.770] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.770] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.771] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.780] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.781] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.782] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.782] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.783] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.783] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.793] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.794] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.796] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.797] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.797] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.798] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.804] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.804] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.818] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.819] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.820] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.820] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.833] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.833] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.834] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.834] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.969] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.969] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.969] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.970] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.982] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.983] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.994] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.995] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.995] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:19.995] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.007] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.007] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.007] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.008] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.020] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.020] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.020] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.021] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.032] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.034] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.034] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.035] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.037] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.037] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.045] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.045] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.046] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.048] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.049] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.050] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.057] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.058] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.058] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.059] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.059] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.060] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.070] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.070] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.075] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.079] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.079] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.080] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.083] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.084] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.084] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.085] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.085] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.085] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.095] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.096] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.099] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.102] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.103] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.103] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.108] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.108] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.110] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.110] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.111] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.111] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.120] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.121] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.121] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.121] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.121] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.121] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.132] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.133] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.134] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.135] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.135] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.136] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.145] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.145] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.147] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.147] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.148] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.148] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.169] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.170] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.170] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.170] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.170] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.171] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.174] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.175] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.176] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.177] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.177] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.177] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.182] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.185] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.185] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.186] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.186] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.187] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.195] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.197] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.198] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.199] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.199] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.199] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.209] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.209] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.210] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.213] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.214] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.214] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.220] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.221] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.222] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.223] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.225] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.225] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.233] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.235] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.237] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.237] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.237] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.238] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.247] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.249] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.250] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.250] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.251] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.251] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.258] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.259] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.263] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.263] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.266] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.266] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.271] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.271] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.272] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.272] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.272] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.273] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.284] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.289] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.289] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.290] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.290] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.290] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.297] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.302] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.304] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.306] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.308] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.309] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.309] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.310] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.310] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.311] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.311] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.314] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.321] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.322] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.322] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.322] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.323] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.323] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.335] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.374] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.374] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.374] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.375] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.418] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.453] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.455] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.456] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.456] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.456] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.456] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.456] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.457] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.485] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.501] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.502] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.502] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.502] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.503] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.510] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.510] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.511] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.512] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.512] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.513] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.522] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.523] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.523] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.524] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.535] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.535] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.536] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.536] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.536] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.536] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.548] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.549] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.549] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.550] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.550] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.550] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.560] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.564] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.566] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.567] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.568] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.570] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.573] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.573] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.574] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.574] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.574] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.574] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.586] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.586] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.586] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.587] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.587] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.587] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.599] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.600] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.601] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.601] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.601] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.602] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.611] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.612] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.612] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.613] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.614] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.614] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.627] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.629] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.630] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.630] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.631] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.631] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.636] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.636] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.637] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.637] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.638] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.638] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.649] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.651] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.652] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.652] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.652] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.653] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.662] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.669] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.669] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.669] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.669] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.670] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.674] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.674] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.674] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.676] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.677] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.677] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.687] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.687] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.687] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.688] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.688] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.688] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.701] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.701] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.703] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.703] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.704] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.704] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.713] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.714] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.715] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.719] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.720] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.720] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.724] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.725] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.725] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.726] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.726] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.726] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.738] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.738] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.738] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.738] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.739] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.739] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.750] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.750] [INF] [default] [c4-exo1_main.cpp:59 in nkmain] -> --- TOTAL : 167 evenement(s) recu(s) en 1 seconde ---
[2026-09-28 23:36:20.751] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.754] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.754] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.754] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.755] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.763] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.766] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.769] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.769] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.775] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.775] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.776] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.776] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.787] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.789] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.791] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.791] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.800] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.801] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.802] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.802] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.814] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.821] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.822] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.822] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.825] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.825] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.826] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.826] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.838] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.838] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.838] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.839] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.852] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.853] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.854] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.854] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.863] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.866] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.875] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.876] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.876] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.876] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.888] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.888] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.888] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.889] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.900] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.902] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.914] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.915] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.925] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.926] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.938] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.938] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.938] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.938] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.950] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.950] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.950] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.951] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.963] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.969] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.969] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:20.969] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.165] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.165] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.178] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.179] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.179] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.179] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.191] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.191] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.203] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.203] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.215] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.215] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.215] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.216] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.228] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.229] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.278] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.279] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.280] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.280] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.291] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.291] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.291] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.292] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.456] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:21.457] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:21.482] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:21.505] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:21.552] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:21.572] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:21.591] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:21.604] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = WINDOW, type = WINDOW
[2026-09-28 23:36:21.607] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.607] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.608] [INF] [default] [c4-exo1_main.cpp:53 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE
[2026-09-28 23:36:21.608] [INF] [default] [c4-exo1_main.cpp:63 in nkmain] -> Evenement recu : categorie = INPUT|MOUSE, type = INPUT|MOUSE

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (7.50s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```
Le journal es évènements est visible dans le terminal