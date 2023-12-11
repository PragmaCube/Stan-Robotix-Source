// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.


#include "RobotContainer.h"
#include "Constants.h"
#include <frc2/command/button/Trigger.h>
#include "commands/Autos.h"
#include "commands/ExampleCommand.h"

RobotContainer::RobotContainer() {


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

}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}
void RobotContainer::Drive()
{


  if (joystick.GetRawButtonPressed(1))
  {
    if ( m_SubEjector.GetMoveState() == SubEjector::eForwards)
    {
      mMotorElevator.Set(EjectorConstants::kSpeedPush*m_SubEjector.GetSpeedCoefficient());
    }

    if ( m_SubEjector.GetMoveState() == SubEjector::eBackwards)
    {
      mMotorElevator.Set(EjectorConstants::kSpeedPush*-m_SubEjector.GetSpeedCoefficient());
    }
  }
  else
  {
    mMotorElevator.Set(0);
  }



  if (joystick.GetRawButtonPressed(3))
  {
    m_SubEjector.SetMoveState(SubEjector::eForwards);
  }   
  
  if (joystick.GetRawButtonPressed(4))
  {
    m_SubEjector.SetMoveState(SubEjector::eBackwards);
  }

}
