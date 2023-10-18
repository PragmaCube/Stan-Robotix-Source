<p align="center">
  <img width="256" height="256" src="https://static.wixstatic.com/media/89f157_1e985f270d91477cb3e130f01d7198a5~mv2.png/v1/fill/w_544,h_493,al_c,q_85,usm_0.66_1.00_0.01,enc_auto/equipe-stan-logo_edited_edited.png">
</p>

# Stan-Robotix-Source
Dépôt officiel de l'équipe [Stan Robotix 6622](https://stanrobotix6622.com/) participant à la compétition [FIRST](https://www.firstinspires.org/robotics/frc)

2019-2023

## Structure
- Activités : tout ce qui n'est pas relié aux compétitions
- Compets : l'intégralité du code source des compétitions ([BetaBots](https://robotiquefirstquebec.org/frc/betabots/) et FRC)
- Doc : documentation créée par l'équipe pour la communauté
  - Liste d'exercices V1.1 DISPONIBLE
  - Corrections de la liste d'exercices V1.1 DISPONIBLE
  - Aide rapide sur Git et Github V1.0 DISPONIBLE
  - Aide sur la structuration d'un programme C++ V1.0 DISPONIBLE
  - Manuel sur les bases C++ et l'utilisation de [WPILIB](https://docs.wpilib.org/en/stable/) EN COURS D'ÉCRITURE

## Conventions de structure
- Branches :`Année-StanRobotix-Compétition-SousSytème/Commande`
- Répertoires : `Année_StanRobotix_Compétition/Projet`

## Les conventions de code
- Programmer en anglais
- Variables dans les méthodes :
  - Préfixe i (input) pour les variables d'entrée (e.g. iMotor)
  - Préfixe o (output) pour les variables de sorties (e.g. oAngle)
- Variables locales :
  - Préfixe w (work) (e.g. wSpeed)
- Dans une classe :
  - Préfixe m (my) pour les attributs (e.g. mAccelerometer)
  - Le nom des méthodes commence par une minuscule puis on utilise des majuscules pour les autres mots (e.g. setVoltage())
- Préfixe k (constant) pour les variables constantes (e.g. kPi)
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
Mentors : Raphaël Pothier et Clément Jevardat-de-Fombelle
Contacts :

andre.wojcik@stanislas.qc.ca <br>
raphael.pothier@umontreal.ca <br>