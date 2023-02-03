// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubIMU.h"
#include "Constants.h"

SubIMU::SubIMU() 
{
  m_Imu.Calibrate();
}

SubIMU::~SubIMU(){}

void SubIMU::Periodic() {
    if (m_gyroVals.size() == kNumberOfSamples)
    {
        m_gyroVals.pop_back();
    }

    units::angle::degree_t turningValue = m_Imu.GetAngle();
    m_gyroVals.insert(m_gyroVals.begin(), turningValue.value());
}

void SubIMU::Start() {
  m_gyroVals.reserve(kNumberOfSamples);
  Periodic();   
}

float SubIMU::getAngle() {
    double wMoyenne = 0.0;
    for (int i = 0; i < m_gyroVals.size(); i++)
    {
        wMoyenne += m_gyroVals[i];
    }
    return wMoyenne/m_gyroVals.size();
}

units::radian_t SubIMU::getRadian()
{
  units::radian_t angle{m_Imu.GetAngle()};
  return angle;
}