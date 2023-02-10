// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

#include <frc/motorcontrol/Talon.h>
#include <frc/motorcontrol/Spark.h>

#include <frc/motorcontrol/MotorController.h>
#include <frc/motorcontrol/MotorControllerGroup.h>

#include <frc/drive/DifferentialDrive.h>
#include <frc/drive/MecanumDrive.h>

#include <Constants.h>
#include "subsystems/motor_pid_subsystem.h"

#include "Constants.h"

class SubDriveTrain : public frc2::SubsystemBase {
 public:
  SubDriveTrain();
  enum MotorSpeed { eSlow = 0, eMedium = 1, eFast = 2 };
  
  enum DriveMode { eArcadeDrive = 0, eTankDrive = 1};
  enum DriveController { eXBox = 0, eJoystick = 1 };

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  void TankDrive(double iLeft, double iRight, MotorSpeed iMotorSpeed);
  void ArcadeDrive(double iSpeed, double iRotation, MotorSpeed iMotorSpeed);
  void SetInactive();
  
  // Implémentation PID
  void PidStartTimer();
  void PidSetPoint(double iSetPoint);
  void PidDrive();
  bool PidAtsetpoint();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  frc::Talon mMotorL1{kMotorL1Port};
  frc::Talon mMotorL2{kMotorL2Port};
  frc::Spark mMotorR1{kMotorR1Port};
  frc::Talon mMotorR2{kMotorR2Port}; 

  //frc::MecanumDrive mMecanumDrive{mMotorL1, mMotorL2, mMotorR1, mMotorR2};

  frc::MotorControllerGroup mLeftSide{mMotorL1, mMotorL2};
	frc::MotorControllerGroup mRightSide{mMotorR1, mMotorR2};

  frc::DifferentialDrive mDriveTrain{mLeftSide, mRightSide};

  // Ajout du pid
  MotorPIDSubsystem mPid {5, 0.1, 0.1};
};
