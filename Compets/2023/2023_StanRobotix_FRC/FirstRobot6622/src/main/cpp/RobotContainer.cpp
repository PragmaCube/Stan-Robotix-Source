// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <iostream>

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Date       Auteur     Description                                               Test
// 21jan2023  Andre W.   mecanum operationel en robot-oriented-drive sans IMU      Deplacement omni-directionnel   

RobotContainer::RobotContainer()
{
  mDriveTrain = new SubDriveTrain;
 
   ConfigureButtonBindings();
}


void RobotContainer::DriveDisplacement()
{
  mDriveTrain->MoveMeca(mJoystick.GetX(), mJoystick.GetY(), mJoystick.GetTwist());
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