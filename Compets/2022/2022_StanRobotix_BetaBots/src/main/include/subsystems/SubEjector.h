// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMaxRelativeEncoder.h>

#include "rev/CANSparkMax.h"
#include "Constants.h"

class SubEjector : public frc2::SubsystemBase {
 public:
  SubEjector();

  void Push();
  void Pull();
  void Stop();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  rev::CANSparkMax mRMotorElevator{kCanIdElevatorR, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax mLMotorElevator{kCanIdElevatorL, rev::CANSparkMax::MotorType::kBrushless};

  rev::SparkMaxRelativeEncoder mRMotorEncoder = mRMotorElevator.GetEncoder();
  rev::SparkMaxRelativeEncoder mLMotorEncoder = mLMotorElevator.GetEncoder();
};
