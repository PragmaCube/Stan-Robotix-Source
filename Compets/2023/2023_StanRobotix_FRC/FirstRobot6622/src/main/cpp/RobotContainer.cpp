// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <iostream>

RobotContainer::RobotContainer()
{
  mDriveTrain = new SubDriveTrain;

    mImu = new SubIMU;
    // mImu->Enable();
    mDriveTrain->SetImuPointer(mImu);

m_autonomousCommand.setSubsystem(mDriveTrain);

    mUltrasonic = new SubUltrasonic;
    mUltrasonic->EnableImperialSystem();

   	ConfigureButtonBindings();
}

frc2::Command *RobotContainer::GetAutonomousCommand()
{
   return &m_autonomousCommand;
}

void RobotContainer::DriveDisplacement()
{
  const double slider = (1-mJoystick.GetThrottle())/2;
  mDriveTrain->MoveMeca(mJoystick.GetX()*slider, mJoystick.GetY()*slider, mJoystick.GetTwist()*slider,mJoystick.GetRawButton(0));
}

void RobotContainer::ConfigureButtonBindings()
{
  // Configure your button bindings here
}

void RobotContainer::Drive()
{
  DriveDisplacement();

  mUltrasonic->doExecute();
}

void RobotContainer::Auto()
{

}