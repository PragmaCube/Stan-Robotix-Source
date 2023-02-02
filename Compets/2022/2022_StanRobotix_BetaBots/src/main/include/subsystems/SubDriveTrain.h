// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "Constants.h"

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/Spark.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/SpeedControllerGroup.h>


class SubDriveTrain : public frc2::SubsystemBase {
 public:
  SubDriveTrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  enum MotorSpeed { eSlow = 0, eMedium = 1, eFast = 2 };

  void MoveDrive(double iLeft, double iRight, MotorSpeed iMotorSpeed);

 private:

  frc:: Spark MotorFR{kMotorR1Port};
  frc:: Spark MotorBR{kMotorR2Port};
  frc:: Spark MotorFL{kMotorL1Port};
  frc:: Spark MotorBL{kMotorL2Port}; 

  frc::SpeedControllerGroup mLeftSide{MotorBL, MotorFL};
	frc::SpeedControllerGroup mRightSide{MotorBR, MotorFR};

  frc::DifferentialDrive mDriveTrain{mLeftSide, mRightSide};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

};
