## le nombre de fichier général est 4335 fichiers
## Le nombre par type sont :
|type|effectifs|
|----|---------|
|**.cpp**| 1609|
|**.h**|2728   |
|**test**|107  |

## Le nombre de ligne est : 2123987 lignes
## les resultats obtenue sont différents de ceux présent dans le chapitre 

## La commande utilisé pour ontenir le nombre de fichier est 
```
(Get-ChildItem -Recurse -File -Include *.cpp, *.h).Count 
```
## la commande utilisée pour avoir le nombre de fichier .cpp est 
```
(Get-ChildItem -Recurse -File -Filter "test_*.cpp").Count 
```
## La commande utilisée pour avoir le nombre de fichier .h est :
```
(Get-ChildItem -Recurse -File -Include *.cpp, *.h).Count 
```
## La commande utilisée pour avoir le nombre de ligne de code est :
```
(Get-ChildItem -Recurse -File -Filter -Include *.cpp,*.h | Get-Content).Count
```
