# DEMONSTRATION 1
Il est question dans cet exercice de construire le graphe d'un dépot manuellement, d'obtenir le graphe avec une commande et de comparer les deux graphes.

## GRAPHE 1: celuiavec la commande 
La commande pour avoir le graphe est : 
```
PS C:\Users\NOELA\Desktop\clone> git log --graph --oneline --all
```
Le résultat de cette commande affiche le graphe suivant : 
```
* 12d2525 (HEAD -> test) modification du fichier nb.cpp
| * 0e7c7f7 (main) Ajouter le fichier mp.cpp ce fichier va servir pour faire l'intégration pour résoudre l'xercice 10 le fichier vient d'etre mis sur la branche main
| * 9f4311f Ajouter le fichier nom.cpp ce fichier va servir pour faire l'intégration pour résoudre l'xercice 10 le fichier vient d'etre mis sur la branche main
|/  
*   300dd77 (test1) Commit C: Fusion de test dans main
|\  
| * 6466e04 Ajouter le fichier nb.cpp ce fichier va servir pour faire l'intégration pour rés
oudre l'xercice 10 une fois le fichier ajouter il sera fusionné dans la branche main
|/  
*   c9e50d4 (origin/main, origin/HEAD) Resolution du conflit dans fon.cpp
|\  
| * ca8e815  modifier la ligne du meme dépot
* | 64e3f0d  modifier la ligne du meme dépot
|/  
* a777703 Initial commit
```
## GRAPHE 2 : éffectué manuellement
```
         [12d525] (Head -> test)       [0e7c7f7] (main)
            |                             |
            |                          [9f4311f]
            |                            /
            |                           /
            |                          /
            +------------+------------+
                         |
                     [300dd77] (test1)   <-- commit de fusion
                      /     \
                [6466e04]    |
                      \     /
                     [c9e50d4] (origin/main) <-- commit de fusion
                       /    \
                 [ca8e815]  [64e3f0d]
                       \     / 
                      [a777703] Initial commit
```

### TABLEAU DE CORRESPONDANCE
|Elément du dessin|Sortie du terminal| Role dans le dépot git|
|-----------------|------------------|-----------------------|
|Noeuds/cercle|Symboles *| Les commits (ex: 12d12525,0e7c7f7,300dd77)|
|Lignes de jonction|Barres verticales | un fil continu|
|Séparations (ex: sous 12d2525/9f4311f)|Symbole|/(au-dessus de 300dd77) : une divergence|
|Jonctions(ex: c9e50d4 ou 300dd77)|Symboles| ou / qui se rejoingnent, un rapprochement ou une fusion|
|Etiquette  (ovales/rectangle)|Noms entre parenthèses (HEAD ->test, main..)|Références/pointeurs de branches et emplacement actuel(HEAD)|
