// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <rev/SparkMaxPIDController.h>
#include <cmath>

#include "Constants.h"

class SubAscenseur : public frc2::SubsystemBase {
 public:
  SubAscenseur();

  
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  double getPositionVoulue();

  void setPositionVoulue(double iPositionVoulue);

  void bougeAscenseur(double iVitesse);

  void setPositionAscenseur(double iPosition);

  double getEncoderPositionMotor1();
  double getEncoderPositionMotor2();

  double getVelocityMotor1();
  double getVelocityMotor2();

  void stopAscenseurMotors();

  bool isMotorStruggling();

  double MotorStruggling();

  void setEnable(bool iEnable) {mEnable = iEnable;}
  bool isEnable() {return mEnable;}

  double PositionVoulue;

 private:

  bool mEnable = true;
  double vitesse = 0;

  rev::CANSparkMax mAscenseurMotor1 {AscenseurConstants::kMotorId1, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax mAscenseurMotor2 {AscenseurConstants::kMotorId2, rev::CANSparkMax::MotorType::kBrushless};

  rev::SparkMaxRelativeEncoder mAscenseurMotor1Encoder = mAscenseurMotor1.GetEncoder(rev::SparkRelativeEncoder::EncoderType::kHallSensor, 42);
  rev::SparkMaxRelativeEncoder mAscenseurMotor2Encoder = mAscenseurMotor2.GetEncoder(rev::SparkRelativeEncoder::EncoderType::kHallSensor, 42);

  rev::SparkMaxPIDController mPIDController1 = mAscenseurMotor1.GetPIDController();
  rev::SparkMaxPIDController mPIDController2 = mAscenseurMotor2.GetPIDController();

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};