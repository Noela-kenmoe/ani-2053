# EXERCICE 7
Dans cet exercice j'ai cloné le mem depot deux fois de suite, puis j'ai effectuer la première modification dans le premier depot 

les commandes et les resultats sont :
```
git add .
>> 
>> cett variable va servir pour la première modification dans le premier dépot
>> une fois le commit envoyé la première modification sera enregistée et nous pourrons passé a la deuxième toujour dans le meme fichier d'un dépot différent"
[main 13edca2] ajouter la variable nombre
 1 file changed, 1 insertion(+)

```
Ensuite je pouse le commit 
```
PS C:\Users\NOELA\Desktop\test> git push origin main
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 4 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 434 bytes | 54.00 KiB/s, done.
Total 3 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/Noela-kenmoe/test.git
   e310a9a..13edca2  main -> main
```
Je vais ensuite dans le second depot je modifie puis je tape les commandes :
```
git add fon.cpp
PS C:\Users\NOELA\Desktop\projet\test> git commit -m "ajouter de la sortie                
>> cette pharse constitu la second modification du meme fichier dans le meme dépot
>> les deux modifications sont maintanant faites"
[main cfc73a4] ajouter de la sortie cette pharse constitu la second modification du meme fichier dans le meme dépot les deux modifications sont maintanant faites
```

Lorsque je tape la commande :
```
git push
```
Lorsque je tape la commande git push, Git refuse la publication (push rejection) son résultat est le suivant
```

To https://github.com/Noela-kenmoe/test.git
 ! [rejected]        main -> main (fetch first)
error: failed to push some refs to 'https://github.com/Noela-kenmoe/test.git'
hint: Updates were rejected because the remote contains work that you do not
hint: have locally. This is usually caused by another repository pushing to
hint: the same ref. If you want to integrate the remote changes, use
hint: 'git pull' before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
```
## RECUPERATION DES MODIFICATIONS DISTINCTES
Pour recuper les modifications je commence par tapé la commande :
```
 git pull origin main --no-rebase

```
son résultat est le suivant : 
```
From https://github.com/Noela-kenmoe/test
 * branch            main       -> FETCH_HEAD
Auto-merging fon.cpp
Merge made by the 'ort' strategy.
 fon.cpp | 1 +
 1 file changed, 1 insertion(+)
```
Pour finir j'affiche le contenu du depot 1 dans le fichier deux avec la commande 
```
cat fon.cpp
```
Le resultat est : 
```
PS C:\Users\NOELA\Desktop\projet\test> cat fon.cpp
#include<iostream>
 int echange(int *a, int *b);

int main(){
   int nombre;
    bool test;
    int y, c ,d;
    //appel des deux nombres
    std::cout<<"entrer deux nombres :";
    std::cin>> c >> d;
    std::cout<<"avant l'appel:"<< c << d;
    //appel de la fonction echange
    y =echange(&c,&d);
     std::cout<<"apres l'appel :"<< c << y ;
     std::cout<<"verification de l'appel";
     std::cout<<"le nombre est :"<<nombre;
     return 0;
     
}
int echange (int *a, int *b)
     { 
      
        int x;
        *a = x;
        *a = *b;
        *b = x;
        return 0;
     }
```

## Modification de deux ligne séparées d'une ligne 
Première modification après avoir tapé les commandes **git add** et **git commit**
```
git swit
Switched to branch 'test'
PS C:\Users\NOELA\Desktop\test> git add fon.cpp         
[test cbbd62c] modification sur la branche test
 1 file changed, 1 insertion(+), 1 deletion(-)
Switched to branch 'main'
Your branch is ahead of 'origin/main' by 3 commits.
  (use "git push" to publish your local commits)
```
## Modification sur la bracnhe main 
je tape la commande 
```
git switch main
```
Puis j'éffectue la modification, j'enregistre et je fais un commit
```
PS C:\Users\NOELA\Desktop\test> git add fon.cpp         
PS C:\Users\NOELA\Desktop\test> git commit -m "modification sur la branche main"
[main 945d570] modification sur la branche main
 1 file changed, 1 insertion(+), 1 deletion(-)
```
Toujours que la branche main j'essaie de faire une fusion
```
PS C:\Users\NOELA\Desktop\test> git merge test 
Auto-merging fon.cpp
CONFLICT (content): Merge conflict in fon.cpp
Automatic merge failed; fix conflicts and then commit the result.
```
 ## Le conflit ce voit dans ce resultat suivant
 Après avoir taper la commande :
 ```
git merge test
 ```
 ```
#include<iostream>
 int echange(int *a, int *b);

int main(){
   int nombre;
    bool test;
    int z=10;
    int y, c ,d;
    //appel des deux nombres
    std::cout<<"entrer les deux premiers nombres :";
    std::cin>> c >> d;
    std::cout<<"avant l'appel:"<< c << d;
    //appel de la fonction echange
    y =echange(&c,&d);
<<<<<<< HEAD
     std::cout<<"apres l'appel :"<< c << y ;
     std::cout<<" la verification de l'appel est :";
=======
     std::cout<<"apres l'appel on a  :"<< c << y ;
     std::cout<<"verification de l'appel";
>>>>>>> test
     return 0;
     
}
int echange (int *a, int *b)
     { 
      
        int x;
        *a = x;
        *a = *b;
        *b = x;
        return 0;
     }
```
### On peut conclure que les outils de gestion de version (Git) ne comparent pas les fichiers ligne par ligne de manière isol"e, mais par **blocs de contexte**. Si des lignes inchangées séparent deux modifications, l'algorithme de fusion automatique (3-way merge) parvient à combiner les deux versions sans ambiguité. En revanche, dès que deux modifications se chevauchent ou touchent des lignes contiguës, l'absence de ligne tampon empêche l'outil de déterminer l'ordre d'intégration souhaité, ce qui déclenche un conflit pour vous laisser trancher