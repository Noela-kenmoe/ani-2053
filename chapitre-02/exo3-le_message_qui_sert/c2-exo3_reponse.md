# ERXERCICE 3
## Premier commit

```cpp

    commit ad0779cb0dfa2ebecb6c58d13327643c1e317f9c
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Fri Aug 28 22:02:54 2026 +0100

    NKCode : runtime MinGW en statique — l'exe ne depend plus du msys64 du testeur
    
    Issue beta #15, seconde moitie. NKCode.exe importait libstdc++-6.dll et
    libgcc_s_seh-1.dll, que le chargeur resolvait PAR LE PATH — donc chez
    l'utilisateur. Un testeur a recu « NKCode.exe - Point d'entree introuvable :
    clock_gettime64 est introuvable dans C:\msys64\ucrt64\bin\libstdc++-6.dll » :
    son msys64, installe en suivant la doc de toolchain, portait une autre version.
    Le symptome apparaissait a l'ouverture d'une NOUVELLE FENETRE parce que le
    processus fils herite du PATH de l'IDE — d'ou un bug « qui varie selon la
    machine ». MakeNkCodeDist.py ne livrait aucune de ces DLL.
    
    `-static` plutot que les seuls `-static-libstdc++ -static-libgcc` : ces deux
    drapeaux laissent libwinpthread-1.dll en import DIRECT (elle etait masquee
    derriere libstdc++), et le pilote clang ajoute son `-lwinpthread` APRES nos
    ldflags — un `-Wl,-Bstatic ... -Bdynamic` encadrant ne l'attrape pas (essaye,
    sans effet, ligne de lien lue avec --verbose).
    
    NKIlyana.jenga deconseille `-static` seul (« casse la selection lld ») : verifie
    ici, ce n'est pas le cas pour NKCode. Release ET Debug : 23/23 SUCCESS, table
    d'imports sans aucune DLL MinGW (ne restent que DINPUT8, vulkan-1 et python312,
    cette derniere livree par la distribution), et l'IDE demarre.
    
    Cinq applications portaient deja des drapeaux de ce genre ; NKCode, la seule
    distribuee a des testeurs externes, ne les avait pas.
```
- Ce que ce commit fait :  runtime MinGW en statique — l'exe ne depend plus du msys64 du testeur

- Pourquoi il le fait : a cause du bug rencontré , du résultat obtenu par le testeur, la cause racine (conflit de versions via le PATH et présence d'un msys64 local), les tentatives échouées (-static,-wl,--static-libstdc++ ,-Bstatic )
```cpp
Issue beta #15, seconde moitie. NKCode.exe importait libstdc++-6.dll et
    libgcc_s_seh-1.dll, que le chargeur resolvait PAR LE PATH — donc chez
    l'utilisateur.
Un testeur a recu « NKCode.exe - Point d'entree introuvable :
    clock_gettime64 est introuvable dans C:\msys64\ucrt64\bin\libstdc++-6.dll » :
    son msys64, installe en suivant la doc de toolchain, portait une autre version.
    Le symptome apparaissait a l'ouverture d'une NOUVELLE FENETRE parce que le
    processus fils herite du PATH de l'IDE — d'ou un bug « qui varie selon la
    machine ». MakeNkCodeDist.py ne livrait aucune de ces DLL.
    
    `-static` plutot que les seuls `-static-libstdc++ -static-libgcc` : ces deux
    drapeaux laissent libwinpthread-1.dll en import DIRECT (elle etait masquee
    derriere libstdc++), et le pilote clang ajoute son `-lwinpthread` APRES nos
    ldflags — un `-Wl,-Bstatic ... -Bdynamic` encadrant ne l'attrape pas (essaye,
    sans effet, ligne de lien lue avec --verbose).
```
- Le sujet : il en existe 1 seul et c'est intégration statique des bibliothèques MinGW (-static) dans NKCode.exe pour supprimer la dépendance aux DLLs locales (msys64) et corriger les plantages au lancement (issue beta #15).

# Deuxième commit
```cpp
    commit 432850100b391c2251ec9bcb5a7e8d41afe0709e (origin/fix/nktraits-portable)
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Thu Sep 10 16:24:50 2026 +0100

    NkTraits : demander a la primitive si elle existe, pas au compilateur qui il est
    
    Neuf blocs s'ouvraient sur la meme condition :
    
        #if defined(__clang__) || defined(__GNUC__) || defined(_MSC_VER)
    
    Elle demande QUI est le compilateur au lieu de demander SI la primitive existe,
    et les deux ne sont pas la meme question. GCC definit __GNUC__, il entrait donc
    dans la branche des intrinseques -- mais g++ 12 ne connait pas
    __is_trivially_destructible. Sur les onze primitives de ce fichier, dix
    compilent avec g++ 12.2 et celle-la est refusee : il a suffi d'elle pour rendre
    NKCore dependant de clang, et avec lui tout ce qui l'inclut.
    
    Les branches de repli etaient pires que le defaut qu'elles couvraient. Elles ne
    sont pas conservatrices, elles sont fausses :
    
        NkIsTriviallyDestructible = true      <- pour TOUT type, destructeur compris
        NkIsBaseOf                : NkFalseType
        NkIsPolymorphic           : NkFalseType
        NkIsEmpty                 : sizeof(T) == 1
    
    La premiere est la dangereuse : un conteneur qui s'y fie saute les destructeurs.
    Un compilateur inconnu ne recevait pas une erreur, il recevait des fuites
    silencieuses -- et une reponse fausse coute toujours plus cher qu'un refus de
    compiler.
    
    Cascade a trois niveaux :
    
        1. la primitive, si le compilateur la porte      le plus direct
        2. std::, si <type_traits> est la                exact, et partout
        3. l'approximation existante                     pre-C++11 seulement
    
    Le niveau 2 n'est pas une concession au principe « sans dependance STL » annonce
    en tete de fichier : l'inclusion conditionnelle de <type_traits> existe DEJA
    « pour les fallbacks », et le fichier s'en sert quarante-neuf fois. On suit son
    motif, on n'en invente pas un second.
    
    MSVC est traite avant __has_builtin : il porte ces intrinseques depuis VS2015
    mais n'a __has_builtin que depuis VS2022, et repondrait « non » a des primitives
    qu'il possede. zig c++ EST clang, il suit clang sans rien de special.
    
    Eprouve dans l'image de correction de RIHEN Academy, meme montage des deux
    cotes, sur treize proprietes dont les valeurs attendues sont celles du standard
    et non celles d'une implementation :
    
        avant   g++ 12.2 REFUSE      clang++ 14 compile
        apres   g++ 12.2 compile     clang++ 14 compile     13/13 justes chacun
```
- Ce qu'il fait : demander a la primitive si elle existe, pas au compilateur qui il est

- Le pourquoi : les branches de repis n'étaient pas conservatrice et elles étaient fausses, le complateur  inconnu ne recevait pas une erreur, il recevait des fuites, 

-Le sujet : il y a  1 :**verification de l'utilisation du compilateur (clang, GCC ou MSVC), via une cascade a 3 niveaux (feature detection, std::type_traits, fallback) pour corriger l'incompatibilité avec g++ 12.2 et éliminer les faux résultats dangereux lors de la destruction d'objets.**

# troisième commit
```cpp
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Fri Aug 28 22:03:44 2026 +0100

    Distribution : refuser de livrer un exe dont une DLL importee manque
    
    La liste des DLL copiees a cote de NKCode.exe etait tenue A LA MAIN, alors que
    le commentaire du script disait deja « DLLs exigees AU DEMARRAGE (import table
    de NKCode.exe) ». Elle etait incomplete : les trois runtimes MinGW n'y
    figuraient pas, et personne ne pouvait le voir avant qu'un testeur ne l'ecrive
    (issue beta #15).
    
    VerifierImports() confronte desormais la table d'imports REELLE du binaire
    (objdump -p) au contenu livre : toute DLL non-systeme absente arrete la
    distribution avec la liste des manquantes. Les DLL fournies par Windows — ou
    par le pilote GPU pour vulkan-1 — sont explicitement listees et ignorees.
    
    Degradation choisie : si objdump est introuvable ou inutilisable, on PREVIENT
    sans bloquer (le script tourne aussi sur des machines sans binutils) ; c'est
    seulement une DLL reellement manquante qui fait echouer la livraison.
    
    Verifie dans les deux sens : distribution complete -> « aucune DLL non-systeme
    manquante » ; python312.dll retiree a la main -> refus, sys.exit(1), message
    nommant la DLL. Un garde-fou qui n'a jamais refuse ne prouve rien.
```
-Ce que ce commit fait : il refuse de livrer un exe dont le DLL importé manque

-Le pourquoi : parce que 
```cpp
La liste des DLL copiees a cote de NKCode.exe etait tenue A LA MAIN, alors que
    le commentaire du script disait deja « DLLs exigees AU DEMARRAGE (import table
    de NKCode.exe) ». Elle etait incomplete : les trois runtimes MinGW n'y
    figuraient pas, et personne ne pouvait le voir avant qu'un testeur ne l'ecrive
    (issue beta #15).
```

-Le sujet : 01 sujet **la validation automatisée des dépendances DLL lors de la livraison du binaire.**
