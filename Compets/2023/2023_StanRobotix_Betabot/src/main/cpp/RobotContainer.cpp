// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"

// RobotContainer::RobotContainer() {
//   // Initialize all of your commands and subsystems here
//   // Configure the button bindings
//   driveTrain = new subDriveTrain;
  // joystick = new frc::Joystick;

//   ConfigureBindings();
// }

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

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}

void RobotContainer::drive() 
{
  driveTrain.mecanumDrive(joystick.GetX(), joystick.GetY(), joystick.GetZ(), IMU.getRotation2d());
  
  if (joystick.GetRawButtonPressed(1))
  {
    IMU.ResetAngle();
  }

  /*if (joystick.GetRawButtonPressed(6) == 1)
  {
    driveTrain.setVitesse(1);
  }

  if (joystick.GetRawButtonPressed(4) == 1)
  {
    driveTrain.setVitesse(2);
  }*/

  if (joystick.GetRawButtonPressed(4) == 1) 
  {
    switch(driveTrain.getVitesse())
    {
      case 1 :
        driveTrain.setVitesse(2);
        break;
      case 2 :
        driveTrain.setVitesse(1);
        break;
      default:
        driveTrain.setVitesse(2);
    }
  }
}



// typeDuReturn classe::fonction(parametres); -> parametres: Get...()