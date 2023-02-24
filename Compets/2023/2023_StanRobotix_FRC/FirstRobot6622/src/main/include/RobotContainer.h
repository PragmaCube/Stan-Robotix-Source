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
#include "subsystems/SubContactDetection.h"

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

  SubDriveTrain *getDriveTrain()                 { return mSubDriveTrain; }
  SubLimelight *getLimelight()                   { return mSubLimelight; }
  SubColorSensor *getColorSensor()               { return mSubColorSensor; }
  SubIMU *getImu()                               { return mSubImu; }
  SubUltrasonic *getUltrasonic()                 { return mSubUltrasonic; }
  SubElevator *getSubElevator()                  { return mSubElevator; }
  SubPneumatic *getSubPneumatic()                { return mSubPneumatic; }
  SubContactDetection * getSubContactDetection() { return mSubContactDetection; }

private:
  AutonomousCommand *m_autonomousCommand;

  frc::Joystick mJoystick{kJoystickPort};

  SubDriveTrain      * mSubDriveTrain;
  SubLimelight       * mSubLimelight = nullptr;
  SubColorSensor     * mSubColorSensor = nullptr;
  SubIMU             * mSubImu = nullptr;
  SubUltrasonic      * mSubUltrasonic = nullptr;
  SubElevator        * mSubElevator = nullptr;
  SubPneumatic       * mSubPneumatic = nullptr;
  SubContactDetection*mSubContactDetection = nullptr;

  bool mSmart = 0;
  bool mIsInit = false;

  void Init ();
  void ConfigureButtonBindings();
  void DriveDisplacement();
  void DrivePneumatic();
};