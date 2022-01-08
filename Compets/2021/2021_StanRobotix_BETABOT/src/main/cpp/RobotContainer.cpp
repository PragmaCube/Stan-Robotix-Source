// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <iostream>

#include "RobotContainer.h"

#include <frc2/command/button/JoystickButton.h>
#include "commands/MoveStraightXSeconds.h"


RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here
  mSubDriveTrain = new SubDriveTrain;
  mPiston = new SubSolenoid;
  mPulley = new SubPulley;
  mUnder10Inch = new under_10_inch(mSubDriveTrain);

  mAuto = new MoveStraightXSeconds(mSubDriveTrain);

  mMotorSpeed[0] = SubDriveTrain::MotorSpeed::eSlow;
  mMotorSpeed[1] = SubDriveTrain::MotorSpeed::eMedium;
  mMotorSpeed[2] = SubDriveTrain::MotorSpeed::eFast;
  mDriveMode = SubDriveTrain::DriveMode::eTankDrive;
  mDriveController = SubDriveTrain::DriveController::eXBox;
  mMotorIndex = 0;

  // Configure the button bindings
  ConfigureButtonBindings();
  mIMU.Init();

  mPiston->SetInactive();
  mSubDriveTrain->SetInactive();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  //frc2::JoystickButton(&mController, 6).WhenPressed(PistonPulse(mPiston, false));
 // frc2::JoystickButton(&mController, 1).WhenPressed(&MoveStraightXSeconds(mSubDriveTrain).WithTimeout(2.0_s));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  //return &m_autonomousCommand;
  return mUnder10Inch;
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

  if(mController.GetBumperPressed(frc::GenericHID::JoystickHand::kRightHand))
  {
    mPiston->SwitchPistonState();
  }

  if(mController.GetYButton())
  {
    mPulley->Up();
  }

  else if(mController.GetXButton())
  {
    mPulley->Down();
  }
  
  else
  {
    mPulley->setInactive();
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

  std::cout << mController.GetY(frc::GenericHID::JoystickHand::kLeftHand) << std:: endl << mController.GetY(frc::GenericHID::JoystickHand::kLeftHand) << std::endl;
}

void RobotContainer::Auto()
{
  mSubDriveTrain->TankDrive(1, 0.75, SubDriveTrain::MotorSpeed::eFast);
}

double RobotContainer::acceleroGetX()
{
  return mIMU.getXAccel();
}
double RobotContainer::acceleroGetY()
{
  return mIMU.getYAccel();
}

double RobotContainer::getZTurning()
{
  return mIMU.getZTurningValue();
}