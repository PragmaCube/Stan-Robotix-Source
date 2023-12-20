// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.


#include "RobotContainer.h"
#include "Constants.h"
#include <frc2/command/button/Trigger.h>
#include "commands/Autos.h"
#include "commands/ExampleCommand.h"
#include <iostream>

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
 /* if (joystick.GetRawButtonPressed(1))
  {
    if ( m_SubEjector.GetMoveState() == true)
    {
      m_SubEjector.Set(SubEjector::eForwards, joystick.GetThrottle());
    }

    if ( m_SubEjector.GetMoveState() == false)
    {
      m_SubEjector.Set(SubEjector::eBackwards, joystick.GetThrottle());
    }
  }
  else
  {
      m_SubEjector.Set(SubEjector::eStop, 0);
  }*/
/////////////////////////////////////////////////////////
  if (joystick.GetRawButtonPressed(1))
  {
     m_SubEjector.SetRoll((m_SubEjector.GetRoll() +1) %3);
  }

  switch (m_SubEjector.GetRoll())
    {
    case 0:
      m_SubEjector.Set(SubEjector::eStop, (joystick.GetThrottle()-1)/2);
      
      break;
    case 1:
      m_SubEjector.Set(SubEjector::eForwards, (joystick.GetThrottle()-1)/2);
      
      break;
    case 2:
      m_SubEjector.Set(SubEjector::eBackwards, (joystick.GetThrottle()-1)/2);
      
      break;
    default:
      m_SubEjector.Set(SubEjector::eStop, (joystick.GetThrottle()-1)/2);
      
      break;
      
    }
  
}

  
