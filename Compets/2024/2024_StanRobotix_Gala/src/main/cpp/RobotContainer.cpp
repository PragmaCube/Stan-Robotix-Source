// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/Autos.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
}

void RobotContainer::Drive(){
  float Sensi = 0.01;

  float X = 0;
  float Y = 0;
  float Z = 0;

  if (mJoystick.GetX() >= 0){
    X = mJoystick.GetX()*mJoystick.GetX();
  }
  else{
    X = -mJoystick.GetX()*mJoystick.GetX();
  }
  if (mJoystick.GetY() >= 0){
    Y = mJoystick.GetY()*mJoystick.GetY();
  }
  else{
    Y = -mJoystick.GetY()*mJoystick.GetY();
  }
  if (mJoystick.GetZ() >= 0){
    Z = mJoystick.GetZ()*mJoystick.GetZ();
  }
  else{
    Z = -mJoystick.GetZ()*mJoystick.GetZ();
  }

  mSwerve.Move(X, Y, Z);
}
