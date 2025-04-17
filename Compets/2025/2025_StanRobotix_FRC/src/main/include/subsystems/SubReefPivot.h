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



class SubReefPivot : public frc2::SubsystemBase {

 public:

  SubReefPivot();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  // Takes as a parameter an angle in radians and uses a PID to make the pivot reach that angle.
  void SetPosition(double);

  bool AtSetPoint();

  void StayStill();

  void CounterGravity();

  void SetVoltage(double);

  void StopPivot();

 private:
  // Voltage used to counter the force of gravity.
  const double kG = 0.27;
  
  const double kOffset = 5.27;

  rev::spark::SparkMax * mMotor = nullptr;

  frc::PIDController mPIDController{0.14, 0, 0};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};