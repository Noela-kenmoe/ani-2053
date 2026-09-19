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

2. CONTENU DU COMMIT

Chaque commit doit représenté une seule modification logique, vérifier systématiquement le contenu réel des commits avec les commandes **git diff** ou **git show** , ne pas mélangé la correction d'un bug et l'ajout d'une fonctionnalité dans un meme commit

3. RELECTURE DE CODE
- Pour chaque PR, au moins 1 membres de l'équipe (autre que l'auteur) doit relire et approuver le code 
- L'approbateur teste le code localement 
```
git checkout <branche> + compilation/tests et vérifie la qualité.
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

**REMARQUE** : il est toujours conseillé d'utiliser **git revert** à **git reset --hard**
- Post-mortem rapide : l'auteur du commit et le relecteur corrigent le problème sur une branche **fix** dédiée avant de réintégrer le code via une nouvelle PR (Pull request)