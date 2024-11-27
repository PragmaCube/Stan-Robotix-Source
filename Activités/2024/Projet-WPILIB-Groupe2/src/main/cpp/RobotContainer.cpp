// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"
#include <frc2/command/RunCommand.h>


RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  mIMU = new SubIMU;
  mIMU->ResetAngle();
  mSub = new SubDriveTrain;

    mSub->SetDefaultCommand(frc2::RunCommand(
       [this] {
         mSub->drive(joystick.GetX(), joystick.GetY(), joystick.GetZ(), mIMU->getRotation2d());
        },
        {mSub}));
  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  // Schedule `ExampleCommand` when `exampleCondition` changes to `true`
  frc2::Trigger([this] {
    return m_subsystem.ExampleCondition();
  }).OnTrue(ExampleCommand(&m_subsystem).ToPtr());

  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  m_driverController.B().WhileTrue(m_subsystem.ExampleMethodCommand());
}

void RobotContainer::drive(){
   mSub->drive(
     joystick.GetX(), joystick.GetY(), joystick.GetZ(), mIMU->getRotation2d()
   );
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}
