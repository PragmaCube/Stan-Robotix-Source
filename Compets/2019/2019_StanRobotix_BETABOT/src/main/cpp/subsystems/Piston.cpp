/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Piston.h"

Piston::Piston() : Subsystem("Piston")
{
  // solenoid0 est a la base, solenoid1 est au bout du piston
  solenoid0 = new frc::Solenoid(kSolenoid0);
  solenoid1 = new frc::Solenoid(kSolenoid1);
  solenoid0->Set(false);
  solenoid1->Set(true);
}

void Piston::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Piston::SetActive()
{
  solenoid0->Set(true);
  solenoid1->Set(false);
}

void Piston::SetInactive()
{
  solenoid0->Set(false);
  solenoid1->Set(true);
}

void Piston::Toggle()
{
  solenoid0->Set(!solenoid0->Get());
  solenoid1->Set(!solenoid1->Get());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
