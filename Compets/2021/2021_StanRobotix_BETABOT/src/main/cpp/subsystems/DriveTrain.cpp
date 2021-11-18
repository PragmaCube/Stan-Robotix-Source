// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveTrain.h"

SubDriveTrain::SubDriveTrain() = default;

// This method will be called once per scheduler run
void SubDriveTrain::Periodic() {}

void SubDriveTrain::TankDrive(double iLeft, double iRight, MotorSpeed iMotorSpeed)
{
    switch (iMotorSpeed)
    {
    case eSlow:
        mTankDrive.TankDrive(0.3 * iLeft, 0.3 * iRight, false);
        break;

    case eMedium:
        mTankDrive.TankDrive(0.65 * iLeft, 0.65 * iRight, false);
        break;

    case eFast:
        mTankDrive.TankDrive(iLeft, iRight, false);
        break;

    default:
        mTankDrive.TankDrive(0.75 * iLeft, 0.75 * iRight, false);
        break;
    }
}
