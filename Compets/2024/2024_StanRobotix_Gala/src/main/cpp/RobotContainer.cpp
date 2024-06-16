// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

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
    return m_subsystem.ExampleCondition();
  }).OnTrue(ExampleCommand(&m_subsystem).ToPtr());
}

void RobotContainer::setLED()
{
  if (m_driverController.GetRawButtonPressed(1) || mLED.isMoving)
  { 
    mLED.setMode(mLED.moving);
  }
  if (m_driverController.GetRawButtonPressed(2) || mLED.isGiving)
  {
    if (timer == 3)
    {
      mLED.setMode(mLED.giving);
      timer = 0;
    }
    else
    {
      timer++;
    }
  }
  if (m_driverController.GetRawButtonPressed(3))
  {
    mLED.setMode(mLED.taking);
  }
  if (m_driverController.GetRawButtonPressed(4))
  {
    mLED.setMode(mLED.immobile);
  }
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}
