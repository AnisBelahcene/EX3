![](https://github.com/thierryseegers/DevCommeLesPros-2020-Ex3/workflows/Test%20master/badge.svg)

# DevCommeLesPros-2020-Ex3

Modèle de départ pour exercices d'introduction au travail par équipe avec github et intégration continue.

## Instructions de départ

Ces intructions présupposent que vous avez déjà suivi les instructions du [premier exercice](https://github.com/thierryseegers/DevCommeLesPros-2020-Ex1#instructions-de-d%C3%A9part) pour la création de compte et l'installation des programmes et extensions nécéssaires.

Pour cet exercice, vous devez travailler en binôme sur un même dépôt. Choisissez qui du binôme créera le dépôt. Par la suite, ce même dépôt sera cloné par les deux membres du binôme.

#### Pour créer le dépôt (un membre du binôme):
1. Créez votre dépôt sur github.com en utilisant ce dépôt-ci (https://github.com/thierryseegers/DevCommeLesPros-2020-Ex3) comme modèle.
    - Suivez ces instructions: https://help.github.com/en/github/creating-cloning-and-archiving-repositories/creating-a-repository-from-a-template.
    - Choisissez l'option `Private` à l'étape 5.
1. Ajoutez le professeur comme collaborateur à votre dépôt.
    - Suivez ces instructions: https://help.github.com/en/github/setting-up-and-managing-your-github-user-account/inviting-collaborators-to-a-personal-repository
        - Nom d'utilisateur à ajouter: `thierryseegers`.
1. Ajoutez votre co-équipier(ère) comme collaborateur à votre dépôt.
    - Suivez les instructions de l'étape précédente.

#### Pour cloner le dépôt (deux membres du binôme):
1. Clonez le dépôt vers votre espace de travail local.
    - Suivez ces instructions: https://help.github.com/en/github/creating-cloning-and-archiving-repositories/cloning-a-repository
    - Attention à ne pas cloner https://github.com/thierryseegers/DevCommeLesPros-2020-Ex3 mais bien votre dépôt nouvellement créé.
1. Lancez Visual Studio Code.
    - À l'invite de commandes:
        - `> cd [nom de votre dépôt]`
        - `> code .`
1. Si vous voyez le message `The debug type is not recognized. Make sure that you have a corresponding debug extension installed and that it is enabled.`, n'en tenez pas compte.


## Objectif

Pour commencer, le programme de test de cet exercice a tout ses tests commentés.
Il vous faudra les décommenter à mesure qui vous implémenterez les fonctionalités de la bibliothèque `liste`. Le programme de test:
- affiche le résultat de chaque test exécutés (`[SUCCES]` ou `[ECHEC]`).
- affiche en fin d'exécution la fraction du nombre de tests réussis sur le nombre de tests exécutés (p. ex. `10/16`).
- retourne comme valeur la différence entre les tests exécutés et les tests réussis (p. ex. 16 - 10 -> `6`).

Vous devrez:

1. Modifier l'URL en tête du document `README.md` pour refléter l'URL de votre dépôt.
    - L'URL doit ressembler à `https://github.com/[nom-de-votre-compte]/[nom-de-votre-depot]/workflows/Test%20master/badge.svg`.
    - Cet URL présente un "badge" qui réflete l'état de santé de votre dépôt.
1. Complétez le fichier `makefile`:
    - Complétez les cibles déjà définies.
        - La cible `check` doit dépendre de la cible `build/test` et doit invoquer le programme de test.
        - **Il est impératifs que les cibles `build/libliste.a`, `build/test` et `check` soient définies pour la bonne exécution de cet exercice.**
    - Ajoutez d'autres cibles à votre guise.
1. Implémentez correctement toutes les fonctions de la bibliothèque logicielle `liste` pour que finalement le programme `test` affiche `87/87` et retourne `0`.

Il vous est permis: 
- De modifier le fichier `README.md`.
- De modifier le fichier `makefile`.
- De modifier le fichier `lib/liste.c` afin d'implémenter les fonctions qu'il contient.
- De modifier le fichier `test/main.c` pour activer le plus de tests possible.

En tout temps:
- votre code doit réussir 100% des tests activés (même si ce n'est pas l'entièreté des tests) avant d'être intégré dans la branche `master`.
- le badge apparaissant tout en haut de ce document doit afficher `passing`.

## Instructions de travail

Chacun des membres du binôme devra suivre ces instructions au moins une fois.

1. Créez une nouvelle branche qui servira de branche de travail pour réparer une première suite de tests.
    - `> git branch [nom de la branche]`
    - `> git checkout [nom de la branche]`
    - Exemple: `> git branch implementation-l_make_node`, `> git checkout implementation-l_make_node`.
1. Au fur et à mesure de vos modifications au code, intégrez-les au dépôt local avec une description des modifications apportées.
    - `> git add [fichiers]`
    - `> git commit -m "Description des modifications apportées"`
    - Exemple: `> git add lib/liste.c`, `> git commit -m "Passe les tests pour l_make_node."`
1. Périodiquement, publiez votre branche de votre dépôt local à votre dépôt sur github.com.
    - `> git push origin [nom de la branche]`
    - Exemple: `> git push origin implementation-l_make_node`.
1. Lorsqu'une suite de tests est réparée, ouvrez un "Pull Request" sur github.com pour fusionner la branche de travail à la branche `master`.
    - Suivez ces instructions: https://help.github.com/en/desktop/contributing-to-projects/creating-a-pull-request
    - Décrivez les bénéfices apportés par ce Pull Request en suivant les suggestions du modèle ("Modification(s) apportée(s)", "Problème(s) résolu(s)", "Vérification(s) et test(s)").
1. Attendez que le service d'Intégration Continue lance un compilation de votre base de code et le test.
    - Vous devriez voir une «fenêtre» apparaître comme celle-ci : 
    ![Intégration Conitnue enclenchée](https://user-images.githubusercontent.com/1580647/75868664-a806f900-5e08-11ea-8fd5-cc1df9f6ca42.png)
1. Assurez-vous que le résultat de la compilation et du test automatique par le service d'Intégration Continu soit positif!
    - La fenêtre précédente devrait devenir comme celle-ci :
    ![Intégration Conitnue réussie](https://user-images.githubusercontent.com/1580647/75868675-b05f3400-5e08-11ea-93b1-87756c4dc80f.png)
1. Si le résultat échoue, vous devez réparer le problème sur votre branche dans votre dépôt local et apporter les modifications nécéssaires.
    - Si la fenêtre vous montre ceci, **vous ne devez pas fusionner votre branche** :
    ![Intégration Conitnue échoue](https://user-images.githubusercontent.com/1580647/75869715-421b7100-5e0a-11ea-81b1-50854cc01c7b.png)
1. Demander à votre co-équipier(ère) de passer en revue vos modifications, de suggérer des améliorations si besoin est et, ultimement, d'approuver.
    - Suivez ces instructions pour demander une revue: https://help.github.com/en/github/collaborating-with-issues-and-pull-requests/requesting-a-pull-request-review
    - Suivez ces instructions pour faire une revue: https://help.github.com/en/github/collaborating-with-issues-and-pull-requests/commenting-on-a-pull-request
1. **Quand la compilation et les test automatiques auront réussi et que votre co-équipier(ère) aura approuvé votre Pull Request**, fusionnez la branche de travail sur github.com.
    - Suivez ces instructions: https://help.github.com/en/github/collaborating-with-issues-and-pull-requests/merging-a-pull-request#merging-a-pull-request-on-github
    - Choisissez `Create a merge commit` à l'étape 3.
1. Revenez sur la branche `master` de votre dépôt local et synchronisez-la avec la branche `master` de votre dépôt sur github.com.
    - `> git checkout master`
    - `> git pull origin master`
1. Répétez ces étapes jusqu'à ce que tout les tests passent.

Avec la commande `> git log --all --decorate --graph --pretty=format:"%ar (%an) %s""`, l'historique de votre travail devrait au fil du temps ressembler à ceci (lire du bas vers le haut):

```
*   1 hour ago (origin/master, origin/HEAD, master) Merge pull request #4 from MickeyMouse/implementation-l_length
|\
| * 3 hours ago (DonalDuck) Passe tout les tests de l_length.
| * 4 hours ago (DonalDuck) Passe le test l_length quand la liste est longe de zéro ou une node.
|/
*   1 day ago Merge pull request #3 from MickeyMouse/implementation-l_make_node
|\
| * 1 day ago (Donald Duck) Passe les tests de l_make_node.
|/
*   2 days ago (Mickey Mouse) Merge pull request #2 from MickeyMouse/reparation-makefile
|\
| * 2 days ago (Mickey Mouse) Peut invoquer check pour lancer le programme de test.
| * 2 days ago (Mickey Mouse) Peut compiler, lancer et déboguer le programme test.
| * 2 days ago (Mickey Mouse) Peut compiler la bibliothèque libliste.a.
|/
*   3 days ago (Donald Duck) Merge pull request #1 from MickeyMouse/correction-URL
|\
| * 3 days ago (Donald Duck) Corrigé URL du badge en tête du README comme demandé.
|/
* 3 days ago Initial commit
```

Remarquez que les deux collaborateurs contribuent au même dépôt.

## "J'ai un problème !"

Voyez les indications données dans le [premier exercice](https://github.com/thierryseegers/DevCommeLesPros-2020-Ex1#jai-un-probl%C3%A8me-) à ce sujet.

## Évaluation

Dans le répertoire `correction`, vous trouverez le script que le professeur utilisera pour automatiser une première partie du processus de correction.
Pour une liste de dépôts donnée dans `correction/depots.txt`, le script:
 - clone le dépôt.
 - invoque `make build/libliste.a`.
 - lie cette bibliothèque avec le fichier objet produit par une pré-compilation du fichier `test/main.c` original.
 - lance le programme.
 - affiche le résultat de la fraction du nombre de tests réussis sur le nombre de tests exécutés.

Vous pouvez tester votre propre dépôt comme le fera le professeur:
1. Installez le module pygit2 avec `> pip3 install pygit2` à l'invite de commandes.
1. Ajoutez le nom de votre dépôt à la liste `correction/depots.txt`.
1. Lancez le script à l'invite de commandes:
    - `> cd correction`
    - `> python3 correction.py`

La deuxième partie de la correction est une inspection visuelle de votre code.

Seul le code de la branche `master` de votre dépôt sur http://github.com compte !
