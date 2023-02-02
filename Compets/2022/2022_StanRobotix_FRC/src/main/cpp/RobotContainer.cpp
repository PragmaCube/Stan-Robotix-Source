// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <iostream>
#include <cameraserver/CameraServer.h>

#include "RobotContainer.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {

  // Initialize all of your commands and subsystems here

  mSubDriveTrain = new SubDriveTrain;

  mLaunch = true;
  mShoot = true;

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
  mAutoTimer.Start();

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
}

void RobotContainer::Auto()
  {
  /* Avance 2s - Stop - Activer Lanceur */

    if(mShoot)
    {
       mLaunchSystem->Launch();
       mShoot = false;
    }

    if(mAutoTimer.Get().value() <= 1.4)
    {
      mSubDriveTrain->TankDrive(-0.6, 0.6, SubDriveTrain::MotorSpeed::eFast);
    }    

    else if(mAutoTimer.Get().value() >= 2 && mAutoTimer.Get().value() <= 4)
    {
      mSubDriveTrain->SetInactive();

      if(mLaunch)
      {
        mLaunchSystem->Collect();
        mLaunch = false;
      }
      
    }
  
  else if(mAutoTimer.Get().value() >= 4 && mAutoTimer.Get().value() <= 5.2)
  {
    mLaunchSystem->LaunchStop();
    mLaunchSystem->CollectStop();
    mSubDriveTrain->TankDrive(-0.6, 0.6, SubDriveTrain::MotorSpeed::eFast);
  }

  else
  {
    mSubDriveTrain->SetInactive();
  }
    
}

  void RobotContainer::ResetAuto()
  {
    mAutoTimer.Reset();
    mShoot = true;
    mLaunch = true;
  }