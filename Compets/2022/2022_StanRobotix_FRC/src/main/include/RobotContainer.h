// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>

#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */

#include <frc/XboxController.h>

#include "subsystems/DriveTrain.h"

#include "subsystems/LaunchSystem.h"

class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

  void Drive();

 private:
  // The robot's subsystems and commands are defined here...
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;

  frc::XboxController mController{0};

  SubDriveTrain* mSubDriveTrain;
  SubDriveTrain::MotorSpeed mMotorSpeed[3];
  LaunchSystem::LauncherSpeed mLauncherSpeed[2];
  int mMotorIndex;
  int mLauncherIndex;

  void ConfigureButtonBindings();

  LaunchSystem mLaunchSystem;  
};
