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
enum StatesCoral {
  relaché,
  horizontale,
  shoot,
  vertical,
  replié
};

  SubCoralPivot();

  void Pivot(float);

  void Stop();
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  bool AtSetPoint();

  void SetSetPoint(double);

  void SetPIDEnable(bool);

  StatesCoral GetState();

  void SetState(StatesCoral);

  void CounterGravity();

  void SetVoltage(double);

 private:
  

  

StatesCoral mState;

  const double kOffset =  -16.1678;
  const double kG = 0.43;
  bool PIDEnable = true;

  rev::spark::SparkMax * mCoralPivotMotor = nullptr;
  frc::PIDController mPIDController{0.2, 0.001, 0};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};