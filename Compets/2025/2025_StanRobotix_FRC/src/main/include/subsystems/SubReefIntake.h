// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>


class SubReefIntake : public frc2::SubsystemBase {
 public:
  SubReefIntake();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void SetPercentage(double);

  void Stop();

 private:

  rev::spark::SparkMax * mMotor = nullptr;

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
