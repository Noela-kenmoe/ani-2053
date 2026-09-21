# EXERCICE 11
Je commence tout d'abord a vérifier le fichier a vide 
```

 (Get-ChildItem .git -Recurse | Measure-Object -Property Length -Sum).Sum / 1MB
0,0300893783569336
```
Pour cet exercice j'ai ajouter un pdf de 10 mo , ensuite je tape les commande **git add* et **git commit**
```
git add "precis de chimie.pdf" 
PS C:\Users\NOELA\Desktop\test1> git commit -m "ajout du fichier de 10 Mo"
[main 4ebb769] ajout du fichier de 10 Mo
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 precis de chimie.pdf
PS C:\Users\NOELA\Desktop\test1> (Get-ChildItem .git -Recurse | Measure-Object -Property Length -Sum).Sum / 1MB
10,1352186203003
```
Je calcule une nouvelle fois la taille du dossier aprrès l'ajout :
```
PS C:\Users\NOELA\Desktop\test1> (Get-ChildItem .git -Recurse | Measure-Object -Property Length -Sum).Sum / 1MB
10,1352186203003
```

Je supprime ensuite le fichier avec la commande suivante et son résultat est le suivant :
```
git rm "precis de chimie.pdf"
rm 'precis de chimie.pdf'
```
Une fois de plus je tape les commande **git add** , **git commit** le resultat est le suivant :
```
git commit -m "Suppression du fichier PDF"
[main 2361f3d] Suppression du fichier PDF
 1 file changed, 0 insertions(+), 0 deletions(-)
 delete mode 100644 precis de chimie.pdf
```
Je tape ensuite la commande pour voir l'historique :
```
git log --oneline
git log --oneline
2361f3d (HEAD -> main) Suppression du fichier PDF
4ebb769 ajout du fichier de 10 Mo
1d13f37 (origin/main, origin/HEAD) Initial commit
```
Je calcule ensuite le poids du dossier dans le disque : 
```
(Get-ChildItem .git -Recurse | Measure-Object -Property Length -Sum).Sum / 1MB
10,1356315612793
```
je vérifie le tout avec **git status** et le fichier a bien disparu
```
git status
On branch main
Your branch is ahead of 'origin/main' by 2 commits.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
```
## ANALYSE

**Taille Conservée = Taille après supression - Taille initiale**
```
AN: 10.13 MB-0.03 MB = 10.1 MB
```
Après avoir valider la suppression du fichier **precis de chimie.pdf** avec un second commit, le fichier n'apparait plus dans le repertoire de travail.

Cependant la mesure du dossier .git indique il occupe toujours une taille de **10,1352186203003** cela s'explique par le fait que lors du premier commit Git enregistre le contenu du fichier sous forme d'un fichier binaire (blob) dans sa base de donnée interne **.git/objects**

Le second commit enregistre seulement la modification de l'arborescence mais il ne supprime pas l'objet blob dans l'historique. Cela est fait pour que l'utilisateur puisse revenir a l'état ultérieure et restaurer le fichier dans l'état d'origine

- Lorsque un collaborateur va cloner le dépot, il recevra tout le contenu de .git contenu dans l'historique de la dernière version visible des fichiers (le working directory). Comme le fichier de 10 Mo a fait un commit dans le passé, il fait partie intégrante de l'historique meme s'il est éfface par la suite il sera donc téléchargé lui aussi par le collaborateur
- Combien de fois faudra t'il retélécharger ces dix mégaoctets dans la vie du projet : a chaque fois qu'une personne clonera le dépot, et à chaque fois qu'un environnement de CI/CD ou un nouveau serveur téléchargera le projet, dans une équipe de 4 personnes, si on travaille sur 02 Pc par exemple ou que l'on réinitiale le depot, les 10 Mo du fichier seront téléchargés des dizaines de fois
- A quel moment aurait-il fallu agir pour que cela n'arrive pas, quel est le fichier qui sert eaxctement à cela :

Il fallait agir avant le **git add/git commit** du fichier. le fichier qui sert exactement à éviter ce problème est le **.gitignore** dès la création du projet car Git ignore complètement le fichier et refuse de le suivre (track), le fichier reste sur notre ordinateur local mais n'est jamais envoyé sur le dépot, évitant ainsi d'imprimer définitivement ces 10 Mo dans l'historique de Git.

## Y a t-il un moyen de les retier véritablement :
Pour effacer définitivement un fichier lourd de tout l'historique Git, il ne suffit pas de le supprimer avec **git rm**. Il faut réecrire l'historique avec un outil dédié comme **git filter-repo (ou bfg repo-cleaner)** puis exécuter la purge du garbage collector (git gc --prune=now)

## Qu'est-ce que cela coute aux personnes qui ont déja cloné le dépot
1- Modification de empreintes (SHA-1): en réecrivant l'historique, les identifiants de tou les commits suivants changent
2. Incompatibilité des dépots locaux : l'historique distant et l'historique local des collaborateurs ne correspondent plus
3. Risque de réintroduction du fichier : si un collaborateur fait un **git pull** , il risque d'annuler ou repousse ses branches locales non réintialisées (git pull), il risque déannuler le netoyage et de réintroduire à nouveau le fichier lourd dans le dépot (c'est pour cela qu'il faut contraindre toute l'équipe a réinitialiser leur copie locale avec **git fetch et git reset --hard origin/main**)