// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <iostream>

#include "RobotContainer.h"

#include <frc2/command/button/JoystickButton.h>

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here
  mSubDriveTrain = new SubDriveTrain;
  mPiston = new SubSolenoid;
  mPulley = new SubPulley;

  mMotorSpeed[0] = SubDriveTrain::MotorSpeed::eSlow;
  mMotorSpeed[1] = SubDriveTrain::MotorSpeed::eMedium;
  mMotorSpeed[2] = SubDriveTrain::MotorSpeed::eFast;
  mDriveMode = SubDriveTrain::DriveMode::eTankDrive;
  mDriveController = SubDriveTrain::DriveController::eXBox;
  mMotorIndex = 0;

  // Configure the button bindings
  ConfigureButtonBindings();

  mPiston->SetInactive();
  //mPiston->SwitchCompressorState();
  mSubDriveTrain->SetInactive();

  mAutoTimer.Start();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}

void RobotContainer::HandlePOV()
{
  ////////////////////
  // 0 = haut, 90 = droite, 180 = bas, 270 = gauche
  // Haut / bas = vitesse
  // Droite / gauche = mode de conduite
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
  ////////////////////
}

void RobotContainer::Drive()
{

  ////////////////////
  // Mapper le controlleur
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
  ////////////////////
  
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

void RobotContainer::Auto(Side iSide)
{
  /*
    Avance - Tourne à droite - Avance - Tourne à droite - Avance - Actionne le piston (mettre un cylindre)
  */

  switch(iSide)
  {
    case Side::eRight:

    if(mAutoTimer.Get() <= 1.3)
    {
      mSubDriveTrain->TankDrive(0.5, 0.5, SubDriveTrain::MotorSpeed::eFast);
    }

    else if(mAutoTimer.Get() >= 1.7 && mAutoTimer.Get() <= 2.1)
    {
      mSubDriveTrain->TankDrive(1, -1, SubDriveTrain::MotorSpeed::eFast);
    }

    else if(mAutoTimer.Get() >= 4.5 && mAutoTimer.Get() <= 7)
    {
      mSubDriveTrain->TankDrive(0.5, 0.5, SubDriveTrain::MotorSpeed::eFast);
    }

    else if(mAutoTimer.Get() >= 7 && mAutoTimer.Get() <= 7.62)
    {
      mSubDriveTrain->TankDrive(1, -1, SubDriveTrain::MotorSpeed::eFast);
    }

    else if(mAutoTimer.Get() >= 8 && mAutoTimer.Get() <= 8.9)
    {
      mSubDriveTrain->TankDrive(0.5, 0.5, SubDriveTrain::MotorSpeed::eFast);
    }

    else if(mAutoTimer.Get() >= 10 && mAutoTimer.Get() <= 13)
    {
      if(mAutoCompressor)
      {
        mPiston->SwitchCompressorState();
        mAutoCompressor = false;
      }

      mPulley->Up();
    }

    else if(mAutoTimer.Get() >= 13)
    {
      if(!mAutoPulley)
      {
        mPulley->setInactive();
        mAutoPulley = true;
      }
      
    }

    break;

    case Side::eLeft:
    if(mAutoTimer.Get() <= 1.3)
    {
      mSubDriveTrain->TankDrive(0.5, 0.5, SubDriveTrain::MotorSpeed::eFast);
    }

    else if(mAutoTimer.Get() >= 1.7 && mAutoTimer.Get() <= 2.1)
    {
      mSubDriveTrain->TankDrive(-1, 1, SubDriveTrain::MotorSpeed::eFast);
    }

    else if(mAutoTimer.Get() >= 4.5 && mAutoTimer.Get() <= 6.9)
    {
      mSubDriveTrain->TankDrive(0.5, 0.5, SubDriveTrain::MotorSpeed::eFast);
    }

    else if(mAutoTimer.Get() >= 6.9 && mAutoTimer.Get() <= 7.6)
    {
      mSubDriveTrain->TankDrive(- 1, 1, SubDriveTrain::MotorSpeed::eFast);
    }

    else if(mAutoTimer.Get() >= 8 && mAutoTimer.Get() <= 9.1)
    {
      mSubDriveTrain->TankDrive(0.5, 0.5, SubDriveTrain::MotorSpeed::eFast);
    }

    else if(mAutoTimer.Get() >= 10 && mAutoTimer.Get() <= 13)
    {
      if(mAutoCompressor)
      {
        mPiston->SwitchCompressorState();
        mAutoCompressor = false;
      }

      mPulley->Up();
    }

    else if(mAutoTimer.Get() >= 13)
    {
      if(!mAutoPulley)
      {
        mPulley->setInactive();
        mAutoPulley = true;
      }
      
    }

    break;

    case Side::eForward:
    // Avance tout droit

    if(mAutoTimer.Get() <= 3)
    {
      mSubDriveTrain->TankDrive(0.5, 0.5, SubDriveTrain::MotorSpeed::eFast);
    }

    break;
  }

  
}

void RobotContainer::ResetAuto()
{
  // Pas utilisé
  // Réinitialise la période autonome
  mAutoTimer.Reset();
}