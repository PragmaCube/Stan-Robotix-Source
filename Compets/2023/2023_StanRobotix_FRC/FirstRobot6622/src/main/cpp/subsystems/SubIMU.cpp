// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Date       Auteur       Description                                               Test
// 09Fev2023  Antoine T.   IMU                                                       ...
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "subsystems/SubIMU.h"
#include "Constants.h"

SubIMU * SubIMU::mSingleton = nullptr;

SubIMU::SubIMU()
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
    
}

void SubIMU::Periodic() 
{
  
}

float SubIMU::getAngle() 
{
  
    return 0.0;

}

units::radian_t SubIMU::getRadian()
{
  
  return (units::radian_t)0;  
}