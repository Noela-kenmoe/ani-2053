# DEMO 3
Dans cette démonstration, je vais modifier un fichier puis detruire la modification
je commence par ajouter la modification puis je l'enregistre dans un commit
```
git add .
PS C:\Users\NOELA\Desktop\clone> git commit -m "modification du fichier nb.cpp"
[test 12d2525] modification du fichier nb.cpp
 2 files changed, 3 insertions(+), 6 deletions(-)
```
Je détruis ensuite le travail 
```
git reset --hard HEAD~1
HEAD is now at 300dd77 Commit C: Fusion de test dans main
```
je verifie et le travail a bien été supprimer
```
PS C:\Users\NOELA\Desktop\clone> cat nb.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
int main() { 
   
   srand(time(NULL));

   int nombresecret = rand()% 100 + 1;
   std::cout<<"un nombre aleatoire :"<<nombresecret;
   return 0;
   }
```
Je vérifie aussi que le commit a bien été supprimer dans l'historique
````

git log --oneline
300dd77 (HEAD -> test, test1) Commit C: Fusion de test dans main
6466e04 Ajouter le fichier nb.cpp ce fichier va servir pour faire l'intégration pour résoudre l'xercice 10 une fois le fichier ajouter il sera fusionné dans la branche main
c9e50d4 (origin/main, origin/HEAD) Resolution du conflit dans fon.cpp
64e3f0d  modifier la ligne du meme dépot
ca8e815  modifier la ligne du meme dépot
a777703 Initial commit
````
Je tape ensuite la commande reflog et j'obtiend :
```
git reflog
300dd77 (HEAD -> test, test1) HEAD@{0}: reset: moving to HEAD~1
12d2525 HEAD@{1}: commit: modification du fichier nb.cpp
300dd77 (HEAD -> test, test1) HEAD@{2}: checkout: moving from main to test
0e7c7f7 (main) HEAD@{3}: commit: Ajouter le fichier mp.cpp
9f4311f HEAD@{4}: checkout: moving from test to main
300dd77 (HEAD -> test, test1) HEAD@{5}: checkout: moving from main to test
9f4311f HEAD@{6}: commit: Ajouter le fichier nom.cpp
300dd77 (HEAD -> test, test1) HEAD@{7}: checkout: moving from main to main
300dd77 (HEAD -> test, test1) HEAD@{8}: checkout: moving from test1 to main
300dd77 (HEAD -> test, test1) HEAD@{9}: checkout: moving from main to test1
300dd77 (HEAD -> test, test1) HEAD@{10}: checkout: moving from test1 to main
300dd77 (HEAD -> test, test1) HEAD@{11}: checkout: moving from main to test1
300dd77 (HEAD -> test, test1) HEAD@{12}: checkout: moving from test to main
300dd77 (HEAD -> test, test1) HEAD@{13}: rebase (finish): returning to refs/heads/test
300dd77 (HEAD -> test, test1) HEAD@{14}: rebase (start): checkout main
6466e04 HEAD@{15}: checkout: moving from main to test
300dd77 (HEAD -> test, test1) HEAD@{16}: merge test: Merge made by the 'ort' strategy.
c9e50d4 (origin/main, origin/HEAD) HEAD@{17}: reset: moving to c9e50d4
6466e04 HEAD@{18}: merge test: Fast-forward (no commit created; -m option ignored)
c9e50d4 (origin/main, origin/HEAD) HEAD@{19}: checkout: moving from test to main
6466e04 HEAD@{20}: commit: Ajouter le fichier nb.cpp
c9e50d4 (origin/main, origin/HEAD) HEAD@{21}: checkout: moving from main to test
c9e50d4 (origin/main, origin/HEAD) HEAD@{22}: pull: Fast-forward
ca8e815 HEAD@{23}: checkout: moving from main to main
ca8e815 HEAD@{24}: commit: modifier la ligne du meme dépot
a777703 HEAD@{25}: clone: from https://github.com/Noela-kenmoe/clone.git
(END)
```
je repère mon commit supprimé puis je tape la commande : 
```
git reset --hard  12d2525    
HEAD is now at 12d2525 modification du fichier nb.cpp
```
Les modifications ont été restaurées et pour vérifier je tape la commande :
```
PS C:\Users\NOELA\Desktop\clone> cat nb.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
int main() { 
   int nombre;
   srand(time(NULL));

   int nombresecret = rand()% 100 + 1;
   std::cout<<"le nombre est :"<< nombre;
   std::cout<<"un nombre aleatoire :"<<nombresecret;
   return 0;
   }
```