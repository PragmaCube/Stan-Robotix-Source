// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <iostream>

RobotContainer::RobotContainer()
{
  mDriveTrain = new SubDriveTrain;
 
  mMotorSpeed[0] = SubDriveTrain::MotorSpeed::eSlow;
  mMotorSpeed[1] = SubDriveTrain::MotorSpeed::eMedium;
  mMotorSpeed[2] = SubDriveTrain::MotorSpeed::eFast;

  mMotorIndex = 1;  
   ConfigureButtonBindings();
  
}


void RobotContainer::DriveDisplacement()
{
  if (mController.GetRightBumperPressed())
  {
    if (mMotorIndex < 2)
    {
      mMotorIndex++;
    }
  }

  if (mController.GetLeftBumperPressed())
  {
    if (mMotorIndex > 0)
    {
      mMotorIndex--;
    }
  }
 // std::cout << mMotorIndex << std::endl;

  mDriveTrain->MoveDrive(
      -mController.GetLeftY(),
      -mController.GetRightY(), mMotorSpeed[mMotorIndex]);
}

void RobotContainer::ConfigureButtonBindings()
{
  // Configure your button bindings here
}

void RobotContainer::Drive()
{
  DriveDisplacement();
}

void RobotContainer::Auto()
{

}