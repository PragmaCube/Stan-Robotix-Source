// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once


#include <rev/SparkMaxRelativeEncoder.h>
#include <rev/CANSparkMax.h>
#include <frc2/command/SubsystemBase.h>
#include "Constants.h"


class SubArm : public frc2::SubsystemBase {
 public:
  SubArm();
  
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void PosDown();
  void PosUp();

  void Move(float);

 private:

  rev::CANSparkMax mMotorArm{ArmConstants::kArmCanId, rev::CANSparkMax::MotorType::kBrushless};
  rev::SparkMaxRelativeEncoder mMotorArmEncoder = mMotorArm.GetEncoder();
  rev::SparkMaxPIDController mPIDArmController = mMotorArm.GetPIDController();

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
