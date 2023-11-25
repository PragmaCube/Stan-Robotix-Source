// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "rev/CANSparkMax.h"
#include "Constants.h"

class SubArm : public frc2::SubsystemBase {
 public:
  SubArm();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  rev::CANSparkMax mArmMotor{ArmConstants::kMotorId, rev::CANSparkMax::MotorType::kBrushless};
  rev::SparkMaxPIDController mArmPID = mArmMotor.GetPIDController();
  mArmPID.SetReference(SetPoint, rev::CANSparkMax::ControlType::kSmartMotion);
  ProcessVariable = m_encoder.GetPosition();
};
