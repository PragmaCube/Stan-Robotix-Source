// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <rev/SparkMaxPIDController.h>

#include "Constants.h"

class SubAscenseur : public frc2::SubsystemBase {
 public:
  SubAscenseur();

  
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  int getVitesse();

  void setVitesse(float Vitesse);

  void bougeAscenseur(double iVitesse);

  double getEncoderPositionMotor1();
  double getEncoderPositionMotor2();

  void stopAscenseurMotors();

 private:

  float vitesse = 0;

  rev::CANSparkMax mAscenseurMotor1 {AscenseurConstants::kMotorId1, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax mAscenseurMotor2 {AscenseurConstants::kMotorId2, rev::CANSparkMax::MotorType::kBrushless};

  rev::SparkMaxRelativeEncoder mAscenseurMotor1Encoder = mAscenseurMotor1.GetEncoder(rev::SparkRelativeEncoder::EncoderType::kHallSensor, 42);
  rev::SparkMaxRelativeEncoder mAscenseurMotor2Encoder = mAscenseurMotor2.GetEncoder(rev::SparkRelativeEncoder::EncoderType::kHallSensor, 42);

  rev::SparkMaxPIDController mPIDController1 = mAscenseurMotor1.GetPIDController();
  rev::SparkMaxPIDController mPIDController2 = mAscenseurMotor2.GetPIDController();

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
