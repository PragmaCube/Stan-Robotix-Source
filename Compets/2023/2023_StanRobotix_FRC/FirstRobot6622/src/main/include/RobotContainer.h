// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc/XboxController.h>
#include <frc/Joystick.h>
#include <frc/Timer.h>
#include <frc/smartdashboard/smartdashboard.h>

#include <string>

#include "commands/AutonomousCommand.h"

#include "subsystems/SubColorSensor.h"
#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubElevator.h"
#include "subsystems/SubIMU.h"
#include "subsystems/subLimelight.h"
#include "subsystems/SubPneumatic.h"
#include "subsystems/SubUltrasonic.h"

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

  void AutonomousInit();
  void TeleopInit();

  void AutonomousPeriodic();

  frc2::Command *GetAutonomousCommand();
  void Drive();
  void Auto();

  SubDriveTrain *getDriveTrain() { return mDriveTrain; }
  SubLimelight *getLimelight() { return mLimelight; }
  SubColorSensor *getColorSensor() { return mColorSensor; }
  SubIMU *getImu() { return mImu; }
  SubUltrasonic *getUltrasonic() { return mUltrasonic; }
  SubElevator *getSubElevator() { return mElevator; }
  SubPneumatic *getSubPneumatic() { return mPneumatic; }

private:
  AutonomousCommand *m_autonomousCommand;

  frc::Joystick mJoystick{kJoystickPort};

  SubDriveTrain *mDriveTrain;
  SubLimelight *mLimelight = nullptr;
  SubColorSensor *mColorSensor = nullptr;
  SubIMU *mImu = nullptr;
  SubUltrasonic *mUltrasonic = nullptr;
  SubElevator *mElevator = nullptr;
  SubPneumatic *mPneumatic = nullptr;

  bool mSmart = 0;
  void ConfigureButtonBindings();
  void DriveDisplacement();
  void DrivePneumatic();
};