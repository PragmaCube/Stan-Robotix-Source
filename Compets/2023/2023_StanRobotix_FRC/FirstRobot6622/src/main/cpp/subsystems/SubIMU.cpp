// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubIMU.h"
#include "Constants.h"

SubIMU * SubIMU::mSingleton = nullptr;

SubIMU::SubIMU() : m_Imu(nullptr)
{
  
}

SubIMU::~SubIMU(){}

SubIMU * SubIMU::getInstance()
{
    if (mSingleton == nullptr)
    {
        mSingleton = new SubIMU();
    }
    return mSingleton;
}

void SubIMU::Enable()
{
  m_Imu = new frc::ADIS16448_IMU();
  m_Imu->Calibrate();
  m_gyroVals.reserve(kNumberOfSamples);
  Periodic();   
}

void SubIMU::Periodic() 
{
    if (m_gyroVals.size() == kNumberOfSamples)
    {
        m_gyroVals.pop_back();
    }

    units::angle::degree_t turningValue = (m_Imu != nullptr)?m_Imu->GetAngle():
                                                             units::degree_t(0);
    m_gyroVals.insert(m_gyroVals.begin(), turningValue.value());
}

float SubIMU::getAngle() 
{
    double wMoyenne = 0.0;
    int wSizeVectorMoy =  m_gyroVals.size();
    for (int i = 0; i < wSizeVectorMoy ; i++)
    {
        wMoyenne += m_gyroVals[i];
    }
    return wMoyenne/wSizeVectorMoy ;
}

units::radian_t SubIMU::getRadian()
{
  if (m_Imu != nullptr)
  {
      units::radian_t angle{m_Imu->GetAngle()};
      return angle;
  }
  return (units::radian_t)0;  
}