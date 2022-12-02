// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/IMU.h"

frc::ADIS16448_IMU mIMU;

IMU::IMU() 
{
  //  mIMU.SetSubsystem();

}


void IMU::Periodic() {

}

float IMU::getAccelX() {
    return 0;//mIMU.GetAccelX().m_value;

}

float IMU::getAccelY() {
    return 0;//mIMU.GetAccelY().m_value;

}

float IMU::getAngle() {
    return 0; //mIMU.GetAngle().m_value;
}
