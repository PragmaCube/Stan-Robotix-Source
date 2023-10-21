// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubArm.h"

SubArm::SubArm() = default;

void SubArm::PosUp()
{
    mPIDArmController.SetReference(ArmConstants::kPositionUp + m0, rev::ControlType::kSmartMotion);
}

void SubArm::PosDown()
{
    mPIDArmController.SetReference(ArmConstants::kPositionDown + m0, rev::ControlType::kSmartMotion);
}

void SubArm::CalibrationDown()
{
    mPIDArmController.SetReference(ArmConstants::kCalibrationDown, rev::ControlType::kVoltage);
}

void SubArm::Stop()
{
    mPIDArmController.SetReference(0, rev::ControlType::kDutyCycle);
}
void SubArm::Calibrate0()
{
    m0 = mMotorArmEncoder.GetPosition();
}

// This method will be called once per scheduler run
void SubArm::Periodic() {}
