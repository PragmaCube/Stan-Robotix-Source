<p align="center">
  <img width="256" height="256" src="https://stanrobotix.files.wordpress.com/2017/01/cropped-cropped-equipe-stan-logo2.jpg">
</p>

# Stan-Robotix-Source
Code source des compétitions auxquelles l'équipe [Stan Robotix 6622](https://stanrobotix6622.com/) a participé, ainsi les autres activités et de la documentation.
2019-2023

## Pourquoi créer un dépôt global?
Il a été créé pour éviter de multiplier le nombre de dépôts. En effet, à chaque compétition ou à chaque projet, Programmation en créait un, faisant en sorte qu'il fallait chercher
longtemps pour retrouver dans un programme déjà fait des morceaux de codes réutilisables.
Ce dépôt est donc global et les autres programmes se feront dans les sous-dossiers.

## Qui a le droit de modifier le dépôt?
Tout le monde dans l'équipe programmation tant que cela est pertinant. Les mentors peuvent modifier le code mais on privilégie les élèves pour qu'ils apprennent à le faire eux-même. Les personnes externes à l'équipe voulant apporter des modifications doivent contacter l'équipe.

**Évitez de faire des modifications directement via Github.**  

## Les répertoires
Trois grandes catégories : Compets (code des compétitions), Activités (code des activités/projets) et Doc (pour vous aider).
Puis on sépare en sous-dossiers pour chaque année.
Pour créer et nommer des sous-dossiers, veiller à respecter la convention suivante :
- Pour les compétitions : **Année_StanRobotix_NomDeLaCompétitionEnMajuscule** (e.g. 2019_StanRobotix_FRC OU 2019_StanRobotix_BETABOT)
- Pour les activités : **NomDuProjet** (e.g. Formation-Github OU Mastermind --> On met des tirets entre les mots)
- Pour la documentation : seuls le chef de Programmation et des mentors peuvent modifier ou rajouter des documents.

## Les Branches
Pour le nom des branches, respectez la convention suivante :
Année-StanRobotix-Compétition-Subsystem

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
git fetch
```
## Gestion
La gestion du dépôt (modification du README ou modifications majeures) est laissée au chef de l'équipe et aux mentors.


Chef d'équipe : André Wojcik<br>
Mentors : Raphaël Pothier, Clement Jevardat-de-Fombelle et Martin le Gallic

Contacts :

wojcik.andre2.0@gmail.com <br>
raphael.pothier@umontreal.ca <br>
marty.legallic@sherbrooke.com <br>