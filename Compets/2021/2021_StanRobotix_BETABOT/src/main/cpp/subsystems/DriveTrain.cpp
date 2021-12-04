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
        mDriveTrain.TankDrive(0.25 * iLeft, 0.25 * iRight, false);
        break;

    case eMedium:
        mDriveTrain.TankDrive(0.45 * iLeft, 0.45 * iRight, false);
        break;

    case eFast:
        mDriveTrain.TankDrive(0.65 * iLeft, 0.65 * iRight, false);
        break;

    default:
        mDriveTrain.TankDrive(0.45 * iLeft, 0.45 * iRight, false);
        break;
    }
}

void SubDriveTrain::ArcadeDrive(double iSpeed, double iRotation, MotorSpeed iMotorSpeed)
{
    switch (iMotorSpeed)
    {
    case eSlow:
        mDriveTrain.ArcadeDrive(0.5 * iSpeed, 0.5 * iRotation);
        break;

    case eMedium:
        mDriveTrain.ArcadeDrive(0.75 * iSpeed, 0.75 * iRotation);
        break;

    case eFast:
        mDriveTrain.ArcadeDrive(0.5 * iSpeed, 0.5 * iRotation);
        break;

    default:
        mDriveTrain.ArcadeDrive(0.75 * iSpeed, 0.75 * iRotation);
        break;
    }
}

void SubDriveTrain::SetInactive()
{
    mDriveTrain.TankDrive(0, 0);
}