// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <iostream>

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  mDriveTrain = new DriveTrain;
  // Initialize all of your commands and subsystems here
  frc::CameraServer::StartAutomaticCapture();

  mMotorSpeed[0] = DriveTrain::MotorSpeed::eSlow;
  mMotorSpeed[1] = DriveTrain::MotorSpeed::eMedium;
  mMotorSpeed[2] = DriveTrain::MotorSpeed::eFast;
  mEjector = new Ejector;
  // mAutoTimer.Start();
  mAutoTimer.Reset();
  mMotorIndex = 1;
  ConfigureButtonBindings();
  // Configure the button bindings
  mClimber = new SubClimber;
  mHeight[0] = SubClimber::Height::h1;
  mHeight[1] = SubClimber::Height::h2;
  mHeight[2] = SubClimber::Height::h3;
  ConfigureButtonBindings();
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}


void RobotContainer::DriveDisplacement()
{
   if (mController.GetPOV() == 0)
  {
    if (mMotorIndex < 2)
    {
      mMotorIndex++;
    }
  }

  if (mController.GetPOV() == 180)
  {
    if (mMotorIndex > 0)
    {
      mMotorIndex--;
    }
  }
  std::cout<<mMotorIndex<<std::endl;

  mDriveTrain->TankDrive(
        - mController.GetLeftY(),
        - mController.GetRightY(), mMotorSpeed[mMotorIndex]);
}

void RobotContainer::DriveEjector()
{
if (mController.GetAButton() && !ejector_in_use)
  {
    ejector_in_use = true;
    mAutoTimer.Start();
    std::cout << "Pressed A Button" << std::endl;
  }

  std::cout << mAutoTimer.Get().value() << std::endl;

  if (ejector_in_use)
  {
    if (mAutoTimer.Get().value()<=0.5)
    {
      mEjector->Push();
    }
    else if (mAutoTimer.Get().value()<=1.65) 
    {
      mEjector->Pull();
    }
    else
    {
      mEjector->Stop();
      ejector_in_use = false;
      mAutoTimer.Stop();
      mAutoTimer.Reset();
    }
  }
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

void RobotContainer::Drive()
{
  DriveClimber();

  DriveDisplacement();

  DriveEjector();
}
void RobotContainer::DriveClimber()
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