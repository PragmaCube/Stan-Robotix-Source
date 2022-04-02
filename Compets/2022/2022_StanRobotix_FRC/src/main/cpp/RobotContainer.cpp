// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <iostream>
#include <cameraserver/CameraServer.h>

#include "RobotContainer.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {

  // Initialize all of your commands and subsystems here

  mSubDriveTrain = new SubDriveTrain;
  mMotorSpeed[0] = SubDriveTrain::MotorSpeed::eSlow;
  mMotorSpeed[1] = SubDriveTrain::MotorSpeed::eMedium;
  mMotorSpeed[2] = SubDriveTrain::MotorSpeed::eFast;
  mLauncherSpeed[0] = LaunchSystem::LauncherSpeed::eSlow;
  mLauncherSpeed[1] = LaunchSystem::LauncherSpeed::eFast;
  mMotorIndex = 1;
  mLauncherIndex = 1;
  // Configure the button bindings
  mElevator = new SubElevator;
  mLaunchSystem = new LaunchSystem;
  ConfigureButtonBindings();

  isCollecting = false;
  isLaunching = false;

  frc::CameraServer* mCamera = frc::CameraServer::GetInstance();
  mCamera->StartAutomaticCapture();
  mCamera->PutVideo("Video In", 720, 480);

}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}

void RobotContainer::Drive()
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
  

  if (mController.GetPOV() == 90)
  {
    mLauncherIndex = 0;
  }
  if (mController.GetPOV() == 270)
  {
    mLauncherIndex = 1;
  }

  mSubDriveTrain->TankDrive(
        - mController.GetY(frc::GenericHID::JoystickHand::kLeftHand),
        - mController.GetY(frc::GenericHID::JoystickHand::kRightHand), mMotorSpeed[mMotorIndex]);
  

  if(mController.GetAButtonPressed())
  {
    if(isLaunching)
    {
      isLaunching = false;
    }
    else
    {
      isLaunching = true;
    }
  }

  if(isLaunching)
  {
    mLaunchSystem->Launch();
  }
  else
  {
    mLaunchSystem->LaunchStop();
  }


  if(mController.GetBButtonPressed())
  {
    if(isCollecting)
    {
      isCollecting = false;
    }
    else
    {
      isCollecting = true;
    }    
  }

  if(isCollecting)
  {
    mLaunchSystem->Collect();
  }
  else if(mController.GetYButton())
  {
    mLaunchSystem->CollectReverse();
  }
  else
  {
    mLaunchSystem->CollectStop();
  }

  if(mController.GetBumper(frc::GenericHID::JoystickHand::kRightHand))
  {
    mElevator->Up(SubElevator::eRightClimber);
  }
  else if(mController.GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand) >= 0.5)
  {
    mElevator->Down(SubElevator::eRightClimber);
  }
  else
  {
    mElevator->Stop(SubElevator::eRightClimber);

  }

  if(mController.GetBumper(frc::GenericHID::JoystickHand::kLeftHand))
  {
    mElevator->Up(SubElevator::eLeftClimber);
  } 
  else if(mController.GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand) >= 0.5)
  {
    mElevator->Down(SubElevator::eLeftClimber);
  }
  else
  {
    mElevator->Stop(SubElevator::eLeftClimber);
  }

}