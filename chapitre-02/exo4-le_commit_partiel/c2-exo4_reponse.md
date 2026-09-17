# EXERCICE 2
dans cet exercice il est question d'apporter deux modifications dans un meme fichier et de faire des commit séparés , une fois les modifications faites, lorsque je tape la commande 
```cpp
git add -p m.cpp
```
le résultat de cette commande suite à la première modificzation est :
```cpp
 git add -p m.cpp
diff --git a/m.cpp b/m.cpp
index 020449f..4f3c6b9 100644
--- a/m.cpp
+++ b/m.cpp
@@ -4,6 +4,7 @@ int main (){
     int tab[5];
     int i;
     float som , mn ;
+    std::string nom ="Noela";
      for (i=1 ; i<5 ; i++){
         std::cout<<"entrer la note numero" << i << ":";
         std::cin>> tab[i];
(1/2) Stage this hunk [y,n,q,a,d,k,K,j,J,g,/,e,p,P,?]? y

```cpp
je tape sur Y pour valider la première modification puis sur n pour empéché la deuxiéme modification d'etre dans le meme commit
```cpp
@@ -15,5 +16,6 @@ int main (){
      }
      
      std::cout<<"la SOMME de la classe est :"<< som;
+     std::cout<<"le nom de la meilleur élève est :"<< nom;
    return 0 ;
 }
\ No newline at end of file
(2/2) Stage this hunk [y,n,q,a,d,K,J,g,/,e,p,P,?]? n
```
une fois cette étape effectuée je peux faire le premier commit qui est le suivant :
```cpp
git commit -m "Ajout de la variable nom
>> cette variable servira pour enregistrer la première modification et pour afficher le nom du meilleur élève
>> Une fois l'ajout de la variable enregistré, le premier commit peut etre poussé"
[branche 5550a41] Ajout de la variable nom cette variable servira pour enregistrer la première modification et pour afficher le nom du meilleur élève Une fois l'ajout de la variable enregistré, le premier commit peut etre poussé
 1 file changed, 1 insertion(+)
```
ensuite je retape la commande 
```
git add -p m.cpp
```
le résultat de la commande est :
```cpp
diff --git a/m.cpp b/m.cpp
index 1ba83c3..4f3c6b9 100644
--- a/m.cpp
+++ b/m.cpp
@@ -16,5 +16,6 @@ int main (){
      }
      
      std::cout<<"la SOMME de la classe est :"<< som;
+     std::cout<<"le nom de la meilleur élève est :"<< nom;
    return 0 ;
 }
\ No newline at end of file
(1/1) Stage this hunk [y,n,q,a,d,e,p,P,?]? y

```
puis je tape le commit correspondant
```cpp
git commit -m "Ajout de la sortie du nom du meilleur élève
>> cette instruction utilise la variable nom déclarée dans la première modification et dans le commit précédent
>> Nous avons maintenant utilisé la variable crée et enregisté la deuxième modification"
[branche 07dd43b] Ajout de la sortie du nom du meilleur élève cette instruction utilise la variable nom déclarée dans la première modification et dans le commit précédent Nous avons maintenant utilisé la variable crée et enregisté la deuxième modification
 1 file changed, 1 insertion(+)
```
une fois ces deux modification enregistrées je peux maintenant éffectuée la vérification avec la commande
```cpp
git log -p -2
```
Le résultat de cette commande est : 
```text
commit 07dd43b4993443aa29cab525711074493f345900 (HEAD -> branche)
Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Fri Sep 18 00:57:30 2026 +0200

    Ajout de la sortie du nom du meilleur élève
    cette instruction utilise la variable nom déclarée dans la première modification et dans le commit précédent
    Nous avons maintenant utilisé la variable crée et enregisté la deuxième modification

diff --git a/m.cpp b/m.cpp
index 1ba83c3..4f3c6b9 100644
--- a/m.cpp
+++ b/m.cpp
@@ -16,5 +16,6 @@ int main (){
      }
      
      std::cout<<"la SOMME de la classe est :"<< som;
+     std::cout<<"le nom de la meilleur élève est :"<< nom;^M
    return 0 ;
 }
\ No newline at end of file

commit 5550a41e2b50e2c552b46a3753553708ad8aa955
Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Fri Sep 18 00:54:23 2026 +0200

    Ajout de la variable nom
    cette variable servira pour enregistrer la première modification et pour afficher le nom du meilleur élève
    Une fois l'ajout de la variable enregistré, le premier commit peut etre poussé

diff --git a/m.cpp b/m.cpp
index 020449f..1ba83c3 100644
--- a/m.cpp
+++ b/m.cpp
@@ -4,6 +4,7 @@ int main (){
     int tab[5];
     int i;
     float som , mn ;
+    std::string nom ="Noela";^M
      for (i=1 ; i<5 ; i++){
         std::cout<<"entrer la note numero" << i << ":";
         std::cin>> tab[i];
```
## Nous remarquons bien la présence de deux commits différents. Un commit pour chaque modification