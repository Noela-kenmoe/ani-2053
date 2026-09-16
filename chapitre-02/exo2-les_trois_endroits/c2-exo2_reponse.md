# EXERCICE 2
## Modification du fichier : **m.cpp**
après modification du fichier et apprès avoir tapé la commande
```cpp
git status
```
```cpp
On branch main
Your branch is up to date with 'origin/main'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   m.cpp

no changes added to commit (use "git add" and/or "git commit -a")
```
Après avoir tapé la commande 
```cpp
git add m.cpp
```
le résultat de la commande **git status** est :
```cpp
On branch main
Your branch is up to date with 'origin/main'.

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   m.cpp
```
après avoir tapé la commande :
```cpp
git commit -m "
```
```cpp
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
```cpp
git commit -m "modification du fichier m.cpp
>> 
>> cette modification est l'ajout de la variable mn afin de résoudre l'exercice 1  
>> Le resultat de cette modification est visible après avoir tapé la commande git status"
```