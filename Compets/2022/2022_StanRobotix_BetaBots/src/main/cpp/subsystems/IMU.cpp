// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/IMU.h"

frc::ADIS16448_IMU mIMU;

ImuSubsystem::ImuSubsystem() 
{
  m_Imu.Calibrate();
}

void ImuSubsystem::Periodic() {
    units::angle::degree_t turningValue = m_Imu.GetAngle();  
    
	mTurningValue = turningValue.value();
}

void ImuSubsystem::Start() {
    units::angle::degree_t turningValue = m_Imu.GetAngle();  
    
	mTurningValue = turningValue.value();
}

float ImuSubsystem::getAngle() {
    return mTurningValue;
}
