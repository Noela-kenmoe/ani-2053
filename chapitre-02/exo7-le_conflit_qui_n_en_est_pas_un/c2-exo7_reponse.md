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
Première modification 
```
 git add .                                      
PS C:\Users\NOELA\Desktop\test> git commit -m "première modification"          
[main 2437ca3] première modification
 1 file changed, 1 insertion(+)
PS C:\Users\NOELA\Desktop\test> git push origin main
git: 'credential-manager' is not a git command. See 'git --help'.
git: 'credential-manager' is not a git command. See 'git --help'.
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 4 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 299 bytes | 49.00 KiB/s, done.
Total 3 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/Noela-kenmoe/test.git
   a74a368..2437ca3  main -> main
```
- Deuxième modification
```
git add fon.cpp                              
PS C:\Users\NOELA\Desktop\projet\test> git commit -m " deuxième modification"       
[main f3b50cb]  deuxième modification
 1 file changed, 1 insertion(+)
PS C:\Users\NOELA\Desktop\projet\test> git push                                     
git: 'credential-manager' is not a git command. See 'git --help'.
To https://github.com/Noela-kenmoe/test.git
 ! [rejected]        main -> main (fetch first)
error: failed to push some refs to 'https://github.com/Noela-kenmoe/test.git'
hint: Updates were rejected because the remote contains work that you do not
hint: have locally. This is usually caused by another repository pushing to
hint: the same ref. If you want to integrate the remote changes, use
hint: 'git pull' before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
PS C:\Users\NOELA\Desktop\projet\test> git pull origin main --no-rebase
remote: Enumerating objects: 5, done.
remote: Counting objects: 100% (5/5), done.
remote: Compressing objects: 100% (1/1), done.
remote: Total 3 (delta 2), reused 3 (delta 2), pack-reused 0 (from 0)
Unpacking objects: 100% (3/3), 279 bytes | 9.00 KiB/s, done.
From https://github.com/Noela-kenmoe/test
 * branch            main       -> FETCH_HEAD
   a74a368..2437ca3  main       -> origin/main
Auto-merging fon.cpp
Merge made by the 'ort' strategy.
 fon.cpp | 1 +
 1 file changed, 1 insertion(+)
```
### La commande git pull a éffectué une fusion automatique (auto-merging ) sans ausun conflit car les modifications portaient sur des lignes différentes. Le fichiers contient maintenat les deux rajouts, lorque deux utilisateurs ne  modifient pas la meme ligne exacte, le conflit de fusion est déclarée des que les modifications se situent dans la meme zone de texte au dela de cette distance la fusion déeffectue automatiquement
