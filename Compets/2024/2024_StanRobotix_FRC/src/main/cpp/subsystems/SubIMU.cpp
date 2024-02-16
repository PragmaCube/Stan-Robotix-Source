// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubIMU.h"
#include <cmath>

SubIMU::SubIMU() = default;

// This method will be called once per scheduler run
void SubIMU::Periodic() {}

void SubIMU::ResetAngle()
{
    IMU.Reset();
}

units::standard_gravity_t SubIMU::getAccelX()
{
    return IMU.GetAccelerationX().GetValue();
}


units::standard_gravity_t SubIMU::getAccelY()
{
    return IMU.GetAccelerationY().GetValue();
}

units::standard_gravity_t SubIMU::getAccel()
{
    return units::standard_gravity_t(std::sqrt(std::pow( IMU.GetAccelerationX().GetValueAsDouble(),2) + std::pow(IMU.GetAccelerationY().GetValueAsDouble(),2) ));
}


frc::Rotation2d SubIMU::getRotation2d()
{
    return IMU.GetRotation2d();
}

units::standard_gravity_t SubIMU::getShock()
{
    return ShockFilter.Calculate(getAccel());
}


double SubIMU::getAngleYaw()
{
    return IMU.GetAngle();
}