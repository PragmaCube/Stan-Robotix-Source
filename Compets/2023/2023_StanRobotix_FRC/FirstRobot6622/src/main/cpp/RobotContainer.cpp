// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <iostream>
 

RobotContainer::RobotContainer()
{
  mDriveTrain = new SubDriveTrain;

	mImu = new SubIMU;
	mImu->Start();
  mDriveTrain->SetImuPointer(mImu);
   	ConfigureButtonBindings();
}


void RobotContainer::DriveDisplacement()
{
  const double slider = (1-mJoystick.GetThrottle())/2;
  mDriveTrain->MoveMeca(mJoystick.GetX()*slider, mJoystick.GetY()*slider, mJoystick.GetTwist()*slider,mJoystick.GetRawButton(0));
  std::cout<<mJoystick.GetRawButton(0)<<std::endl;
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