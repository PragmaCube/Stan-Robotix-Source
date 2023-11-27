// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubGyro.h"

SubGyro::SubGyro() 
{
    mGyro = new ctre::phoenix::sensors::WPI_Pigeon2(0);
}

frc::Rotation2d SubGyro::getRotation2D()
{
    return -mGyro->GetRotation2d();
}

void SubGyro::ResetAngle()
{
    mGyro->Reset();
    mGyro->Calibrate();
}

double SubGyro::GetAngle()
{
    mGyro->GetAngle();
}

// This method will be called once per scheduler run
void SubGyro::Periodic() {}
