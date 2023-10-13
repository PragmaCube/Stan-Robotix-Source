// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubGyro.h"

SubGyro::SubGyro() = default;

frc::Rotation2d SubGyro::GetRotation2D()
{
    return mGyro.GetRotation2d();
}

void SubGyro::ResetAngle()
{
    mGyro.Reset();
    mGyro.Calibrate();
}

// This method will be called once per scheduler run
void SubGyro::Periodic() {}
