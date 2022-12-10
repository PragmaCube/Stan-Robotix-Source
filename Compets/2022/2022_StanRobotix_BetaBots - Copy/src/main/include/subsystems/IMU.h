// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

#include <frc/ADIS16448_IMU.h>

class IMU : public frc2::SubsystemBase {
 public:
  IMU();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  float GetAccelX();
  float GetAccelY();

  float GetAngle();

  void Periodic() override;
   
 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  frc::ADIS16448_IMU mIMU;

};
