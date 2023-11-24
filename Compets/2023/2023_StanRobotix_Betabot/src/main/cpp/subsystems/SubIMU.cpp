// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubIMU.h"

SubIMU::SubIMU() 
{
    mGyro = new ctre::phoenix::sensors::WPI_Pigeon2(0);
}

frc::Rotation2d SubIMU::getRotation2D()
{
    return -mGyro->GetRotation2d();
}

void SubIMU::ResetAngle()
{
    mGyro->Reset();
    mGyro->Calibrate();
}

double SubIMU::GetAngle()
{
    return mGyro->GetAngle();
}

// This method will be called once per scheduler run
void SubIMU::Periodic() {}