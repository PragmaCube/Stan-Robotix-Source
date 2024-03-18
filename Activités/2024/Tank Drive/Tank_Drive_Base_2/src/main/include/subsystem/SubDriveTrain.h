// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "Constants.h"
#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/Spark.h>
#include <frc/drive/DifferentialDrive.h>

class SubDriveTrain : public frc2::SubsystemBase {
 public:
  SubDriveTrain();

  void tankDrive(double iLeftSpeed, double iRightSpeed);
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  frc::Spark mSparkRight{DriveTrainConstants::kMotorsRight};
  frc::Spark mSparkLeft{DriveTrainConstants::kMotorsLeft};

  frc::DifferentialDrive mDrive{mSparkLeft, mSparkRight} ;
};
