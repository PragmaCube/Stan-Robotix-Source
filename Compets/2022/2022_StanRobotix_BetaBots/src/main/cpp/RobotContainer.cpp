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

  mEjectorSpeed[0] = SubEjector::EjectorSpeed::eSlow;
  mEjectorSpeed[1] = SubEjector::EjectorSpeed::eFast;

  mEjector = new SubEjector;
  mAutoTimer.Reset();
  mMotorIndex = 1;  
  
  mClimber = new SubClimber;
  mHeight[0] = SubClimber::eHeight::h0;
  mHeight[1] = SubClimber::eHeight::h1;
  mHeight[2] = SubClimber::eHeight::h2;
  mHeight[3] = SubClimber::eHeight::h3;

  mImu = new SubIMU;
  mImu->Start();
  m_autonomousCommand.setSubsystem(mEjector, mDriveTrain, mClimber, mImu);

  ConfigureButtonBindings();
  
}

frc2::Command *RobotContainer::GetAutonomousCommand()
{
   return &m_autonomousCommand;
}

void RobotContainer::DriveDisplacement()
{
  if (mController.GetRightBumperPressed())
  {
    if (mMotorIndex < 2)
    {
      mMotorIndex++;
    }
  }

  if (mController.GetLeftBumperPressed())
  {
    if (mMotorIndex > 0)
    {
      mMotorIndex--;
    }
  }
 // std::cout << mMotorIndex << std::endl;

  mDriveTrain->MoveDrive(
      -mController.GetLeftY(),
      -mController.GetRightY(), mMotorSpeed[mMotorIndex]);
}

void RobotContainer::DriveEjector()
{
  int EjectorSpeed = -1;
  
  if (mController.GetXButton()){
    EjectorSpeed = 0;
  }
  if (mController.GetBButton()){
     EjectorSpeed = 1;  
  }

  if (EjectorSpeed != -1)
  {
     mEjector->SpeedChange(mEjectorSpeed[EjectorSpeed]);
  }
  
  mEjector->Periodic(mController.GetAButton());
}

void RobotContainer::ConfigureButtonBindings()
{
  // Configure your button bindings here
}

void RobotContainer::Drive()
{
  
  DriveClimber();

  DriveDisplacement();

  DriveEjector();
  mImu->Periodic();
  static int i = 0;

  if (i ++ % 500)
  {
    //std::cout<< "Angle :" << mImu->getAngle()<<std::endl;
  }
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

  if (mController.GetRightTriggerAxis() > 0.5)
  {
    mClimber->UpHold();
  }
  else if (mController.GetLeftTriggerAxis() > 0.5)
  {
    mClimber->DownHold();
  }

  if (mSmart)
  {
    mClimber->Periodic();
  }
}

void RobotContainer::Auto()
{

}