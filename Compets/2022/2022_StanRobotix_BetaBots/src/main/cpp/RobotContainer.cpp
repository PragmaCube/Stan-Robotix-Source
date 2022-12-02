// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  mClimber = new SubClimber;
  mHeight[0] = SubClimber::Height::h1;
  mHeight[1] = SubClimber::Height::h2;
  mHeight[2] = SubClimber::Height::h3;
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}

void RobotContainer::Drive()
{/* voir plus tard
  if (mController.GetPOV() == 0)
  {
    mClimber->Stage(mHeight[0]);
  }
  else if (mController.GetPOV() == 90)
  {
    mClimber->Stage(mHeight[1]);
  }
  else if (mController.GetPOV() == 180)
  {
    mClimber->Stage(mHeight[2]);
  }
  else if (mController.GetPOV() == 270)
  {
    mClimber->Down();
  }*/
  

  if(mController.GetRightTriggerAxis()>0.5)
  {
    mClimber->UpHold();
  } 
  else if(mController.GetRightTriggerAxis()>0.5)
  {
    mClimber->DownHold();
  }
  else
  {
    mClimber->Stop();
  }
}