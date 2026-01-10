// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/IMU.h"

IMU::IMU() = default;

// This method will be called once per scheduler run
void IMU::Periodic() {}

double IMU::GetAngle()
{ 
    return mpigeon2.GetAngle();
}