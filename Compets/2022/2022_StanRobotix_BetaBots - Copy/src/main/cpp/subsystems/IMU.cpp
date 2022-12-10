// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/IMU.h"


IMU::IMU() 
{
    mIMU.SetSubsystem();

}


void IMU::Periodic() {

}

float IMU::GetAccelX() {
    return mIMU.GetAccelX().;

}

float IMU::GetAccelY() {
    return mIMU.GetAccelY().m_value;

}

float IMU::GetAngle() {
    return mIMU.GetAngle().m_value;
}
