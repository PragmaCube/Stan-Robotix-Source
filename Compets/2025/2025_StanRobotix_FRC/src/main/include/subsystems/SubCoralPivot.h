// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <iostream>
#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <rev/RelativeEncoder.h>
#include <frc/controller/PIDController.h>
#include <frc/controller/ArmFeedforward.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <rev/SparkRelativeEncoder.h>
#include <frc/controller/ArmFeedforward.h>

#include "Constants.h"

class SubCoralPivot : public frc2::SubsystemBase {
 public:
  SubCoralPivot();

  void stopCoralPivot();

  void Pivot();

  void Pivot(float);

  void PivotUp();
  void PivotDown();

  void Stop();
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  bool atSetPoint();

  void SetSetPoint(double);

 private:
  bool mEnable = true;

  const double kOffset =  -14.7857;

  rev::spark::SparkMax * mCoralPivotMotor = nullptr;
  frc::PIDController mPIDController{0.2, 0, 0};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};