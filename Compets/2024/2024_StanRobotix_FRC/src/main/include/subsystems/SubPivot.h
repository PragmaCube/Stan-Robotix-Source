// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <rev/SparkMaxPIDController.h>
#include "Constants.h"

#include <cmath>


class SubPivot : public frc2::SubsystemBase {
 public:
  SubPivot();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void pivotUp();
  void pivotGo(double ivitesse);
  double getEncodeurPosition();
  double getVelocityMotor();
  void stopPivot();
  void pivotDown();
  void pivotMiddle();

  bool isEnable();
  void setEnable(bool iEnable) {mHeight = iEnable;}


  double kMaxVel = 2000, 
         kMinVel = 0, 
         kMaxAcc = 1500, 
         kAllErr = 0;
  
  
 private:
  bool mEnable = true;
  float mHeight = 0;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  rev::CANSparkMax mPivotMotor{PivotConstants::kMotorId, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
  rev::SparkMaxRelativeEncoder mPivotMotorEncodeur = mPivotMotor.GetEncoder(rev::SparkRelativeEncoder::EncoderType::kHallSensor, 42);
  rev::SparkMaxPIDController mPIDController = mPivotMotor.GetPIDController();
  
};
