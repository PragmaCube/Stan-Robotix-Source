<p align="center">
  <img width="256" height="226" src="https://stanrobotix.files.wordpress.com/2017/01/cropped-cropped-equipe-stan-logo2.jpg">
</p>

# Stan-Robotix-Source
Code source des compétitions auxquelles [Stan Robotix](https://stanrobotix6622.com/) a participé, les autres activités et la documentation.
2019-2022

## Pourquoi créer un repositoire global?
Il a été créé pour éviter de multiplier le nombre de repositoires. En effet, à chaque compétition ou à chaque projet, Programmation en créait un, faisant en sorte qu'il fallait chercher
longtemps pour retrouver dans un programme déjà fait des morceaux de codes réutilisables.
Ce repositoire sera donc global et les autres codes se feront dans les sous-dossiers.

## Qui a le droit de commit?
Tout le monde dans l'équipe programmation (si vous n'êtes pas dans l'équipe vous pouvez proposer une modification mais pas commit pour que les étudiants apprenent par eux-mêmes) tant que cela est pertinant. Les mentors peuvent modifier le code mais on privilégie les élèves pour qu'ils apprennent à le faire eux-même.

**Évitez de faire des modifications directement via Github.**  

## Les répertoires
Trois grandes catégories : Compets (code des compétitions), Activités (code des activités/projets) et Doc (pour vous aider).
Puis on sépare en sous-dossiers pour chaque année.
Pour créer et nommer des sous-dossiers, veiller à respecter la convention suivante :
- Pour les compétitions : **Année_StanRobotix_NomDeLaCompétitionEnMajuscule** (e.g. 2019_StanRobotix_FRC OU 2019_StanRobotix_BETABOT)
- Pour les activités : **NomDuProjet** (e.g. Formation-Github OU Mastermind --> On met des tirets entre les mots)
- Pour la documentation : seuls le chef de Programmation et des mentors peuvent modifier/rajouter des documents

## Les conventions à respecter pour coder
**À RESPECTER IMPÉRATIVEMENT POUR UN CODE UNIFORME**
- Programmer en anglais
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
git clone
git status
git add *
git add "NomDuFichier"
git commit -m "MessageQuiADuSens"
git push
git checkout NomDeLaBranche
git rm "NomDuFichier"
git pull
```
## Gestion
La gestion du repositoire (modification du README ou modifications majeures) est laissée au chef de l'équipe et aux mentors.


Chef d'équipe : Nahuel Duquéroy-Roldán<br>
Mentors : Cyril Jacob, Philippe Ducas, Raphaël Pothier et Martin Le Gallic

Contacts :

raphael.pothier@umontreal.ca <br>
martin.le.gallic@usherbrooke.ca <br>
cyril.jacob@stanislas.qc.ca <br>
philippe.ducas@stanislas.qc.ca <br>
nahuel.duqueroy-roldan@stanislas.qc.ca<br>
<br>
