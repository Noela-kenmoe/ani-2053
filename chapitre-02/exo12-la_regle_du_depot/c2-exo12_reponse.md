# EXERCICE 12
Les règles pour une bonne collaboration sur github sont :
1. NOMMAGE DES BRANCHES
- La branche principale main: celle-ci on la maintient et personne ne travail dessus

- Les autres branches : chaque branche porte le nom de la tache a éffectuée dessus : par exemple (devops, Fontend, backend etc...)
- Les types de branches définis


|type|Role|
|----|----|
|**feat**|développement d'une nouvelle fonctionnalité|
|**Fix**|correction d'un bug ou d'une erreur|
|**Docs**|Ajouter une mise a jour de la documentation|
|**refactor**|Reconstruction, nettoyage et réorganisation du code sans en modifier le comportement ou une nouvelle fonction|

## EXEMPLE DE BRANCHE :
```
git checkout -b feat/noela/ecran-connexion-frontend
```

2. CONTENU DU COMMIT

Chaque commit doit représenté une seule modification logique, vérifier systématiquement le contenu réel des commits avec les commandes **git diff** ou **git show** , ne pas mélangé la correction d'un bug et l'ajout d'une fonctionnalité dans un meme commit

3. RELECTURE DE CODE
- Pour chaque PR, au moins 1 membres de l'équipe (autre que l'auteur) doit relire et approuver le code 
- L'approbateur teste le code localement 

- Le **pull request** ne peut etre fusionnée dans **main** que si elle a recu au moins 1 approbation d'un coéquiper, le code compile sans erreur et passe tous les tests
- Interdiction de **push** directement sur **main** : tout changement doit passer par une Pull Request (PR) ou Merge Request (MR)


4. PRATIQUES INTERDIT 

- Interdit de taper la commande sur la branche **main** ou **develop**
```
git push --force
```
- Commiter des fichiers temporaires ou générés (binaires, .exe) et les dossiers (.vs/, .idea, build/, fichier de configuration locale)
- Déposer des identifiants/ clés d'accès/ secrets dans les commits
- Faire des commits **fourre-tout** : exemple (le type "update","wip","fix stuff")

5. PROCEDURE D'URGENCE : Que faire si **main**  est cassées?
Si un code défectuex est poussé et aarivé sur **main** (erreurs de compilation, crash) :
- Alerter immediatement l'équipe : signaler le problème sur le canal de discussion du groupe
- Geler les fusions : plus personne ne fusionne de PR sur **main** tant que le problème n'est pas résolu 
- Annuler le commit responsable (bonne méthode)
Trouver le hash du commit fautif via **git log**


Créer un commit d'annulation explicite :
```
git revert <hash_du_commit_fautif>
git push origin main
```

-Pourquoi il est important de ne pas pousser sur la branche main :
- Garantire la stabilité du code : la branche main contient la version officielle et focntionnell du projet, Poussé directement sur cette branche risque d'intégrer un code qui ne compile pas ou qui plante, ce qui bloque toute l'équipe
- Conserver un historique propre: cela évute de polluer l'historique de **main** avec des commits de travils temporiaires (corrections, tests)
-Faciliter la gestion des erreurs : en cas de problème, il est beaucoup plus simple d'annuler ou de corriger une branche isolée que de réparer la branche principale
- Les règles pour empecher de pousser directement sur main 
1. Activation des **Branch Protection Rules** sur github (les etapes sont : Setting- Branches- Add rule sur main)

2. L'**option Require a pull request before merging**: le bouton push sur main est physiquement bloqué par gihub pour tous les membres

3. **Option Require approvals : réglées sur 1 approbation minimum, la fusion (merge) est bloquée et impossible à cliquer tant qu'un coéquiper n'a pas validé la PR

**REMARQUE** : il est toujours conseillé d'utiliser **git revert** à **git reset --hard**
- Post-mortem rapide : l'auteur du commit et le relecteur corrigent le problème sur une branche **fix** dédiée avant de réintégrer le code via une nouvelle PR (Pull request)