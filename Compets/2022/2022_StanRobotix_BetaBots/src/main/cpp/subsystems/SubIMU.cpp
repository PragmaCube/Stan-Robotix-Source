// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubIMU.h"

//frc::ADIS16448_IMU mIMU;

SubIMU::SubIMU() 
{
  m_Imu.Calibrate();
}

SubIMU::~SubIMU()
{}

void SubIMU::Periodic() {
    units::angle::degree_t turningValue = m_Imu.GetAngle();  
    
	mTurningValue = turningValue.value();
}

void SubIMU::Start() {
    units::angle::degree_t turningValue = m_Imu.GetAngle();  
    
	mTurningValue = turningValue.value();
}

float SubIMU::getAngle() {
    return mTurningValue;
}
