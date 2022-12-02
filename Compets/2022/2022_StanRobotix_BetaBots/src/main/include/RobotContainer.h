// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc/XboxController.h>

#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/SubClimber.h"
#include "Constants.h"#include <frc/XboxController.h>
#include <frc/Timer.h>
#include "subsystems/DriveTrain.h"

#include "subsystems/Ejector.h"
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

  frc2::Command* GetAutonomousCommand();
  void Drive();
  void DriveClimber();
  void DriveDisplacement();
  void DriveEjector();

 private:
  // The robot's subsystems and commands are defined here...
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;

  
  frc::XboxController mController{kJoystickPort};
  DriveTrain* mDriveTrain;

  DriveTrain::MotorSpeed mMotorSpeed[3];

  void ConfigureButtonBindings();

  SubClimber* mClimber;
  SubClimber::Height mHeight[3];

    int mMotorIndex;
  Ejector* mEjector;
  frc::Timer mAutoTimer;

  bool ejector_in_use = false;
};
