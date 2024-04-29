// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <rev/CANSparkMax.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"
#include <rev/SparkRelativeEncoder.h>

class SubChain : public frc2::SubsystemBase {
 public:
  SubChain();


  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:

  rev::CANSparkMax mChainMotor{ChainConstants::kMotorID, rev::CANSparkMax::MotorType::kBrushless};

  rev::SparkMaxRelativeEncoder mChainMotorEncoder = mChainMotor.GetEncoder(rev::SparkRelativeEncoder::EncoderType::kHallSensor, 42);

  rev::SparkMaxPIDController mPIDController = mChainMotor.GetPIDController();
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
