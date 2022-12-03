// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubDriveTrain.h"

SubDriveTrain::SubDriveTrain() = default;

// This method will be called once per scheduler run
void SubDriveTrain::Periodic() {}
void SubDriveTrain::TankDrive(double iLeftHand, double iRightHand, MotorSpeed iMotorSpeed)
{
    switch (iMotorSpeed)
    {
    case eSlow:
        mDriveTrain.TankDrive(0.55 * iLeftHand, -0.55 * iRightHand);
        break;

    case eMedium:
        mDriveTrain.TankDrive(0.65 * iLeftHand, -0.65 * iRightHand);
        break;

    case eFast:
        mDriveTrain.TankDrive(0.80 * iLeftHand, -0.80 * iRightHand);
        break;

    default:
        mDriveTrain.TankDrive(0.45 * iLeftHand, -0.45
        * iRightHand);
        break;
    }
}