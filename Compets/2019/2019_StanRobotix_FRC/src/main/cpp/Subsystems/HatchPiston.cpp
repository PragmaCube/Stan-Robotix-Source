/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/HatchPiston.h"
#include <RobotMap.h>
#include <iostream>

HatchPiston::HatchPiston() : Subsystem("HatchPiston") {
  solenoid0 = new Solenoid(kHatchPiston0);
  //^^^ connecte a la base
  solenoid1 = new Solenoid(kHatchPiston1);
  //^^^ connecte a l'extremite

  solenoid0->Set(false);
  solenoid1->Set(true);
  //piston est desactive quand 1 est true et 0 est false
}

void HatchPiston::InitDefaultCommand() {
}

void HatchPiston::Toggle()
{
  solenoid0->Set(!solenoid0->Get());
  solenoid1->Set(!solenoid1->Get());
  if (solenoid0->Get())
  {
    std::cout<<"piston : active "<<std::endl;
  }
  else
  {
    std::cout<<"piston : desactive "<<std::endl;
  }
}

void HatchPiston::Retract()
{
  // valeurs true/false inconnues
  solenoid0->Set(false);
  solenoid1->Set(true);
}