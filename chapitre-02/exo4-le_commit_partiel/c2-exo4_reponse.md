# EXERCICE 2
dans cet exercice il est question d'apporter deux modifications dans un meme fichier et de faire des commit séparés , une fois les modifications faites, lorsque je tape la commande 
```cpp
git add -p test.cpp
```
le résultat de cette commande suite à la première modificzation est :
```cpp
PS C:\Users\NOELA\Desktop\CHAPITRE-02> git add -p test.cpp
diff --git a/test.cpp b/test.cpp
index e72f185..ad2df5f 100644
+++ b/test.cpp
@@ -2,7 +2,7 @@
 
 int main(){
   int i,nbm;
-  float moy, som ;
+  float moy, som, nom=1 ;
   float T[10] ;
   
     for (i=0 ; i<10 ; i++)
(1/2) Stage this hunk [y,n,q,a,d,k,K,j,J,g,/,e,p,P,?]? y
```cpp
je tape sur Y pour valider la première modification puis sur n pour empéché la deuxiéme modification d'etre dans le meme commit
```cpp
@@ -18,6 +18,7 @@ int main(){
       {nbm=0;
          std::cout<<nbm<<"eleves ont plus de cette moyenne "<<std::endl;
       }
+      std::cout<<"le nom est :"<< nom;
  return 0;
 
 }
\ No newline at end of file
(2/2) Stage this hunk [y,n,q,a,d,K,J,g,/,e,p,P,?]? n
```
une fois cette étape effectuée je peux faire le premier commit qui est le suivant :
```cpp
git commit -m "enregistrer la première modification
>> 
>> une fois le commit envoyé les deux modification seront dans des commits différents"
[main 9efb62a] enregistrer la première modification
 1 file changed, 1 insertion(+), 1 deletion(-)
```
ensuite je retape la commande 
```
git add -p m.cpp
```
le résultat de la commande est :
```cpp
diff --git a/test.cpp b/test.cpp
index f3fec08..ad2df5f 100644                                                
--- a/test.cpp                                                                        
+++ b/test.cpp
@@ -18,6 +18,7 @@ int main(){
       {nbm=0;
          std::cout<<nbm<<"eleves ont plus de cette moyenne "<<std::endl;
       }
+      std::cout<<"le nom est :"<< nom;
  return 0;
 
 }
\ No newline at end of file
(1/1) Stage this hunk [y,n,q,a,d,e,p,P,?]? y

```
puis je tape le commit correspondant
```cpp
git commit -m "enregistrer la deuxième  modification
>> 
>> La deuxième modification est enregistrée séparement de la première comme dans l'énnoncé
>> une fois le commit envoyé les deux modification seront dans des commits différents"
[main d228a21] enregistrer la deuxième  modification
 1 file changed, 1 insertion(+)
```
une fois ces deux modification enregistrées je peux maintenant éffectuée la vérification avec la commande
```cpp
git log -p -2
```
Le résultat de cette commande est : 
```cpp
commit d228a2164179963d0154972f70ec78e377d8c8a2 (HEAD -> main)
Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Thu Sep 17 09:57:10 2026 +0200

    enregistrer la deuxième  modification
    
    La deuxième modification est enregistrée séparement de la première comme dans l'énnoncé
    une fois le commit envoyé les deux modification seront dans des commits différents

diff --git a/test.cpp b/test.cpp
index f3fec08..ad2df5f 100644
--- a/test.cpp
+++ b/test.cpp
@@ -18,6 +18,7 @@ int main(){
       {nbm=0;
          std::cout<<nbm<<"eleves ont plus de cette moyenne "<<std::endl;
       }
+      std::cout<<"le nom est :"<< nom;^M
  return 0;
 
 }
\ No newline at end of file

commit 9efb62a7a7eb32477edbad4eb28179ca478aa1aa
Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Thu Sep 17 09:53:09 2026 +0200

    enregistrer la première modification
    
    Il s'agit de la première modification qui doit etre séparée de la deuxième
    une fois le commit envoyé les deux modification seront dans des commits différents

diff --git a/test.cpp b/test.cpp
index e72f185..f3fec08 100644
--- a/test.cpp
+++ b/test.cpp
@@ -2,7 +2,7 @@
 
 int main(){
   int i,nbm;
-  float moy, som ;
+  float moy, som, nom=1 ;^M
   float T[10] ;
   
     for (i=0 ; i<10 ; i++)
```
## Nous remarquons bien la présence de deux commits différents. Un commit pour chaque modification