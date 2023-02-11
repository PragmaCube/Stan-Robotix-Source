// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <iostream>

RobotContainer::RobotContainer()
{
   mDriveTrain = new SubDriveTrain;

  //sSubIMU::getInstance()->Enable();

  m_autonomousCommand.setSubsystem(mDriveTrain);

    mUltrasonic = new SubUltrasonic;
    mUltrasonic->EnableImperialSystem();
    mUltrasonic -> EnablePerformanceLog(kLogPerf_UltrasonEnable);

    SubIMU::getInstance()->EnableSubsystemLog(kLogIMU);
    SubIMU::getInstance()->EnablePerformanceLog(kLogPerf_ImuEnable);
   	
    ConfigureButtonBindings();
    
}

frc2::Command *RobotContainer::GetAutonomousCommand()
{
   return &m_autonomousCommand;
}

void RobotContainer::DriveDisplacement()
{
  const double slider = (1-mJoystick.GetThrottle())/2;
  mDriveTrain->MoveMeca(mJoystick.GetX()*slider, mJoystick.GetY()*slider, mJoystick.GetTwist()*slider, 1-mJoystick.GetRawButton(1));
  if(mJoystick.GetRawButtonPressed(2))
  {
    SubIMU::getInstance()->ResetYaw();
  }
}

void RobotContainer::ConfigureButtonBindings()
{
  // Configure your button bindings here
}

void RobotContainer::Drive()
{
  DriveDisplacement();

  mUltrasonic->Execute();
  
  SubIMU::getInstance()->Execute();

}

void RobotContainer::Auto()
{

}