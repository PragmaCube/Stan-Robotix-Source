// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/subDriveTrain.h"

subDriveTrain::subDriveTrain() = default;

// This method will be called once per scheduler run
void subDriveTrain::Periodic() {}
void subDriveTrain::mecanumDrive(float x, float y, float z)
{
    drive.DriveCartesian(y, x, z);
}