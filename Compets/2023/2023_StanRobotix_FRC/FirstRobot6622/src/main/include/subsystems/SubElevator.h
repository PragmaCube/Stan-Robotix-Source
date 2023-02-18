// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once


#include <rev/SparkMaxRelativeEncoder.h>
#include <rev/CANSparkMax.h>

#include "Constants.h"
#include <frc2/command/SubsystemBase.h>


class SubElevator : public frc2::SubsystemBase {
 public:
  SubElevator();

  enum eHeight{h0 = 0 ,h1 = 1, h2 = 2};
  
  void resetPidData();
  void Stage(eHeight iHeight);
  void Periodic() override;

 private:

  double kMaxVel = 10000, 
         kMinVel = 0, 
         kMaxAcc = 8000, 
         kAllErr = 0;

  rev::CANSparkMax mRMotorElevator{kCanIdElevatorR, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax mLMotorElevator{kCanIdElevatorL, rev::CANSparkMax::MotorType::kBrushless};
  
  rev::SparkMaxRelativeEncoder mRMotorEncoder = mRMotorElevator.GetEncoder();
  rev::SparkMaxRelativeEncoder mLMotorEncoder = mLMotorElevator.GetEncoder();

  rev::SparkMaxPIDController mRPIDController = mRMotorElevator.GetPIDController();
  rev::SparkMaxPIDController mLPIDController = mLMotorElevator.GetPIDController();

  double mHeight_ = kMinHeight;
};
