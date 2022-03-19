// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  mElevator = new SubElevator;
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}

void RobotContainer::Drive()
{
  mSubDriveTrain->TankDrive(
        - mController.GetY(frc::GenericHID::JoystickHand::kLeftHand),
        - mController.GetY(frc::GenericHID::JoystickHand::kRightHand));
  std::cout << mController.GetY(frc::GenericHID::JoystickHand::kLeftHand) << std:: endl << mController.GetY(frc::GenericHID::JoystickHand::kLeftHand) << std::endl;
  
  if(mController.GetYButton())
  {
    mElevator->Up();
  }
  
  else if(mController.GetXButton())
  {
    mElevator->Down();
  }
  
  else
  {
    mElevator->Stop();
  }
}