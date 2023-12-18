// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include <iostream>

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>
//#include "commands/oui.h"
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
  frc2::Trigger([this] {
    return joystick.GetRawButton(7);
  }).OnTrue(GoToTag(&driveTrain).ToPtr());

  /*frc2::Trigger([this] {
    return joystick.GetRawButton(6);
  }).OnTrue(oui().ToPtr());*/

  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  // m_driverController.B().WhileTrue(m_subsystem.ExampleMethodCommand());
  // frc::Shuffleboard::
}

// frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
//   // An example command will be run in autonomous
//   return Autos::ExampleAuto(&m_subsystem);
// }

void RobotContainer::drive() 
{
  driveTrain.mecanumDrive(joystick.GetX(), -joystick.GetY(), -joystick.GetZ(), IMU.getRotation2D());
  if (joystick.GetRawButtonPressed(8))
  {
    IMU.ResetAngle();
  }
}

void RobotContainer::oEjector()
{
  if (joystick.GetRawButtonPressed(6))
  {
    isArmForward = false;
    std::cout << "forward" << std::endl;  
  }
  else if (joystick.GetRawButtonPressed(4))
  {
    isArmForward = true;
    std::cout << "backward" << std::endl;
  }

  if (joystick.GetRawButton(1))
  {
    if (isArmForward)
    {
      Ejector.On(-(joystick.GetThrottle()-1)/2);
    }
    else
    {
      Ejector.On((joystick.GetThrottle()-1)/2);
    }
  }
  else
  {
    Ejector.Off();
  }
}

void RobotContainer::oArm()
{
  if (joystick.GetRawButtonPressed(5))
  {
    Arm.PosUp();
  }
  if (joystick.GetRawButtonPressed(3))
  {
    Arm.PosDown();
  }
}


// typeDuReturn classe::fonction(parametres); -> parametres: Get...()