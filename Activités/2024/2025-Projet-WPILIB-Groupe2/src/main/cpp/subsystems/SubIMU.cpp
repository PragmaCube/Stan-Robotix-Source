// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubIMU.h"
#include <ctre/phoenix6/Pigeon2.hpp>

SubIMU::SubIMU() = default;

// This method will be called once per scheduler run
void SubIMU::Periodic() {}

void SubIMU::ResetAngle()
{
    mIMU.Reset();
}

frc::Rotation2d SubIMU::getRotation2d()
{
    return mIMU.GetRotation2d();
}

double SubIMU::getAngleYaw()
{
    return mIMU.GetAngle();
}
