// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <iostream>

#include "RobotContainer.h"
#include "subsystems/SubArm.h"

#include <frc2/command/button/Trigger.h>

#include "RobotContainer.h"
#include "commands/Autos.h"
#include "commands/ExampleCommand.h"

/*-------------------------------------------------------------------------------------------*/

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here
//   // Configure the button bindings
//   driveTrain = new subDriveTrain;
   joystick = new frc::Joystick;

   ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  // Schedule `ExampleCommand` when `exampleCondition` changes to `true`
  frc2::Trigger([this] 
  {
    return joystick.GetPOV() == 180;
  }).OnTrue(Down(&mArm).ToPtr()); // A CONFIRMER

  frc2::Trigger([this] 
  {
    return joystick.GetPOV() == 0;
  }).OnTrue(Up(&mArm).ToPtr()); // A CONFIRMER

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(10);
  }).OnTrue(Rotation90DegresDroite(&mIMU, &mDriveTrain).ToPtr());
  
  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(9);
  }).OnTrue(Rotation90DegresGauche(&mIMU, &mDriveTrain).ToPtr());

  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  m_driverController.B().WhileTrue(m_subsystem.ExampleMethodCommand());
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}

void RobotContainer::ArmLimit()
{ 
    // if (joystick.GetPOV() == 0 && mArm->GetEncodeurPosition() > ArmConstants::kArmLimitDown)
    // {
    //   std::cout << "message" << std::endl;
    //   mArm->Down();
    // }
    
    // // Baisser bras
    // else if (joystick.GetPOV() == 180 && mArm->GetEncodeurPosition() < ArmConstants::kArmLimitUp)
    // {
    //   std::cout << "messageoui" << std::endl;
    //   mArm->Up();
    // }
}

void RobotContainer::drive() 
{
  mDriveTrain.mecanumDrive(mJoystick.GetX(), mJoystick.GetY(), mJoystick.GetZ(), mIMU.getRotation2d());
  
  if (mJoystick.GetRawButtonPressed(1))
  {
    mIMU.ResetAngle();
  }

  /*if (mJoystick.GetRawButtonPressed(6) == 1)
  {
    mDriveTrain.setVitesse(1);
  }

  if (mJoystick.GetRawButtonPressed(4) == 1)
  {
    mDriveTrain.setVitesse(2);
  }*/

  if (mJoystick.GetRawButtonPressed(4) == 1) 
  {
    switch(mDriveTrain.getVitesse())
    {
      case 1 :
        mDriveTrain.setVitesse(2);
        break;
      case 2 :
        mDriveTrain.setVitesse(1);
        break;
      default:
        mDriveTrain.setVitesse(2);
    }
  }
}


// typeDuReturn classe::fonction(parametres); -> parametres: Get...()