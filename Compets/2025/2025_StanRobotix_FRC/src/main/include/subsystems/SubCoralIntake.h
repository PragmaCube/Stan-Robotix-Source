// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>

#include "Constants.h"

class SubCoralIntake : public frc2::SubsystemBase {
 public:
  SubCoralIntake();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;


  void SetVoltage(double);

  void SetPercentage(double);
  
  void Stop();

 private:
  rev::spark::SparkMax * mCoralIntakeMotor = nullptr;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
