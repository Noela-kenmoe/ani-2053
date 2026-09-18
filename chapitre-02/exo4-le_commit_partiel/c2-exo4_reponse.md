# EXERCICE 4
dans cet exercice il est question d'apporter deux modifications dans un meme fichier et de faire des commit séparés , une fois les modifications faites, lorsque je tape la commande 
```cpp
git add -p m.cpp
```
le résultat de cette commande suite à la première modificzation est :
```
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
```
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
```
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
```
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
# !!! REMARQUE :

Pour avoir deux erreurs différentes, il est nécessaire de faire dex midifications séparées et ne collée, il faut donc laissé quelque lignes intactes entre le deux modification pour que Git est la possibilité de les séparés proprement et correctement
## Nous remarquons bien la présence de deux commits différents. Un commit pour chaque modification
pour cela on tape la commande **git log** son résultat est le suivant :
```text
git log
commit 07dd43b4993443aa29cab525711074493f345900 (HEAD -> branche)
Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Fri Sep 18 00:57:30 2026 +0200

    Ajout de la sortie du nom du meilleur élève
    cette instruction utilise la variable nom déclarée dans la première modification et dans le commit précédent
    Nous avons maintenant utilisé la variable crée et enregisté la deuxième modification

commit 5550a41e2b50e2c552b46a3753553708ad8aa955
Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Fri Sep 18 00:54:23 2026 +0200

    Ajout de la variable nom
    cette variable servira pour enregistrer la première modification et pour afficher le nom du meilleur élève
    Une fois l'ajout de la variable enregistré, le premier commit peut etre poussé

commit d051e5de1c04adb5b3f1d468ff2888215dffa33d
Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Fri Sep 18 00:08:33 2026 +0200

    resoudre l'exercice 8
    
    modification du fichier pour

commit 219a8774c1d823e4dd2a0cc0205c93bc3ed8ce8c (origin/branche)
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