// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <rev/RelativeEncoder.h>
#include <frc/controller/PIDController.h>
#include "Constants.h"

class SubPivot : public frc2::SubsystemBase {
 public:
  SubPivot();

  void setSetPoint(double);

  void runPivot();

  void stopPivot();

  bool atSetPoint();

  bool isEnable();
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  bool mEnable = true;

  rev::spark::SparkMax * mMoteurPivot = nullptr;
  frc::PIDController PIDController{PivotConstants::kP, PivotConstants::kI, PivotConstants::kD};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
