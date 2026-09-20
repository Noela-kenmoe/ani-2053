# DEMONSTRATION 2
Dans cette démonstration je vais modifier une meme ligne d'un fichier sur deux branches différentes
1. je commence pas vérifie sur quel branche je me trouve avec la commande :
```
git branch
* main
  test
```
2. L'état initial du fichier est :
```
#include<iostream>
int main ( ){
    int nbr,i;
    std::cout<<"entrer un nombre:\n";
    std::cin>> nbr;
    std::cout<<"LA TABLE DE MULTIPLICATION PAR "<<nbr<<"EST :\n";
    for ( i = 0; i <=10; i++)
    {
        /* code */
        std::cout<<nbr<<"*"<<i<<"="<<i*nbr<<"\n";
    }
    return 0;
}
```
3. J'éffectue la première modification
```
#include<iostream>
int main ( ){
    int nbr,i;
    std::cout<<"veillez entrer un nombre:\n";
    std::cin>> nbr;
    std::cout<<"LA TABLE DE MULTIPLICATION PAR "<<nbr<<"EST :\n";
    for ( i = 0; i <=10; i++)
    {
        /* code */
        std::cout<<nbr<<"*"<<i<<"="<<i*nbr<<"\n";
    }
    return 0;
}
```
4. J'enregistre puis je fais un commit 
```
git add mp.cpp
PS C:\Users\NOELA\Desktop\test> git commit -m "première modification"
[main 934325b] première modification
 1 file changed, 13 insertions(+)
 create mode 100644 mp.cpp
```
5. Je change maintenant de branche 
```
git switch test
Switched to branch 'test'
```
6. Je fais aussi une modification dans cette branche sur la meme ligne que celle de la branche précédente
```
#include<iostream>
int main ( ){
    int nbr,i;
    std::cout<<"entrer un nombre de votre choix:\n";
    std::cin>> nbr;
    std::cout<<"LA TABLE DE MULTIPLICATION PAR "<<nbr<<"EST :\n";
    for ( i = 0; i <=10; i++)
    {
        /* code */
        std::cout<<nbr<<"*"<<i<<"="<<i*nbr<<"\n";
    }
    return 0;
}
```
7. J'enregistre la modification puis je fais un autre commit 
```
git add mp.cpp
PS C:\Users\NOELA\Desktop\test> git commit -m "deuxième modification sur la meme ligne"
[test 4f58e6c] deuxième modification sur la meme ligne
 1 file changed, 1 insertion(+), 1 deletion(-)
```
8. Je bascule de nouveau sur la branche main
```
git switch main
```
9. Je crée le conflit en essayant de faire une fusion avec la commande :
```
git merge test
```
La sortie du terminal est :
```
Auto-merging mp.cpp
CONFLICT (add/add): Merge conflict in mp.cpp
Automatic merge failed; fix conflicts and then commit the result.
```
Le contenu du fichier devient : 
```
#include<iostream>
int main ( ){
    int nbr,i;
<<<<<<< HEAD
    std::cout<<"veillez entrer un nombre:\n";
=======
    std::cout<<"entrer un nombre de votre choix:\n";
>>>>>>> test
    std::cin>> nbr;
    std::cout<<"LA TABLE DE MULTIPLICATION PAR "<<nbr<<"EST :\n";
    for ( i = 0; i <=10; i++)
    {
        /* code */
        std::cout<<nbr<<"*"<<i<<"="<<i*nbr<<"\n";
    }
    return 0;
}
```

10. Je choisie la version que je souhaite gardé 
```
#include<iostream>
int main ( ){
    int nbr,i;
    std::cout<<"entrer un nombre de votre choix:\n";
    std::cin>> nbr;
    std::cout<<"LA TABLE DE MULTIPLICATION PAR "<<nbr<<"EST :\n";
    for ( i = 0; i <=10; i++)
    {
        /* code */
        std::cout<<nbr<<"*"<<i<<"="<<i*nbr<<"\n";
    }
    return 0;
}

```
11. je fais un **git add** puis je vérifie avec un **git status**
```
git status
On branch main
Your branch is up to date with 'origin/main'.

All conflicts fixed but you are still merging.
  (use "git commit" to conclude merge)

Changes to be committed:
        modified:   mp.cpp

```
12. Je fais maintenant un dernier commit de validation
```
PS C:\Users\NOELA\Desktop\test> git commit -m "resolution du conflit"                  
[main fcbd060] resolution du conflit
```
**Le conflit est désormais résolu !!**
