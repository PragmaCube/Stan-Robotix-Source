/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/CentrePID.h"

#include <livewindow/LiveWindow.h>
#include <smartdashboard/SmartDashboard.h>
#include "Robot.h"
#include <iostream>

CentrePID::CentrePID() : PIDSubsystem("CentrePID", 2.0, 2.0, 2.0) 
{
  EnableWithSettings();
}
CentrePID::CentrePID(double p, double i, double d) : PIDSubsystem("CentrePID", p,i,d) 
{
  EnableWithSettings();
}

double CentrePID::ReturnPIDInput() 
{
  return Robot::m_vision.GetContoursCentreX();
}

void CentrePID::UsePIDOutput(double output) 
{
  mPIDOutput = output;
} 

void CentrePID::InitDefaultCommand() 
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

double CentrePID::GetPIDOutput() 
{
  if (Robot::m_vision.FoundContour())
  {
  return mPIDOutput;
  }
  else
  {
    return 0;
  }
}

void CentrePID::EnableWithSettings()
{
  SetOutputRange(-0.3,0.3);
  SetAbsoluteTolerance(0.2);
  Enable();  
}
