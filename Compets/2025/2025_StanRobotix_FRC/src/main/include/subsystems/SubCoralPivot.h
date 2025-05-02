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

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  // Takes as a parameter an angle in radians and uses a PID to make the pivot reach that angle.
  void SetPosition(double);

  // Returns true when the PID of the pivot reached its setpoint given the tolerance.
  bool AtSetPoint();

  // Set the value of the boolean PIDEnable.
  void SetPIDEnable(bool);

  // Method used to send the sufficient voltage to the pivot for it to counter the force of gravity.
  void CounterGravity(); 

  void SetVoltage(double);

  // Method to get the position of the encoder of the pivot.
  double GetAngle();

  void Stop();

 private:
  
  bool PIDEnable = true;

  rev::spark::SparkMax * mCoralPivotMotor = nullptr;
  frc::PIDController * mPIDController;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};