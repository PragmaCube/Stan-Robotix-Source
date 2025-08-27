// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>
#include <frc2/command/RunCommand.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"
#include "commands/AlgaePivotDown.h"
#include "commands/AlgaePivotUp.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  m_commandJoystick = new frc2::CommandJoystick{0};

  mSubAlgaePivot = new SubAlgaePivot;

  mSubAlgaePivot->SetDefaultCommand(frc2::RunCommand(
    [this] {
      mSubAlgaePivot->CounterGravity();
    },
    {mSubAlgaePivot}));

  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
  m_commandJoystick->Button(JoystickBindingsConstants::Algae::kPivotUp).OnTrue(AlgaePivotUp(mSubAlgaePivot).ToPtr());
  m_commandJoystick->Button(JoystickBindingsConstants::Algae::kPivotDown).OnTrue(AlgaePivotDown(mSubAlgaePivot).ToPtr());  

  m_commandJoystick->Button(JoystickBindingsConstants::Algae::kDynamicForward).WhileTrue(mSubAlgaePivot->SysIdDynamic(frc2::sysid::Direction::kForward));
  m_commandJoystick->Button(JoystickBindingsConstants::Algae::kDynamicReverse).WhileTrue(mSubAlgaePivot->SysIdDynamic(frc2::sysid::Direction::kReverse));
  m_commandJoystick->Button(JoystickBindingsConstants::Algae::kQuasistaticForward).WhileTrue(mSubAlgaePivot->SysIdQuasistatic(frc2::sysid::Direction::kForward));
  m_commandJoystick->Button(JoystickBindingsConstants::Algae::kQuasistaticReverse).WhileTrue(mSubAlgaePivot->SysIdQuasistatic(frc2::sysid::Direction::kReverse));
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}