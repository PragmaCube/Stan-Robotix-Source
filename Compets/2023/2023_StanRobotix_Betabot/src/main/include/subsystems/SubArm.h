// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <rev/SparkMaxPIDController.h>
#include "Constants.h"

class SubArm : public frc2::SubsystemBase {
 public:
  SubArm();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void Up();
  void Down();
  double GetEncodeurPosition();
  void StopArm();

  double kMaxVel = 2000, 
         kMinVel = 0, 
         kMaxAcc = 1500, 
         kAllErr = 0;

 private:
  float Height = 0;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  rev::CANSparkMax mArmMotor {ArmConstants::kMotorId, rev::CANSparkMax::MotorType::kBrushless};
  rev::SparkMaxRelativeEncoder mArmMotorEncodeur = mArmMotor.GetEncoder();
  rev::SparkMaxPIDController mPIDController = mArmMotor.GetPIDController();
  
};