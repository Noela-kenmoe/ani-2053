# EXERCICE 8
## premiere modification
Après la modification du fichier, je tape la commande **git status** et le resultat est le suivant 
```cpp
On branch branche
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   test.cpp

no changes added to commit (use "git add" and/or "git commit -a")
```
puis je tape la commande pour annuler la modification 
```cpp
git restore test.cpp
```
## UN add DE TROP
J'ai ajouté un fichier.cpp nommé **test2.cpp** puis j'ai tapé la commande :
```cpp
git add test2.cpp
```
ensuite pour défaire j'ai tapé la commande :
```cpp
git restore --staged test2.cpp
```
Pour vérifier j'ai tapé la commande et son résultat : 
```cpp
 git status
On branch branche
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        test2.cpp

nothing added to commit but untracked files present (use "git add" to track)
```
## UN commmit DE TROP
après avoir ajouter une nouvelle ligne, j'éffectue la commande **git add test.cpp**, **git commit -m** et pour le défaire dans le terminal je tape la commande 
```text
git reset HEAD~1
```
Ensuite je vérifie avec **git status** et le résultat est le suivant :
```cpp
On branch branche
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        test2.cpp

nothing added to commit but untracked files present (use "git add" to track)
```
## UNcommit DEJA POUSSE
J'apporte premièrement une modification au fichier.cpp ensuite je tape les commandes **git add**, 
```text
git commit -m "ajout d'une modification pour l'exercice 8
>>                                                                                              
>> cette modification permetttra de résoudre la partie sur comment défaire un commit deja poussé
>> Ce commit sera poussé pour obtenir le resultat démandé dans l'exercice"
```
et la commande **git push origin branche** car je suis encore sur la branche **branche que j'ai crée plus haut.

Ensuite pour défaire dans le terminal je tape la commande et son résultat :
```text
 git revert HEAD --no-edit                                
[branche 219a877] Revert "ajout d'une modification pour l'exercice 8"
 Date: Thu Sep 17 23:36:05 2026 +0200                                                           
 1 file changed, 7 deletions(-)        
```
Repousse encore
```text
git push origin branche  

Enumerating objects: 3, done.
Counting objects: 100% (3/3), done.
Delta compression using up to 4 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (2/2), 273 bytes | 39.00 KiB/s, done.
Total 2 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/Noela-kenmoe/CHAPITRE-02.git
   1e575c5..219a877  branche -> branche
```       
Et je verifie avec :
```text
 git status                                               
On branch branche
nothing to commit, working tree clean
```
## UN TRAVAIL EN COURS QU'IL FAUT METTRE DE COTE
Je commence un op"ration d'affectation sans la terminée ** test1 = test1 +** ensuite j'enregistre puis je tape la commande 
```text
git stach -u / git stach
``` 
le resultat donne 
```text
Saved working directory and index state WIP on branche: 219a877 Revert "ajout d'une modification pour l'exercice 8"

```
Puis je tape
```text
git status  
On branch branche
nothing to commit, working tree clean
```
Et pour d"faire dans le terminal je tape
```text
 git stash pop
Already up to date.
On branch branche
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        test2.cpp

nothing added to commit but untracked files present (use "git add" to track)
Dropped refs/stash@{0} (30abcef623d01d3eac64512d5a8db567439061ae)
```
## UN COMMIT PERDU A RETROUVE PAR LE REFLOG
J'ajoute quelque ligne de code, j'enregistre puis je tape
```text
git add test2.cpp                   
P git commit -m "resoudre l'exercice 8
>>                              
>> modification du fichier pour pouvoir l'effacer et le retrouver ensuite"
On branch branche
nothing to commit, working tree clean
```
Puis j'annule le commit avec la commande :
```text
 git reset --hard HEAD~1
HEAD is now at 219a877 Revert "ajout d'une modification pour l'exercice 8"
```
Ensuite je vérifie dans l'historique que le commit n'est plus présent
```text
 git log
commit 219a8774c1d823e4dd2a0cc0205c93bc3ed8ce8c (HEAD -> branche, origin/branche)
Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Thu Sep 17 23:36:05 2026 +0200

    Revert "ajout d'une modification pour l'exercice 8"
    
    This reverts commit 1e575c551943ad128e3af415a830119e05793bcf.

commit 1e575c551943ad128e3af415a830119e05793bcf
Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Thu Sep 17 23:35:04 2026 +0200

    ajout d'une modification pour l'exercice 8
    
    cette modification permetttra de résoudre la partie sur comment défaire un commit deja poussé
    Ce commit sera poussé pour obtenir le resultat démandé dans l'exercice

commit 6110d3a12e98f57acaf129f155da290795141670
Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Thu Sep 17 23:33:12 2026 +0200

    Revert "ajout d'une modification pour l'exercice 8"
    
    This reverts commit fddd3bdd5b944e4f4b00eab89cd8ffa9f733cfc7.

commit fddd3bdd5b944e4f4b00eab89cd8ffa9f733cfc7
Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Thu Sep 17 23:32:46 2026 +0200

    ajout d'une modification pour l'exercice 8
    
    cette modification permetttra de résoudre la partie sur comment défaire un commit deja poussé
    Ce commit sera poussé pour obtenir le resultat démandé dans l'exercice

commit 6ef46466f933122bbb40b57418df01c0ad250d54
Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Thu Sep 17 23:27:56 2026 +0200

    Revert " modifier la ligne du meme dépot"
    
    This reverts commit cbaa576ed9409d59fc8f4232cbddaee97c440869.

commit cbaa576ed9409d59fc8f4232cbddaee97c440869
Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Thu Sep 17 18:41:30 2026 +0200

     modifier la ligne du meme dépot
    
    première modification de la ligne d'un meme fichier dans deux dépot différents
    Cette meme ligne sera modifiée dans le second dépot

commit 94b87a6ee59401ba0802c5f073f8d67615ac05e7
Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Thu Sep 17 12:39:48 2026 +0200

    Ajout de la troisième  modification
    
    Il s'agit de la dernière modification comme démandé dans l'esxercie 5
    les trois commits sont désormais la branche branche

commit c026125a393921caef40780fd5b4b0628ad49efd
Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Thu Sep 17 12:37:42 2026 +0200

    Ajout de la deuxième modification
    
    cette deuxième modification va rejoindre la première sur la branche main
    le premier commit et le second seront sur la branche branche

commit 45e9640e74adad75bb73cc91588cadd6ebd76539
Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Thu Sep 17 12:25:13 2026 +0200

    Ajout de la première modification
    
    cette première modification servira pour le premier commit de l'exercice
    ce premier commit sera sur la branche branche

commit d228a2164179963d0154972f70ec78e377d8c8a2 (origin/main, origin/HEAD, main)
Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Thu Sep 17 09:57:10 2026 +0200

    enregistrer la deuxième  modification
    
    La deuxième modification est enregistrée séparement de la première comme dans l'énnoncé
    une fois le commit envoyé les deux modification seront dans des commits différents

commit 9efb62a7a7eb32477edbad4eb28179ca478aa1aa
Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Thu Sep 17 09:53:09 2026 +0200

    enregistrer la première modification
    
    Il s'agit de la première modification qui doit etre séparée de la deuxième
    une fois le commit envoyé les deux modification seront dans des commits différents

commit 9bbe7c5dadd1d9f03da4f37388e4a543d9857341
Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Wed Sep 16 19:28:46 2026 +0200

    modification du fichier m.cpp
    
    cette modification est l'ajout de la variable mn afin de résoudre l'exercice 1
    Le resultat de cette modification est visible après avoir tapé la commande git status

commit 87c6afd38ba717c7ab10a5e1966fc2e97cfc07d0
Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Wed Sep 16 19:26:36 2026 +0200

    modification du fichier m.cpp
    
    cette modification est l'ajout de la variable test afin de résoudre l'exercice 1
    Le resultat de cette modification est visible après avoir tapé la commande git status

commit 46f5d63ab6373309168d36d6f9abbd48b7182a9c
Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Wed Sep 16 17:58:03 2026 +0200

    Ajouter du troisieme fichier qui est test.cpp
    
    le fichier test.cpp a été créer, il est maintenant question de l'ajouter au dépot afin qu'il soit visible sur
 github
    Le dépot contiendra maintenant les fichiers m.cpp, g.cpp, test.cpp

commit 0d69dac8428304722519ee726f95f4fffd7bc436
Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Wed Sep 16 17:55:31 2026 +0200

    Ajouter du second fichier qui est g.cpp
    
    le fichier g.cpp a été créer, il est maintenant question de l'ajouter au dépot afin qu'il soit visible sur gi
thub
    Le dépot contiendra maintenant le fichier m.cpp et le fichier g.cpp

commit b3c6f60397d2e5b386d7807042920edb122357a1
Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Wed Sep 16 17:54:27 2026 +0200

    Ajouter du premier fichier qui est m.cpp
    
    le fichier m.cpp a été créer, il est maintenant question de l'ajouter au dépot afin qu'il soit visible sur gi
thub
    Le dépot contiendra maintenant le fichier m.cpp

commit 5cf527ee2786972b572ad27811f1a065c7a0e10b
Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Wed Sep 16 17:47:02 2026 +0200

    Initial commit
```
Puis je tape la commande reflog pour afficher le commit perdu
```text

219a877 (HEAD -> branche, origin/branche) HEAD@{0}: reset: moving to HEAD~1
d051e5d HEAD@{1}: commit: resoudre l'exercice 8
219a877 (HEAD -> branche, origin/branche) HEAD@{2}: reset: moving to HEAD
219a877 (HEAD -> branche, origin/branche) HEAD@{3}: reset: moving to HEAD
219a877 (HEAD -> branche, origin/branche) HEAD@{4}: revert: Revert "ajout d'une modification pour l'exercice 8"
1e575c5 HEAD@{5}: commit: ajout d'une modification pour l'exercice 8
6110d3a HEAD@{6}: revert: Revert "ajout d'une modification pour l'exercice 8"
fddd3bd HEAD@{7}: commit: ajout d'une modification pour l'exercice 8
6ef4646 HEAD@{8}: revert: Revert " modifier la ligne du meme dépot"
cbaa576 HEAD@{9}: reset: moving to HEAD~1
2282532 HEAD@{10}: commit: commit pour le test de l'exercice 8
cbaa576 HEAD@{11}: commit: modifier la ligne du meme dépot
94b87a6 HEAD@{12}: commit: Ajout de la troisième modification
c026125 HEAD@{13}: commit: Ajout de la deuxième modification
45e9640 HEAD@{14}: commit: Ajout de la première modification
d228a21 (origin/main, origin/HEAD, main) HEAD@{15}: checkout: moving from main to branche
d228a21 (origin/main, origin/HEAD, main) HEAD@{16}: commit: enregistrer la deuxième modification
9efb62a HEAD@{17}: commit: enregistrer la première modification
```cpp
Git confirme le retour du commit avec la commande et son résultat:
```text
 git reset --hard d051e5d
HEAD is now at d051e5d resoudre l'exercice 8
```
