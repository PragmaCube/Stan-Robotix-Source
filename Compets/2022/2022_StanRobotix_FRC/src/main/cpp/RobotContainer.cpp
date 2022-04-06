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

  mElevator = new SubElevator;
  mLaunchSystem = new LaunchSystem;

  // Configure the button bindings

  ConfigureButtonBindings();

  isCollecting = false;
  isLaunching = false;

  mCamera.SetResolution(852, 480);
  mCamera.SetFPS(20);
  frc::CameraServer::StartAutomaticCapture(mCamera);
  frc::CameraServer::StartAutomaticCapture();

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
        - mController.GetLeftY(),
        mController.GetRightY(), mMotorSpeed[mMotorIndex]);
  

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

  if(mController.GetRightBumper())
  {
    mElevator->Up(SubElevator::eRightClimber);
  }
  else if(mController.GetRightTriggerAxis() >= 0.5)
  {
    mElevator->Down(SubElevator::eRightClimber);
  }
  else
  {
    mElevator->Stop(SubElevator::eRightClimber);

  }

  if(mController.GetLeftBumper())
  {
    mElevator->Up(SubElevator::eLeftClimber);
  } 
  else if(mController.GetLeftTriggerAxis() >= 0.5)
  {
    mElevator->Down(SubElevator::eLeftClimber);
  }
  else
  {
    mElevator->Stop(SubElevator::eLeftClimber);
  }

  std::cout << "L-Encoder Value : " << mElevator->GetEncoderPosition(SubElevator::eLeftEncoder) << std::endl;
  std::cout << "R-Encoder Value : " << mElevator->GetEncoderPosition(SubElevator::eRightEncoder) << std::endl;

  std::cout << "R Up condition" << (mElevator->GetEncoderPosition(SubElevator::Encoder::eRightEncoder) < kMaxHeight) << std::endl;
  std::cout << "L Up condition" << (mElevator->GetEncoderPosition(SubElevator::Encoder::eRightEncoder) < kMaxHeight) << std::endl;

  std::cout << "R Down condition : " << (mElevator->GetEncoderPosition(SubElevator::Encoder::eRightEncoder) > kMinHeight) << std::endl;
  std::cout << "L Down condition : " << (mElevator->GetEncoderPosition(SubElevator::Encoder::eRightEncoder) > kMinHeight) << std::endl;

}