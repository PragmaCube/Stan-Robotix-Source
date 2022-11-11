// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Ejector.h"

Ejector::Ejector() = default;

// This method will be called once per scheduler run
void Ejector::Periodic() {}

void Ejector::Push()
{
    mRMotorElevator.Set(kSpeedPush);
    mLMotorElevator.Set(-kSpeedPush);
}

void Ejector::Pull()
{
    mRMotorElevator.Set(kSpeedPull);
    mLMotorElevator.Set(-kSpeedPull);
}

void Ejector::Stop()
{
    mRMotorElevator.Set(0);
    mLMotorElevator.Set(0);
}

