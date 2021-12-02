// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/BuiltInAccelerometer.h>
#include <adi/ADIS16448_IMU.h>
#include "Constants.h"

class IMU : public frc2::SubsystemBase {
 public:
  IMU();
  
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  void Init();
  double getXAccel();
  double getYAccel();
  double getZTurningValue();
 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  frc::BuiltInAccelerometer mBuiltInAccelerometer{};
  frc::ADIS16448_IMU imuGyro{};

};
