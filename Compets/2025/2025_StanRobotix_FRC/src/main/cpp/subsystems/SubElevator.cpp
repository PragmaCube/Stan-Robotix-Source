// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubElevator.h"

SubElevator::SubElevator()
{
    mElevatorMotor = new rev::spark::SparkMax{ElevatorConstants::kMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless};
}

// This method will be called once per scheduler run
void SubElevator::Periodic() {}

void SubElevator::manualUp()
{
    mElevatorMotor->Set(-0.01);
}

void SubElevator::manualDown()
{
    mElevatorMotor->Set(0.01);
}