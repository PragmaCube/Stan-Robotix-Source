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
#include "subsystems/SubElevator.h"
/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */

#include <frc/XboxController.h>
#include <cameraserver/CameraServer.h>

#include "subsystems/DriveTrain.h"

#include "subsystems/LaunchSystem.h"
#include "rev/CANSparkMax.h"


class RobotContainer {
  public:
  RobotContainer();
  enum Side { eLeft, eRight, eForward };

  frc2::Command* GetAutonomousCommand();

  void HandlePOV();
  void Drive();
  void Auto();
  void ResetAuto();

  cs::UsbCamera mCamera;
  
  private:
  // The robot's subsystems and commands are defined here...
  frc::XboxController mController{kJoystickPort};
  frc::Timer mAutoTimer;

  ExampleSubsystem m_subsystem;

  ExampleCommand m_autonomousCommand;

  SubDriveTrain* mSubDriveTrain;
  SubDriveTrain::MotorSpeed mMotorSpeed[3];
  LaunchSystem::LauncherSpeed mLauncherSpeed[2];

  int mMotorIndex;
  int mLauncherIndex;

  SubElevator* mElevator;

  bool isCollecting;
  bool isLaunching;

  void ConfigureButtonBindings();

  LaunchSystem* mLaunchSystem;  

  bool mLaunch;
  bool mShoot;
};
