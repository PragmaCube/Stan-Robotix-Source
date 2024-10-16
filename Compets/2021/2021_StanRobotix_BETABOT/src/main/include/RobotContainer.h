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
#include <frc/Joystick.h>

#include <frc/Timer.h>

#include "subsystems/DriveTrain.h"
#include "subsystems/Pulley.h"
#include "subsystems/Solenoid.h"

class RobotContainer {
 public:
  enum Side { eLeft, eRight, eForward };
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

  void HandlePOV();
  void Drive();
  void Auto(Side iSide);
  void ResetAuto();

 private:
  // The robot's subsystems and commands are defined here...
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;

  frc::XboxController mController{kJoystickPort};
  frc::Joystick mJoystick{kJoystickPort};

  SubDriveTrain* mSubDriveTrain;

  SubDriveTrain::MotorSpeed mMotorSpeed[3];
  SubDriveTrain::DriveMode mDriveMode;
  SubDriveTrain::DriveController mDriveController;

  int mMotorIndex;

  SubSolenoid* mPiston;

  SubPulley* mPulley;

  frc::Timer mAutoTimer;
  bool mAutoCompressor = true;
  bool mAutoPulley = false;

  void ConfigureButtonBindings();
};
