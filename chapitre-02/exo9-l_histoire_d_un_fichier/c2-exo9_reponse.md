
# EXERCICE 9

# L'histoire d'un fichier
Afin d'avoir l'historique des commits j'ai tapé la commande :
```
PS C:\Users\NOELA\Desktop\Nkentseu> git log --follow --stat -- Kernel/Foundation/NKMath/src/NKMath/NkRectangle.cpp
commit bdda350a054705f217f0daf5a54ab02bcb9c56ef
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Thu Jul 9 16:53:52 2026 +0100

    style: reformatage clang-format repo-wide (Kernel/Engine/Applications)
    
    Applique le .clang-format maison a tout l'arbre source C++ :
    - indentation par namespace (NamespaceIndentation: All)
    - public/private/protected indentes sous class (IndentAccessModifiers)
    - une ligne vide entre definitions (SeparateDefinitionBlocks)
    - une instruction par ligne, accolades attachees, tabs
    
    1748 fichiers (.h/.cpp/.inl/.mm). Verifie : NKGptTrain 25/25 et renderdemo 28/28 buildent OK apres reformatage.

 Kernel/Foundation/NKMath/src/NKMath/NkRectangle.cpp | 686 +++++++++++++++++++++++++++++++++++++++++++++++++--------------------------------------------------------
 1 file changed, 317 insertions(+), 369 deletions(-)

commit d557314e707baf17e53029b9d9cae2c5164dd417
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Tue May 5 20:04:22 2026 +0100

    update

 {Modules => Kernel}/Foundation/NKMath/src/NKMath/NkRectangle.cpp | 0
 1 file changed, 0 insertions(+), 0 deletions(-)

commit f1e536a58890ac267b12ab7df1004d0a43270c48
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Wed Apr 29 10:39:16 2026 +0100

    refactor 001

 Modules/Foundation/NKMath/src/NKMath/NkRectangle.cpp | 492 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++----------------------
 1 file changed, 391 insertions(+), 101 deletions(-)

Date:   Sat Mar 21 03:25:48 2026 +0100
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Sat Mar 21 03:25:48 2026 +0100

    bug fix vulkan opengl dx11 current bug software and dx12

 Modules/Foundation/NKMath/src/NKMath/NkRectangle.cpp | 108 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 1 file changed, 108 insertions(+)
(END)
```
1. SA CREATION
le fichier a été crée le 21 mars 2026 a l'occasion d'un correctif de bugs sur plusieurs API graphiques (vulkan, openGL, software, dx11). Le message annonce un correctif global, tandis que le diff montre la céation initiale de la structure avec 108 lignes de codes  


2. Les trois moments clés d'évolution 

- La refactorisation opaque
```
f1e536a5 refactor 001
```
Ce que le message dit : deux mots et un numéro (refactor 001)
Ce que le diff montre : une réecriture majeure du fichier avec 391 lignes ajoutées et 101 lignes supprimées. Seule l'inspection du diff permet de comprendre les changements apportés, ce qui constitue un manque clair d'information

- Le déplacement de fichier masquer sous un message vide
commit : **d557314e**
message : **update**
Ce que le message dit : Un seul mot, six lettres (update). Ce message ne dit absolument rien sur l'action réalisée.

Ce que le diff/stat montre : 0 ligne de code modifiée. La mesure --stat révèle qu'il s'agit en réalité du déplacement du fichier du dossier Modules/ vers le dossier Kernel/. C'est précisément pour cette raison que l'option --follow a été indispensable pour retracer l'historique au-delà de cette date.
- La normalisation automatique du code (le plus gros volume)
 Commit : bdda350a (9 juillet 2026)

Message :
```
style: reformatage clang-format repo-wide (Kernel/Engine/Applications)

Applique le .clang-format maison a tout l'arbre source C++ :

- indentation par namespace (NamespaceIndentation: All)

- public/private/protected indentes sous class (IndentAccessModifiers)

- une ligne vide entre definitions (SeparateDefinitionBlocks)

- une instruction par ligne, accolades attachees, tabs

1748 fichiers (.h/.cpp/.inl/.mm). Verifie : NKGptTrain 25/25 et renderdemo 28/28 buildent OK apres reformatage.
```

volume (stat): 1 file changed, 317 insertions(+), 369 deletions(-) (686 lignes touchées)

Ce que le message dit : Le message est très complet. Il documente le style appliqué, liste les règles d'indentation, précise la portée de l'opération (1 748 fichiers) et confirme la validation des builds après reformatage.

Ce que le diff montre : Avec 686 lignes modifiées (317 ajouts, 369 suppressions), ce commit représente le plus grand volume de modifications de toute l'histoire du fichier, alors qu'aucune ligne de code logique n'a été altérée.
- Nous avons tout d'abord le passage d'une implémentation de départ brute à une architecture propre
- Les fonctions ont été réorganisées pour standardiser l'API interne du module **NKMath** et harmoniser le type de données du rectangle avec les primitives géométrique du moteur

# cette analyse met en évidence la différence entre la forme d'un commit et son impact réel sur la code source

- Les messages muets masque l'historique : Un message comme update ne mentionne aucun changement alors qu'il déplace le composant dans l'arborescence (Modules vers Kernel), tandis que refactor 001 réécrit plus de 490 lignes sans en donner la raison.

- Le reformatage domine les volumes : Sur un total cumulé d'environ 1 286 lignes modifiées au cours de la vie de ce fichier, le commit de reformatage automatique clang-format (bdda350a) représente à lui seul plus de la moitiée de l'activité totale (686 lignes touchées), sans apporter la moindre modification fonctionnelle au composant.