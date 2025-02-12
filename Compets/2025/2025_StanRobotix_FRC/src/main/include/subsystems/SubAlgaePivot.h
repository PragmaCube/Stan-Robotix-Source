// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <rev/RelativeEncoder.h>
#include <frc/controller/PIDController.h>
#include "Constants.h"

class SubAlgaePivot : public frc2::SubsystemBase {
 public:
  SubAlgaePivot();

  void setSetPoint(double);

  void runAlgaePivotPID();

  void stopAlgaePivot();

  void manualAlgaePivot();

  void manualAlgaePivotReverse();
  
  bool atSetPoint();

  bool isEnable();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  bool mEnable = true;

  rev::spark::SparkMax * mAlgaePivotMotor = nullptr;
  frc::PIDController mPIDController{AlgaePivotConstants::kP, AlgaePivotConstants::kI, AlgaePivotConstants::kD};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};