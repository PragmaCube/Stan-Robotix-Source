// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>

#include <frc/XboxController.h>
#include <frc/Joystick.h>

#include <frc/Timer.h>

#include "subsystems/DriveTrain.h"
#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();
  enum Side { eLeft, eRight, eForward };

  frc2::Command* GetAutonomousCommand();

  void HandlePOV();
  void Drive();
    

 private:
  // The robot's subsystems and commands are defined here...
  frc::XboxController mController{kJoystickPort};
  frc::Joystick mJoystick{kJoystickPort};

  SubDriveTrain* mSubDriveTrain;

  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;
  SubDriveTrain mDriveTrain;

  void ConfigureButtonBindings();
};