// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include <iostream>
#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <frc/controller/PIDController.h>

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
  void GoToPlace(double SetPointRight, double SetPointLeft);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  rev::spark::SparkMax * mSparkMaxRight;
  rev::spark::SparkMax * mSparkMaxLeft;
  int i = 0;
  double PastSetPointLeft = 0;
  double PastSetPointRight = 0;
  frc::PIDController * mPIDRight;
  frc::PIDController * mPIDLeft;
  double pivotAngleLeft;
  double pivotAngleRight;
  double OutputLeft;
  double OutputRight;
};
