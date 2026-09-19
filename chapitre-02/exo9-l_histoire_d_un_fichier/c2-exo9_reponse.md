
# EXERCICE 9

# L'histoire d'un fichier
Afin d'avoir l'historique des commits j'ai tapé la commande :
```
git log --follow --oneline -- Kernel/Foundation/NKMath/src/NKMath/NkRectangle.cpp
bdda350a style: reformatage clang-format repo-wide (Kernel/Engine/Applications)
d557314e update
f1e536a5 refactor 001
9c49f79f bug fix vulkan opengl dx11 current bug software and dx12
```
1. SA CREATION
le fichier a été crée lors de la resolution des bugs liée a la gestion des différentes  API graphiques (vulkan, openGL, software, dx11) le besoin d'unifacation de calcul de zonne d'affichage (rectangle, viewport) a initié l'implementation de la structure de rectangle. Cela est visible par le resultat suivant : 
```
9c49f79f bug fix vulkan opengl dx11 current bug software and dx12
```
2. Les trois moments clés d'évolution 
```
f1e536a5 refactor 001
```
- Nous avons tout d'abord le passage d'une implémentation de départ brute à une architecture propre
- Les fonctions ont été réorganisées pour standardiser l'API interne du module **NKMath** et harmoniser le type de données du rectangle avec les primitives géométrique du moteur

3. La mise a jour Fonctionnelle 

```
d557314e update
```
Ce message montre la mise a jour applicative du code source, l'ajustement des méthodes utilitaires sur la classe nécessaires aux sous-système de plus haut niveau (interface utilisateur, moteur de rendu)

4. La normalisation du code
```
bdda350a style: reformatage clang-format repo-wide (Kernel/Engine/Applications)
```
L'outil automatisé **clang-format** a été appliqué sur l'ensemble du projet dans le cadre d'un nettoyage global du dépot **repo-wide**

## L'histoire de NKRectangle montre une évolution classique d'un composant bas niveau 