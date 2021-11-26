// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <iostream>

#include "RobotContainer.h"

#include <frc2/command/button/JoystickButton.h>

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here

  mSubDriveTrain = new SubDriveTrain;
  mMotorSpeed[0] = SubDriveTrain::MotorSpeed::eSlow;
  mMotorSpeed[1] = SubDriveTrain::MotorSpeed::eMedium;
  mMotorSpeed[2] = SubDriveTrain::MotorSpeed::eFast;
  mDriveMode = SubDriveTrain::DriveMode::eTankDrive;
  mDriveController = SubDriveTrain::DriveController::eXBox;
  mMotorIndex = 1;

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  frc2::JoystickButton(&mController, 6).WhenPressed(PistonPulse(mPiston, false));
  
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}

void RobotContainer::HandlePOV()
{
  switch (mController.GetPOV())
  {
  case 0:
    if (mMotorIndex < 2)
    {
      mMotorIndex++;
    }

    break;

  case 90:
    mDriveMode = SubDriveTrain::DriveMode::eArcadeDrive;

    break;

  case 180:
    if (mMotorIndex > 0)
    {
      mMotorIndex--;
    }

    break;

  case 270:
    mDriveMode = SubDriveTrain::DriveMode::eTankDrive;

    break;
  }
}

void RobotContainer::Drive()
{
  if(mDriveController == SubDriveTrain::DriveController::eXBox)
  {
    HandlePOV();
  }

  if(mController.GetBumperPressed(frc::GenericHID::JoystickHand::kLeftHand))
  {
    mPiston->SwitchCompressorState();
  }

  switch (mDriveMode)
  {
  case SubDriveTrain::DriveMode::eTankDrive:
    mSubDriveTrain->TankDrive(
        - mController.GetY(frc::GenericHID::JoystickHand::kLeftHand),
        - mController.GetY(frc::GenericHID::JoystickHand::kRightHand), mMotorSpeed[mMotorIndex]);
    break;
  
  case SubDriveTrain::DriveMode::eArcadeDrive:
    if(mDriveController == SubDriveTrain::DriveController::eJoystick)
    {
      mSubDriveTrain->ArcadeDrive(
           - mJoystick.GetY(),
          mJoystick.GetZ(), mMotorSpeed[mMotorIndex]);
    }

    else
    {
      mSubDriveTrain->ArcadeDrive(
           - mController.GetY(frc::GenericHID::JoystickHand::kRightHand),
          mController.GetX(frc::GenericHID::JoystickHand::kRightHand), mMotorSpeed[mMotorIndex]);
    }
    
    break;
  }
}