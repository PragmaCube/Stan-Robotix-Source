// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <rev/config/SparkMaxConfig.h>
#include <frc/controller/PIDController.h>
#include <frc/controller/ProfiledPIDController.h>
#include <frc/controller/ElevatorFeedforward.h>
#include <rev/SparkRelativeEncoder.h>

#include "Constants.h"

class SubElevator : public frc2::SubsystemBase {
 public:
  SubElevator();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */

  bool AtSetpoint();

  bool AtSetpointFeedForward();

  void manualUp();

  void manualDown();

  void Stop();

  void DefaultCommand();

  void SetPosition(double iSetpoint);

  void SetPositionFeedForward(units::radian_t iGoal);

  void CounterGravity();

  int sgn(double iInput);

  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  rev::spark::SparkMax * mElevatorMotor;
  frc::PIDController * mPIDController;
  frc::ProfiledPIDController<units::radians> * mProfiledPIDController;
  frc::ElevatorFeedforward * mFeedForward;
  rev::spark::SparkRelativeEncoder * mRelativeEncoder;
  rev::spark::SparkMaxConfig * mSparkMaxConfig;
};
