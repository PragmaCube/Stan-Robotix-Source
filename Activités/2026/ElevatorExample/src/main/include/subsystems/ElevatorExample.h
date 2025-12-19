// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <rev/config/SparkMaxConfig.h>

#include "Constants.h"

class ElevatorExample : public frc2::SubsystemBase {
 public:
  ElevatorExample();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  void SetMotors(double iMotorPower);
 private:
 rev::spark::SparkMax * mMotor1;
 rev::spark::SparkMax * mMotor2;
 rev::spark::SparkMaxConfig * mMotor1Config;
 rev::spark::SparkMaxConfig * mMotor2Config;

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
