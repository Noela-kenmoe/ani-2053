## EXERCICE 1
Cet exercice consiste a crée un dépot qui se nomme **CHAPITRE-02** et d'y ajouter trois fichiers dans notre cas il s'agit des fichiers (m.cpp, g.cpp, test.cpp )
Les commandes tapées pour ajouter chaque fichier sont 
```cpp
git add m.cpp
git add g.cpp
git add test.cpp
```

# le résultat de l'affichage de l'historique en une ligne est :

après avoir tapé la commande **git log --oneline**
```cpp
46f5d63 (HEAD -> main, origin/main, origin/HEAD)
Ajouter du troisieme fichier qui est test.cpp 0d69dac 
Ajouter du second fichier qui est g.cpp b3c6f60 
Ajouter du premier fichier qui est m.cpp
5cf527e Initial commit
```
## LE GRAPHE CORRESPONDANT 
le grape est obtenu après avoir tapé la commande
```cpp
git log --online --graph
```
le résultat obtenu est
```cpp 
* 46f5d63 (HEAD -> main, origin/main, origin/HEAD) Ajouter du troisieme fichier qui est test.cpp
* 0d69dac Ajouter du second fichier qui est g.cpp
* b3c6f60 Ajouter du premier fichier qui est m.cpp
* 5cf527e Initial commit
```