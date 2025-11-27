// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/ADIS16448_IMU.h>
#include "Constants.h"

class IMUsubsystem : public frc2::SubsystemBase {
 public:
  IMUsubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  
  double GetYawAxis();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  frc::ADIS16448_IMU * mIMU = nullptr;
};
