// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc/XboxController.h>
#include <frc/XboxController.h>
#include <frc/Timer.h>

#include <cameraserver/CameraServer.h>
#include "commands/AutonomousCommand.h"
#include "subsystems/SubClimber.h"
#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubEjector.h"
#include "subsystems/SubIMU.h"

#include "Constants.h" 
/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer
{
public:
  RobotContainer();

  frc2::Command *GetAutonomousCommand();
  void Drive();
  void Auto();

private:
  AutonomousCommand m_autonomousCommand;

  frc::XboxController mController{kJoystickPort};
  SubDriveTrain *mDriveTrain;
  SubClimber *mClimber;
  SubDriveTrain::MotorSpeed mMotorSpeed[3];

  SubClimber::eHeight mHeight[4];

  SubIMU *mImu;

  int mMotorIndex;
  SubEjector *mEjector;
  frc::Timer mAutoTimer;

  bool ejector_in_use = false;
  bool mSmart = 0 ;
  void ConfigureButtonBindings();
  void DriveClimber();
  void DriveDisplacement();
  void DriveEjector();

};
