/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/Ventouse.h"
#include <RobotMap.h>
#include <iostream>


Ventouse::Ventouse() : Subsystem("Ventouse") {
  solenoid0 = new Solenoid(kVentouse0);
  //^^^Valve de pression
  solenoid1 = new Solenoid(kVentouse1);
  //^^^Solenoid de ventouses
  
  solenoid0->Set(true);
  solenoid1->Set(false);
  //ventouse est desactivee quand 0 est true et 1 est false
}

void Ventouse::InitDefaultCommand() {
  
}

void Ventouse::Toggle()
{
  solenoid0->Set(!solenoid0->Get());
  solenoid1->Set(!solenoid1->Get());
  if (solenoid1->Get())
  {
    std::cout<<"ventouse : activee "<<std::endl;
  }
  else
  {
    std::cout<<"ventouse : desactivee "<<std::endl;
  }
}

void Ventouse::TurnOff()
{
  solenoid0->Set(true);
  solenoid1->Set(false);
}
