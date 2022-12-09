// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <iostream>

RobotContainer::RobotContainer()
{
  mDriveTrain = new SubDriveTrain;
  // Initialize all of your commands and subsystems here
  frc::CameraServer::StartAutomaticCapture();

  mMotorSpeed[0] = SubDriveTrain::MotorSpeed::eSlow;
  mMotorSpeed[1] = SubDriveTrain::MotorSpeed::eMedium;
  mMotorSpeed[2] = SubDriveTrain::MotorSpeed::eFast;

  mEjector = new SubEjector;
  mAutoTimer.Reset();
  mMotorIndex = 1;  
  
  mClimber = new SubClimber;
  mHeight[0] = SubClimber::Height::h0;
  mHeight[1] = SubClimber::Height::h1;
  mHeight[2] = SubClimber::Height::h2;
  mHeight[3] = SubClimber::Height::h3;

  m_autonomousCommand.setSubsystem(mEjector, mDriveTrain, mClimber);

  ConfigureButtonBindings();
  
}

frc2::Command *RobotContainer::GetAutonomousCommand()
{
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
  std::cout << mMotorIndex << std::endl;

  mDriveTrain->TankDrive(
      -mController.GetLeftY(),
      -mController.GetRightY(), mMotorSpeed[mMotorIndex]);
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
    if (mAutoTimer.Get().value() <= 0.5)
    {
      mEjector->Push();
    }
    else if (mAutoTimer.Get().value() <= 1.65)
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

void RobotContainer::ConfigureButtonBindings()
{
  // Configure your button bindings here
}

void RobotContainer::Drive()
{
  DriveClimber();

  //DriveDisplacement();

  //DriveEjector();

}
void RobotContainer::DriveClimber()
{ 
   frc::SmartDashboard::PutBoolean("smart",mSmart);
   frc::SmartDashboard::PutNumber("POV",mController.GetPOV());
   if (mController.GetPOV() == 0)
   {
     mSmart = 1;
     mClimber->Stage(mHeight[3]);
   }
   else if (mController.GetPOV() == 90)
   {
     mSmart = 1;
     mClimber->Stage(mHeight[1]);
   }
   else if (mController.GetPOV() == 180)
   {
     mSmart = 1;
     mClimber->Stage(mHeight[0]);
   }
   else if (mController.GetPOV() == 270)
   {
     mSmart = 1;
     mClimber->Stage(mHeight[2]);
   }

   
  //std::cout<<mClimber->GetEncoderPosition();
/*
  if (mController.GetRightTriggerAxis() > 0.5)
  {
    mSmart = 0;
    mClimber->UpHold();
  }
  else if (mController.GetLeftTriggerAxis() > 0.5)
  {
    mSmart = 0;
    mClimber->DownHold();
  }
  else
  {
    mClimber->Stop();
  }*/

  if (mSmart)
  {
    mClimber->Periodic();
  }
}