# EXERCICE 11
Pour cet exercice j'ai ajouter un pdf de 10 mo , ensuite je tape les commande **git add* et **git commit**

Le resultat est le suivant :
```
git commit -m "ajouter du fichier pdf d
[main ea95013] ajouter du fichier pdf de 10megaoctets
 create mode 100644 precis de chimie.pdf
```
Je supprime ensuite le commande ave cla commande suivante et son résultat est le suivant :
```
git rm "precis de chimie.pdf"
rm 'precis de chimie.pdf'
```
Une fois de plus je tape les commande **git add** , **git commit** le resultat est le suivant :
```
git add .DF"
[main c9a1a86] Suppression du fichier PDF
 1 file changed, 0 insertions(+), 0 deletions(-)
 delete mode 100644 precis de chimie.pdf
```
Je tape ensuite la commande pour voir l'historique :
```
git log --oneline
c9a1a86 (HEAD -> main) Suppression du fichier PDF
ea95013 ajouter du fichier pdf de 10megaoctets
5b8fa12 (origin/main, origin/HEAD) Initial commit
```
Je calcule ensuite le poids du dossier dans le disque : 
```
PS C:\Users\NOELA\Desktop\exo11> (Get-ChildItem -Recurse .git | Measure-Object -Property Length -Sum).Sum / 1MB
10,135666847229
```
je vérifie le tout avec **git status** et le fichier a bien disparu
```
PS C:\Users\NOELA\Desktop\exo11> git status
On branch main
Your branch is ahead of 'origin/main' by 2 commits.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
```
## ANALYSE
Après avoir valider la suppression du fichier **precis de chimie.pdf** avec un second commit, le fichier n'apparait plus dans le repertoire de travail.

Cependant la mesure du dossier .git indique il occupe toujours une taille de **10,135666847229** cela s'explique par le fait que lors du premier commit Git enregistre le contenu du fichier sous forme d'un fichier binaire (blob) dans sa base de donnée interne **.git/objects**

Le second commit enregistre seulement la modification de l'arborescence mais il ne supprime pas l'objet blob dans l'historique. Cela est fait pour que l'utilisateur puisse revenir a l'état ultérieure et restaurer le fichier dans l'état d'origine