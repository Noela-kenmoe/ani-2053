# EXERCICE 4 
Dans cet exercice il est question de affichez cote à cote le taille rendue par la fenetre, celle rendue par la cible de rendu, et le facteur d'échelle.

Pour cela je commence par créer une fentre ensuite je récupère les grandeurs physiques et logiques :
```
 nkentseu::math::NkVec2u windowSize = window.GetSize();        
    nkentseu::math::NkVec2u renderTargetSize = window.GetDisplaySize(); 
    nkentseu::float32 dpiScale = window.GetDpiScale(); 
```
je calcule le facteur S
```    
    float calculatedScale = (windowSize.x > 0) ? static_cast<float>(renderTargetSize.x) / static_cast<float>(windowSize.x) : 0.0f;
```
J'affiche les résultats
```  
       std::cout << "Fenetre: " << windowSize.x << "x" << windowSize.y << " | "
          << "Cible de rendu: " << renderTargetSize.x << "x" << renderTargetSize.y << " | "
          << "Echelle DPI: " << dpiScale 
          <<"le resultat de S est :"<< calculatedScale << std::endl;
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