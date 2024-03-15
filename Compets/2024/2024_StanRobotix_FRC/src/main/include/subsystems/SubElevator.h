// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <rev/SparkMaxPIDController.h>
#include <cmath>

#include "Constants.h"

enum NumberMotor
{
  Motor1,
  Motor2
};

class SubElevator : public frc2::SubsystemBase {
 public:
  SubElevator();

  
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  double getTargetPosition();

  void setTargetPosition(double iTargetPosition);

  void manualMoveElevator(double iVitesse);

  void setElevatorPosition();

  double getEncoderPositionMotor(NumberMotor iNumberMotor);

  double getVelocityMotor(NumberMotor iNumberMotor);

  void stopElevatorMotors();

  bool isMotorStruggling();

  double MotorStruggling();

  void setEnable(bool iEnable);
  
  bool isEnable();

 private:

  bool mEnable = true;
  double mTargetPosition;

  rev::CANSparkMax mElevatorMotor1 {AscenseurConstants::kMotorId1, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax mElevatorMotor2 {AscenseurConstants::kMotorId2, rev::CANSparkMax::MotorType::kBrushless};

  rev::SparkMaxRelativeEncoder mElevatorMotor1Encoder = mElevatorMotor1.GetEncoder(rev::SparkRelativeEncoder::EncoderType::kHallSensor, 42);
  rev::SparkMaxRelativeEncoder mElevatorMotor2Encoder = mElevatorMotor2.GetEncoder(rev::SparkRelativeEncoder::EncoderType::kHallSensor, 42);

  rev::SparkMaxPIDController mPIDController1 = mElevatorMotor1.GetPIDController();
  rev::SparkMaxPIDController mPIDController2 = mElevatorMotor2.GetPIDController();

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
