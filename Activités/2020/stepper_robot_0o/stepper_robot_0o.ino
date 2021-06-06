#include "KitFocus.h"

//en programmation arduino, la fonction setup est appelée au début une fois, puis la fonction loop est appelée continuellement

RobotKitFocus * pMyRobot; // création de pointeur d'un objet robot

void setup()
{
  Serial.begin(9600);           //initialisation de la communication sérielle pour débugage
  
  pMyRobot = new RobotKitFocus; //création d'un objet RobotKitFocus
  pMyRobot->setStepperSpeed (600);  //vitesse à 600
  pMyRobot->setStepperMaxSpeed (600); //vitesse maximale à 600
  pMyRobot->setStepperAcceleration (100); //accélération à 100
  pMyRobot->defineControls(0x19, 0x15, 0x18, 0x1A); //codes IR pour contrôler le robot
  
}

void loop() 
{
  pMyRobot->updateRobot();
}
