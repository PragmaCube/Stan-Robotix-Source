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

  int sgn(int x);

  units::radian_t getAlgaePivotEncoderPosition();

  units::angular_velocity::radians_per_second_t getAlgaePivotEncoderVelocity();
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  bool mEnable = true;

  rev::spark::SparkMax * mAlgaePivotMotor = nullptr;
  frc::PIDController mPIDController{AlgaePivotConstants::kP, AlgaePivotConstants::kI, AlgaePivotConstants::kD};
  frc::ArmFeedforward * feedForward = nullptr;
  double velocityUp = 0;
  double velocityDown = 0;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};