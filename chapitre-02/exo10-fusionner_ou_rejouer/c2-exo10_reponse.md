# EXERCICE 10 : FUSIONNER OU REJOUER
## POUR LA FUSION

1. Tout d'abord je commence par véreifier dans quelle branche je me trouve avec la commande et son résutat est  : 
```cpp
git branch
* test
```

2. Ensuite je fais une modification puis je tape les commandes et le resultat est le suivant :
```
PS C:\Users\NOELA\Desktop\test> git add .                                 
>> cette modification va servire pour la fusion des deux branche"
[test 3259cc3] modifier le fichier fon.cpp cette modification va servire pour la fusion des deux branche
 1 file changed, 1 insertion(+)
```
3. je bascule ensuite sur la branche main avec la commande :
```
git switch main
Switched to branch 'main'
Your branch is ahead of 'origin/main' by 2 commits.

```
4. Puis j'éffectue une modification et je tape les commandes :
```
PS C:\Users\NOELA\Desktop\test> git add .                                 
PS C:\Users\NOELA\Desktop\test> git commit -m "modifier le fichier fon.cpp sur la branche main
>> cette modification va servire pour la fusion des deux branche"
[main 4b30fe7] modifier le fichier fon.cpp sur la branche main cette modification va servire pour la fusion des deux branche
 1 file changed, 1 insertion(+), 1 deletion(-)
````
5. Je peux maintenat effectuer la fusion, pour cela je tape : 
```
git merge test
Auto-merging fon.cpp
Merge made by the 'ort' strategy.
 fon.cpp | 1 +
 1 file changed, 1 insertion(+)
```
6. Je vérifie avec **git status**
```
git status
On branch main
Your branch is ahead of 'origin/main' by 5 commits.  (use "git push" to publish your local commits)

nothing to commit, working tree clean
```
7. Je peux désormais afficher le graphe 
```
PS C:\Users\NOELA\Desktop\test> git log --graph --oneline --all
*   272a76f (HEAD -> main) Merge branch 'test'
|\  
| * 3259cc3 (test) modifier le fichier fon.cpp cette modification va servire pour la fusion des deux branche
* | 4b30fe7 modifier le fichier fon.cpp sur la branche main cette modification va servire pour la fusion des deux branche
|/  
* ee41f02 modifier le fichier fon.cpp sur la branche main cette modification va servire pour la fusion des deux branche
* e205d87 modifier le fichier fon.cpp cette modification va servire pour la fusion des deux branche
* 629449a (origin/main, origin/HEAD) Initial commit
```

## POUR REJOUER
 1. Je revient au commit avant la fusion, grace a la commande : 
 ```
git reset --hard 4b30fe7
HEAD is now at 4b30fe7 modifier le fichier fon.cpp sur la branche main cette modification va servire pour la fusion des deux branche
 ```
 2. je bascule sur la branche test
 ```
PS C:\Users\NOELA\Desktop\test> git switch test
Switched to branch 'test'
 ```
 3. je réaligne l'historique de test au sommet de main
 ```
PS C:\Users\NOELA\Desktop\test> git rebase main
Successfully rebased and updated refs/heads/test.
 ```
 4. je bascule maintenant sur la branche main 
 ```
PS C:\Users\NOELA\Desktop\test> git switch main
Switched to branch 'main'
Your branch is ahead of 'origin/main' by 3 commits.
  (use "git push" to publish your local commits)
 ```
5. j'intègre la branche réalignée 
```
PS C:\Users\NOELA\Desktop\test> git merge test
Updating 4b30fe7..e310a9a
Fast-forward
 fon.cpp | 1 +
 1 file changed, 1 insertion(+)
 ```
 6. J'affiche le graphe
 ```
PS C:\Users\NOELA\Desktop\test> git log --graph --oneline --all
* e310a9a (HEAD -> main, test) modifier le fichier fon.cpp cette modification va servire pour la fusion des deux branche
* 4b30fe7 modifier le fichier fon.cpp sur la branche main cette modification va servire pour la fusion des deux branche
* ee41f02 modifier le fichier fon.cpp sur la branche main cette modification va servire pour la fusion des deux branche
* e205d87 modifier le fichier fon.cpp cette modification va servire pour la fusion des deux branche
* 629449a (origin/main, origin/HEAD) Initial commit
```
### LA DIFFERENCE ENTRE LES DEUX GRAPHE
- Le graphe de la fusion: tout d'abord il n'est pas linéaire, on observe deux branche parrall-le qui se sépare du commit initial puis qui se rejoignent a travers ne commit de fusion dédié(merge branch test) 
- le graphe par **rebase** : il a une structure lineaire et les commits de la branche test sont au dessus de ceus de la branche main, les modifications apparaissent les unes sur les autres sur un seul fil et il n'y a pas de commit de merge intermédiaire

### MON CHOIX
mon choix se porte sur le graphe donné par **rebase** car celui-ci est plus facile a lire et permet de se répérer faiclement lorques l'on consultera le fichier une seconde fois et je gagnerai en temps 


