// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>

#include "Constants.h"

class SubArms : public frc2::SubsystemBase {
 public:

  enum Positions{
    Up,
    Down
  };

  SubArms();
  double GetAngleRight();
  double GetAngleLeft();
  void Stop();

  void SetVoltageRight(units::volt_t);
  void SetVoltageLeft(units::volt_t);

  // Method used to send the sufficient voltage to the pivot for it to counter the force of gravity.
  void CounterGravity();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  rev::spark::SparkMax * mSparkMaxRight;
  rev::spark::SparkMax * mSparkMaxLeft;
};
