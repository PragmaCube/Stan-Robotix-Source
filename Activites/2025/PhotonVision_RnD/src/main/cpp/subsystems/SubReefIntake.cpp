// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubReefIntake.h"

SubReefIntake::SubReefIntake()
{
    mMotor = new rev::spark::SparkMax(13, rev::spark::SparkLowLevel::MotorType::kBrushless);
}

// This method will be called once per scheduler run
void SubReefIntake::Periodic() {}

void SubReefIntake::SetPercentage(double iPercent)
{
    mMotor->Set(iPercent);
}

void SubReefIntake::Stop()
{
    mMotor->StopMotor();
}