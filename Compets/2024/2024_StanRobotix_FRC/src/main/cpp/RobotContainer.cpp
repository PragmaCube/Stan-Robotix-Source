// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include "RobotContainer.h"

#include "Constants.h"
#include <frc2/command/button/Trigger.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  // Schedule `ExampleCommand` when `exampleCondition` changes to `true`
  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(5);
  }).OnTrue(GoToTag(&mDriveTrain).ToPtr());
  // frc2::Trigger([this] {
    // return SubDriveTrain.ExampleCondition();
  // }).OnTrue(GoToTag(&mDriveTrain).ToPtr());

  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  m_driverController.Button(1).OnTrue(GoToTag(&mDriveTrain).ToPtr());

}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}


void RobotContainer::Drive() 
{
  mDriveTrain.mecanumDrive(mJoystick.GetX(), mJoystick.GetY(), mJoystick.GetZ(), mIMU.getRotation2d());
  
  if (mJoystick.GetRawButtonPressed(1))
  {
    mIMU.ResetAngle();
  }
}