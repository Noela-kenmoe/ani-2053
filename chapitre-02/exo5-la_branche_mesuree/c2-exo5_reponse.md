# EXERCICE 5
## Mesurer le poids initial du dossier avant de créer une nouvelle branche
```cpp
(Get-ChildItem .git -Recurse | Measure-Object -Property Length -Sum).Sum / 1KB
```
le resultat obtenu est 
```cpp
39,1376953125
```
### Création de la nouvelle branche
le nouvelle branche est crée et basculer grace à la commande
```cpp
git switch -c branche   
```
Le résultat donne 
```cpp
Switched to a new branch 'branche'
```
Ensuite on teste pour voir si on est désormais sur la nouvelle branche avec la commande 
```cpp
git branch
```
Le résultat de cette commande est : 
```cpp
* branche
  main
```
ensuite on éffectue la première modification et le premier commit 
```cpp
 git commit -m "Ajout de la première modification
>> 
>> cette première modification servira pour le premier commit de l'exercice
>> ce premier commit sera sur la branche branche"
[branche 45e9640] Ajout de la première modification
 1 file changed, 1 insertion(+)
```
Puis la deuxième modification
```cpp
git commit -m "Ajout de la deuxième modification
>> 
>> cette deuxième modification va rejoindre la première sur la branche main
>> le premier commit et le second seront sur la branche branche"
```
Et la troisième modification 
```cpp
 git commit -m "Ajout de la troisième  modification
>>                                                                         
>> Il s'agit de la dernière modification comme démandé dans l'esxercie 5   
>> les trois commits sont désormais la branche branche"                
[branche 94b87a6] Ajout de la troisième  modification
 1 file changed, 2 insertions(+), 1 deletion(-)
```
#### LE POIDS DU DOSSIER
Pour obtenir le j'ai utilisé la commande 
```cpp
(Get-ChildItem .git -Recurse | Measure-Object -Property Length -Sum).Sum / 1KB

```
le résultat de la commande est :
```cpp
42,7294921875
```
##### EXPLICATION
Lorsqu'on éffectue les trois modifications et qu'on fait trois commits, Git crée trois types objets compréses (blobs,trees,commits) dans un dossier caché nommée **.git/objets**, Comme Git fonctionne en ajout uniquement et ne supprime jamais les anciennes versions des fichiers, la taille du dossier .git augmente sur le disque après les trois commits.