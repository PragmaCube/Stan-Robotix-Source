// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveTrain.h"

SubDriveTrain::SubDriveTrain() = default;

// This method will be called once per scheduler run
void SubDriveTrain::Periodic() {}

void SubDriveTrain::TankDrive(double iLeft, double iRight)
{
    mDriveTrain.TankDrive(0.45 * iLeft, 0.45 * iRight, false);
}

void SubDriveTrain::SetInactive()
{
    mDriveTrain.TankDrive(0, 0);
}