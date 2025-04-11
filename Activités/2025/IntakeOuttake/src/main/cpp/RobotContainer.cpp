// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"
#include "commands/Intake.h"
#include "commands/Outtake.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here
  mIntake = new SubIntake{};
  mJoystick = new frc::GenericHID{0};
  mButton1 = new frc2::JoystickButton{mJoystick, 1};
  mButton2 = new frc2::JoystickButton{mJoystick, 2};

  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  // Schedule `ExampleCommand` when `exampleCondition` changes to `true`
  frc2::Trigger([this] {
    return m_subsystem.ExampleCondition();
  }).OnTrue(ExampleCommand(&m_subsystem).ToPtr());

  frc2::Trigger([this] {
    return mButton1->Get();
  }).OnTrue(Intake(mIntake, mButton1).ToPtr());

  frc2::Trigger([this] {
    return mButton2->Get();
  }).OnTrue(Outtake(mIntake, mButton2).ToPtr());
  
  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  m_driverController.B().WhileTrue(m_subsystem.ExampleMethodCommand());
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}
