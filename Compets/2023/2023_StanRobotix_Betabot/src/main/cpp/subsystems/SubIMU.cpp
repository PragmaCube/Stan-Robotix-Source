// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubIMU.h"

SubIMU::SubIMU() = default;

// This method will be called once per scheduler run
void SubIMU::Periodic() {}

void SubIMU::ResetAngle()
{
    IMU.Reset();
}

units::standard_gravity_t SubIMU::getAccelX()
{
    int16_t wAccel[3];
    IMU.GetBiasedAccelerometer(wAccel);
    return units::standard_gravity_t{(double)wAccel[0] / 16384.0 };
}


units::standard_gravity_t SubIMU::getAccelY()
{
    int16_t wAccel[3];
    IMU.GetBiasedAccelerometer(wAccel);
    return units::standard_gravity_t{(double)wAccel[1] / 16384.0};
}

units::standard_gravity_t SubIMU::getAccel()
{
    int16_t wAccel[3];
    IMU.GetBiasedAccelerometer(wAccel);
    return units::standard_gravity_t{sqrt(pow((double)wAccel[0] / 16384.0,2) + pow((double)wAccel[1] / 16384.0,2))};
}


frc::Rotation2d SubIMU::getRotation2d()
{
    return IMU.GetRotation2d();
}

units::standard_gravity_t SubIMU::getShock()
{
    return ShockFilter.Calculate(getAccel());
}