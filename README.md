# Stan-Robotix-Source
Code source des compétitions auxquelles Stan Robotix a participé, les autres activités et la documentation.
2019-2020

## Pourquoi créer une repository globale?
Elle a été créé pour éviter de multiplier le nombre de repository. En effet, à chaque compétition ou à chaque projet, Programmation en créait une, faisant en sorte qu'il fallait chercher
longtemps pour retrouver dans un programme déjà fait des morceaux de codes réutilisables.
Cette repository sera donc globale et les autres codes se feront dans les sous-dossiers.

## Qui a le droit de commit?
Tout le monde dans l'équipe programmation tant que cela est pertinant. Les mentors peuvent modifier le code mais on privilégie les élèves pour qu'ils apprennent à le faire eux-même.

**IL EST DÉFENDU DE FAIRE DES MODIFICATIONS MANUELLES.**  
**TOUTES DOIVENT ÊTRE FAITES SOIT PAR COMMANDES, SOIT PAR UNE INTERFACE DE TYPE TURTOISEGIT.**

## Les répertoires
Trois grandes catégories : Compets (code des compétitions), Activités (code des activités/projets) et Doc (pour vous aider).
Puis on sépare en sous-dossiers pour chaque année.
Pour créer et nommer des sous-dossiers, veiller à respecter la convention suivante :
- Pour les compétitions : **Année_StanRobotix_NomDeLaCompétitionEnMajuscule** (e.g. 2019_StanRobotix_FRC OU 2019_StanRobotix_BETABOT)
- Pour les activités : **NomDuProjet** (e.g. Formation-Github OU Mastermind --> On met des tirets entre les mots)
- Pour la documentation : seuls le capitaine de Programmation et des mentors peuvent modifier/rajouter des documents

## Les conventions à respecter pour coder
**À RESPECTER IMPÉRATIVEMENT**
- Écrire en anglais
- Avec les fonctions/méthodes :
  - Préfixe i pour les variables d'entrée (e.g. iMotor)
  - Préfixe o pour les variables de sorties (e.g. oAngle)
- Dans un même bloc :
  - Préfixe w pour les variables locales (e.g. wDeltaVelocity)
- Dans une classe :
  - Préfixe m pour les attributs (e.g. mAccelerometer)
  - Les noms de méthodes commence par un minuscule. Si il y a plusieurs mots, on met une majuscule à leur première lettre (e.g. setVoltage())
- Préfixe k pour les variables constantes (e.g. kPi)
- Mettre des commentaires mais ne pas en abuser

## Rappel des commandes de base de Git
```
gitk
git status
git add *
git add "NomDuFichier"
git commit -m "MessageQuiADuSens"
git push
git checkout NomDeLaBranche
git rm "NomDuFichier"
git pull
```
