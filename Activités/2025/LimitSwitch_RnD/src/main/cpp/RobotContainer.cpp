// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>
#include <frc2/command/RunCommand.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  m_commandJoystick = new frc2::CommandJoystick{0};
  
  mLimit = new SubLimitSwitch(LimitSwitchs::Port1,LimitSwitchs::Port2);

  ConfigureBindings();

  mLimit->SetDefaultCommand(frc2::RunCommand(
    [this] {
  if (mLimit->getState(LimitSwitchs::Port1))
  {
      std::cout << "Limit 1 appuyée" << std::endl;
  }
  if (mLimit->getState(LimitSwitchs::Port2))
  {
      std::cout << "Limit 2 appuyée" << std::endl;
  }},{mLimit}));
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous

  return autos::ExampleAuto(&m_subsystem);
}