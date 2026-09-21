# DEMONSTRATION 4 
Pour cette démonstration un dépot Github a été créer 
```

```
je commence par prendre les modifications et ajouts pour etre a jour 
```
PS C:\Users\NOELA\Desktop\GestionnaireEtudiants\G
Already up to date.
PS C:\Users\NOELA\Desktop\GestionnaireEtudiants\G
* feat/student-management
  main
PS C:\Users\NOELA\Desktop\GestionnaireEtudiants\G
On branch feat/student-management
Your branch is up to date with 'origin/feat/stude

Untracked files:
  (use "git add <file>..." to include in what wil
        etud.exe
        etudiant.cpp

nothing added to commit but untracked files prese
```
Je vérifie ensuite dans quelle branche je me trouve
```
 C:\Users\NOELA\Desktop\GestionnaireEtudiants\G
* feat/student-management
  main
```
je tape la comande **git status**
```

```
J'ajoute mon fichier et je fais un commit 
```

```

Voici mon commit :
```

Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Tue Sep 22 00:25:07 2026 +0200

    feat(etudiant): ajout de la saisie, du stockage et de la vérification des étudiants
    
    Implémentation de flux complet de gestion d'un étudiant en C++ (saisie,stockage dynamqiue et vérification).
    Détails des fonctionnalités ajoutées :
    - Saisie sécurisée (demanderInformations):
      * Récupération des champs : ID, NOM, prénom et moyenne (0 à 20)
      * Nettoyage du tampon et gestion des erreurs de flux avec std::cin.clear() et std::cin.ignore().
      * Prise en charge des espaces pour les noms et prénoms via std::getline().
    - Stockage dynamique (ajouterEtudiant) :
      * Insertion de la structure Etudiant dans un std::vector transmis par référence.
    - Contrôle d'intégrité (verifierEnregistrement) :
      * Recherche par ID dans le vecteur à l'aide de l'algorithme std::find_if et d'
une fonction lambda.
      * Validation visuelle en affichant l'ensemble des champs enregistrés dans la c
onsole.
    Résout le besoin de saisie et de contrôle des étudiants en garantissant qu'aucun
e saisie invalide ne bloque le programme et que chaque étudiant ajouté est immédiate
ment vérifiable en mémoire
```
L'historique des commits du dépot est :
```
C:\Users\NOELA\Desktop\GestionnaireEtudiants\Gestionnaire_d'Etudiants> 
commit 7f8e86e17d28c1f12bc8040af7ac5c21473d6a16 (HEAD -> main)
Author: Noela-kenmoe <kenmoenoela@gmail.com>
Date:   Tue Sep 22 00:25:07 2026 +0200

    feat(etudiant): ajout de la saisie, du stockage et de la vérification des étudiants
    
    Implémentation de flux complet de gestion d'un étudiant en C++ (saisie,stockage dynamqiue et vérification
    Détails des fonctionnalités ajoutées :
    - Saisie sécurisée (demanderInformations):
      * Récupération des champs : ID, NOM, prénom et moyenne (0 à 20)
      * Nettoyage du tampon et gestion des erreurs de flux avec std::cin.clear() et std::cin.ignore().
      * Prise en charge des espaces pour les noms et prénoms via std::getline().
    - Stockage dynamique (ajouterEtudiant) :
      * Insertion de la structure Etudiant dans un std::vector transmis par référence.
    - Contrôle d'intégrité (verifierEnregistrement) :
      * Recherche par ID dans le vecteur à l'aide de l'algorithme std::find_if et d'
une fonction lambda.
      * Validation visuelle en affichant l'ensemble des champs enregistrés dans la c
onsole.
    Résout le besoin de saisie et de contrôle des étudiants en garantissant qu'aucun
e saisie invalide ne bloque le programme et que chaque étudiant ajouté est immédiate
ment vérifiable en mémoire

commit c9f1c3aaadab14e470394fb407089d1021becc10 (origin/feat/student-search)
Author: lovelinegatsi <lovelinegatsi@gmail.com>
Date:   Mon Sep 21 23:14:12 2026 +0100

    feat(Recherche-etudiant: Etablissons le plan de recherche des etudiant a travers
 reherche .cpp

commit 32e0b79f20a1dfd78f060c88e82260ea15c0ea59 (origin/feat/student-management)
Author: Daiki ny <nyondjeudurel8.com>
Date:   Mon Sep 21 23:04:00 2026 +0100

    Section_Du_main_permettant_d'afficher_la _liste_des_etudiants

commit d2ac43e84fcb8b060256895691f2ae1be3f35ada (origin/main, origin/HEAD, feat/stud
ent-management)
Author: lovelinegatsi <lovelinegatsi@gmail.com>
Date:   Mon Sep 21 21:01:02 2026 +0100

    creation du projet
(END)

commit c9f1c3aaadab14e470394fb407089d1021becc10 (origin/feat/student-search)
Author: lovelinegatsi <lovelinegatsi@gmail.com>
Date:   Mon Sep 21 23:14:12 2026 +0100

    feat(Recherche-etudiant: Etablissons le plan de recherche des etudiant a travers reherche .cpp

commit 32e0b79f20a1dfd78f060c88e82260ea15c0ea59 (origin/feat/student-management)
Author: Daiki ny <nyondjeudurel8.com>
Date:   Mon Sep 21 23:04:00 2026 +0100

    Section_Du_main_permettant_d'afficher_la _liste_des_etudiants

commit d2ac43e84fcb8b060256895691f2ae1be3f35ada (origin/main, origin/HEAD, feat/student-management)
Author: lovelinegatsi <lovelinegatsi@gmail.com>
Date:   Mon Sep 21 21:01:02 2026 +0100

    creation du projet
~
~
(END)

commit c9f1c3aaadab14e470394fb407089d1021becc10 (origin/feat/student-search)
Author: lovelinegatsi <lovelinegatsi@gmail.com>
Date:   Mon Sep 21 23:14:12 2026 +0100

    feat(Recherche-etudiant: Etablissons le plan de recherche des etudiant a travers reherche .cpp

commit 32e0b79f20a1dfd78f060c88e82260ea15c0ea59 (origin/feat/student-management)
Author: Daiki ny <nyondjeudurel8.com>
Date:   Mon Sep 21 23:04:00 2026 +0100

    Section_Du_main_permettant_d'afficher_la _liste_des_etudiants

commit d2ac43e84fcb8b060256895691f2ae1be3f35ada (origin/main, origin/HEAD, feat/student-management)
Author: lovelinegatsi <lovelinegatsi@gmail.com>
Date:   Mon Sep 21 21:01:02 2026 +0100

    creation du projet
(END)

commit c9f1c3aaadab14e470394fb407089d1021becc10 (origin/feat/student-search)
Author: lovelinegatsi <lovelinegatsi@gmail.com>
Date:   Mon Sep 21 23:14:12 2026 +0100

    feat(Recherche-etudiant: Etablissons le plan de recherche des etudiant a travers reherche .cpp

commit 32e0b79f20a1dfd78f060c88e82260ea15c0ea59 (origin/feat/student-management)
Author: Daiki ny <nyondjeudurel8.com>
Date:   Mon Sep 21 23:04:00 2026 +0100

    Section_Du_main_permettant_d'afficher_la _liste_des_etudiants

commit d2ac43e84fcb8b060256895691f2ae1be3f35ada (origin/main, origin/HEAD, feat/student-management)
Author: lovelinegatsi <lovelinegatsi@gmail.com>
Date:   Mon Sep 21 21:01:02 2026 +0100

    creation du projet
~
~
(END)
```
J'analyse désormais le commit d'un collaborateur 
```
commit c9f1c3aaadab14e470394fb407089d1021becc10 (origin/feat/student-search)
Author: lovelinegatsi <lovelinegatsi@gmail.com>
Date:   Mon Sep 21 23:14:12 2026 +0100

    feat(Recherche-etudiant: Etablissons le plan de recherche des etudiant a travers
 reherche .cpp)
```
# ANALYSE :
- Abscence de titre et de corps
- Abcence d'une balise fermente : la chaine feat(Recherche-etudiant...) ne se ferme pas
- Fautes de frappes
- Erreur d'interprétation par Shell: la rupture de ligne après **à travers** suivie d'un indentation sur **recherche .cpp** le Shell a interpr"te la ligne comme deux entrés distantes, générant un saut de ligne parasite dans l'en-tete du commit
- Inclure le nom du fichier (recherche.cpp) dans le titre du commmit est une rédondance inutile. Le fichier apparait déja explicitement dans l'index Git via **git diff** ou **git log --stat**
