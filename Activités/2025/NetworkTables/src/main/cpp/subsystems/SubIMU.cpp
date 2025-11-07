// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubIMU.h"

SubIMU::SubIMU() = default;

// This method will be called once per scheduler run
void SubIMU::Periodic() {}

frc::Rotation2d SubIMU::getRotation2d()
{
    return mIMU.GetRotation2d();
}


void SubIMU::resetAngle()
{
    mIMU.Reset();
}