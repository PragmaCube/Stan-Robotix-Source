/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems\RotationPID.h"

#include "LiveWindow\LiveWindow.h"
#include <SmartDashboard/SmartDashboard.h>
#include <Robot.h>
#include <iostream>

//RotationPID::RotationPID() : PIDSubsystem("RotationPID", Robot::PIDSettingsPtr[0], Robot::PIDSettingsPtr[1], Robot::PIDSettingsPtr[2]) 
RotationPID::RotationPID() : PIDSubsystem("RotationPID", 1 ,0, 0) 
{
  EnableWithSettings();
}

RotationPID::RotationPID(double p, double i, double d) : PIDSubsystem("RotationPID", p,i,d) 
{
  EnableWithSettings();
}




double RotationPID::ReturnPIDInput() {
  return Robot::m_gps.GetAngle();
}

void RotationPID::UsePIDOutput(double output) 
{
  mPIDOutput = output;
}

double RotationPID::GetPIDOutput()
{
  return mPIDOutput; 
}

void RotationPID::InitDefaultCommand() 
{

}

void RotationPID::EnableWithSettings()
{
  SetOutputRange(-0.8,0.8);
  SetAbsoluteTolerance(1);
  Enable();  
}