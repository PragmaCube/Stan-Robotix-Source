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

void RobotContainer::armInit()
{
  Arm.Init();
  frc::Shuffleboard::GetTab("Operator").AddDouble("X", [this]{return joystick.GetX();});
  frc::Shuffleboard::GetTab("Operator").AddDouble("Y", [this]{return joystick.GetY();});
  frc::Shuffleboard::GetTab("Operator").AddDouble("Z", [this]{return joystick.GetZ();});
  frc::Shuffleboard::GetTab("IMU").AddDouble("Rotation2d", [this]{return IMU.getRotation2D().Degrees().value();});
  
  
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

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}

void RobotContainer::drive() 
{
  driveTrain.mecanumDrive(joystick.GetX(), joystick.GetY(), joystick.GetZ(), IMU.getRotation2D());
  
  if (joystick.GetRawButtonPressed(1))
  {
    IMU.ResetAngle();
    
  }
}

void RobotContainer::oEjector()
{
  std::cout << joystick.GetRawButtonPressed(2) << std::endl;
  if (joystick.GetRawButton(2))
  {
    Ejector.On((-joystick.GetThrottle()+1)/2);
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