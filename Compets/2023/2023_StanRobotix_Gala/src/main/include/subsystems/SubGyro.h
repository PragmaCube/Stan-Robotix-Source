// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/ADXRS450_Gyro.h>
#include <frc/SPI.h>

class SubGyro : public frc2::SubsystemBase {
 public:
  SubGyro();

  frc::Rotation2d GetRotation2D();
  void ResetAngle();
  
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  frc::ADXRS450_Gyro mGyro;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
