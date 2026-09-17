# EXERCICE 6
La première modification du premier clone aorès avoir tapé les commandes **git add**,  **git commit -m**,  **git push**
Le resultat de ces commandes est : 
```cpp
Enumerating objects: 4, done.                          
Counting objects: 100% (4/4), done.
Delta compression using up to 4 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 609 bytes | 101.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To https://github.com/Noela-kenmoe/clone.git
   a777703..ca8e815  main -> main
```
Le resultat de la deuxième modification est 
```cpp
git: 'credential-wincred' is not a git command. See 'git --help'.
git: 'credential-wincred' is not a git command. See 'git --help'.
To https://github.com/Noela-kenmoe/clone.git                            
 ! [rejected]        main -> main (fetch first)
error: failed to push some refs to 'https://github.com/Noela-kenmoe/clone.git'
hint: Updates were rejected because the remote contains work that you do not
hint: have locally. This is usually caused by another repository pushing to
hint: the same ref. If you want to integrate the remote changes, use
hint: 'git pull' before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
```
Pour provoquer le conflit je tape la commande 
```cpp
git pull --no-rebase origin main
```
Le resultat de la commande est 
```cpp
From https://github.com/Noela-kenmoe/clone
 * branch            main       -> FETCH_HEAD
Auto-merging fon.cpp
CONFLICT (add/add): Merge conflict in fon.cpp
Automatic merge failed; fix conflicts and then commit the result.
```
après cette commande je supprime les lignes marqués 
```cpp
int echange(int *a, int *b);



int main(){

   

    int y, c ,d;

<<<<<<< HEAD

    std::cout<<"entrer deux premiers nombres :";

=======

    std::cout<<"entrer deux nombres enregistrés :";

>>>>>>> ca8e81589ccd4e0fbd1957fee107bd28411d27e1

    std::cin>> c >> d;

    std::cout<<"avant l'appel:"<< c << d;

    y =echange(&c,&d);

     std::cout<<"apres l'appel :"<< c << y ;

     return 0;

     

}

int echange (int *a, int *b) je supprime quelle ligne 

```
## LES ETAPES POUR RESOUDRE LE PROBLEME SONT
1. je modifie les lignes en choisissant la version que je souhaite gardé
```cpp
int echange(int *a, int *b);

int main(){
    
    int y, c ,d;

    std::cout<<"entrer deux premiers nombres :";

    std::cin>> c >> d;
    std::cout<<"avant l'appel:"<< c << d;
    y =echange(&c,&d);
     std::cout<<"apres l'appel :"<< c << y ;
     return 0;
     
}
int echange (int *a, int *b)
```
2. je tape ensuite les commandes **git add fon.cpp** et **git commit -m** 
```cpp
 git commit -m "Resolution du conflit dans fon.cpp"
[main c9e50d4] Resolution du conflit dans fon.cpp

```
3. je tape la commande 
```cpp
                              
git: 'credential-wincred' is not a git command. See 'git --help'.
git: 'credential-wincred' is not a git command. See 'git --help'.
Enumerating objects: 9, done.
Counting objects: 100% (9/9), done.
Delta compression using up to 4 threads
Compressing objects: 100% (6/6), done.
Writing objects: 100% (6/6), 764 bytes | 63.00 KiB/s, done.
Total 6 (delta 4), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (4/4), completed with 2 local objects.
To https://github.com/Noela-kenmoe/clone.git
   ca8e815..c9e50d4  main -> main
```
# LE CONFLIT EST ENFIN RESOLUTION !!!!