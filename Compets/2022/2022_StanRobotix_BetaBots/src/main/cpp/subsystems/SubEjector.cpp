// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubEjector.h"

SubEjector::SubEjector() {}

// This method will be called once per scheduler run
void SubEjector::Periodic() {}

void SubEjector::Push()
{
    mRMotorElevator.Set(-kSpeedPush);
    mLMotorElevator.Set(kSpeedPush);
}

void SubEjector::Pull()
{
    mRMotorElevator.Set(-kSpeedPull);
    mLMotorElevator.Set(kSpeedPull);
}

void SubEjector::Stop()
{
    mRMotorElevator.Set(0);
    mLMotorElevator.Set(0);
}

