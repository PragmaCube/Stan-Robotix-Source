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

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  // Takes as a parameter an angle in radians and uses a PID to make the pivot reach that angle.
  void SetPosition(double);

  bool AtSetPoint();

  void Climb();
  void PivotUpSmooth();

  void StayStill();

  void CounterGravity();

  void Stop();

 private:

  rev::spark::SparkMax * mAlgaePivotMotor = nullptr;
  frc::PIDController * mPIDController = nullptr;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};