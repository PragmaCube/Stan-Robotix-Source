/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Senseurs.h"

Senseurs::Senseurs() : Subsystem("Senseurs") {
  captDist = new frc::AnalogInput(kCaptDist);
  captDist2 = new frc::AnalogInput(kCaptDist2);
  gyro = new frc::ADXRS450_Gyro();
  accelerometre = new frc::BuiltInAccelerometer();
  gyro->Reset();
}

void Senseurs::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Senseurs::Calibrate()
{
  gyro->Calibrate();
}

double Senseurs::GetDist()
{
  return captDist->GetVoltage()*VoltToFootDistCapt;
}

double Senseurs::GetDist2()
{
  return captDist2->GetVoltage()*VoltToFootDistCapt;
}

double Senseurs::GetGyro()
{
  return gyro->GetAngle();
  // angle par rapport au depart. negatif pour sens anti-horaire
}

double Senseurs::GetAcceleroX()
{
  return accelerometre->GetX();
  // axe horizontal du roboRIO. negatif pour gauche(?)
}

double Senseurs::GetAcceleroY()
{
  return accelerometre->GetY();
  // axe vertical du roboRIO. negatif pour bas(?)
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
