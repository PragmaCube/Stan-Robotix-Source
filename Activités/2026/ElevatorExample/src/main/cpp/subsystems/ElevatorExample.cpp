// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ElevatorExample.h"

ElevatorExample::ElevatorExample()
{
    mMotor1 = new rev::spark::SparkMax{ElevatorConstants::kMotorId1, rev::spark::SparkLowLevel::MotorType::kBrushless};
    mMotor2 = new rev::spark::SparkMax{ElevatorConstants::kMotorId2, rev::spark::SparkLowLevel::MotorType::kBrushless};
    mMotor1Config = new rev::spark::SparkMaxConfig{};
    mMotor2Config = new rev::spark::SparkMaxConfig{};
    mMotor1Config->Inverted(true);
    mMotor2Config->Inverted(false);
    mMotor1->Configure(*mMotor1Config,rev::spark::SparkBase::ResetMode::kNoResetSafeParameters, rev::spark::SparkBase::PersistMode::kPersistParameters);
    mMotor2->Configure(*mMotor1Config, rev::spark::SparkBase::ResetMode::kNoResetSafeParameters, rev::spark::SparkBase::PersistMode::kPersistParameters);

}

// This method will be called once per scheduler run
void ElevatorExample::Periodic() {}

void ElevatorExample::SetMotors(double iMotorPower)
{
    mMotor1->Set(iMotorPower);
    mMotor2->Set(iMotorPower);
}


