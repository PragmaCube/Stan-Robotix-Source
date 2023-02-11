// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Date       Auteur       Description                                               Test
// 09Fev2023  Antoine T.   IMU                                                       ...
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "subsystems/SubIMU.h"
#include "Constants.h"

#include <iostream>

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
   ctre::phoenix::sensors::PigeonIMU::GeneralStatus status;

   gyro.GetGeneralStatus(status);

    static double ypr[3];
    gyro.GetYawPitchRoll(ypr);
    std::cout << "Yaw:" << ypr[0] << "Pitch :" << ypr[1] << "Roll " << ypr[2] <<std::endl;

    





}

float SubIMU::getAngle() 
{
  
    return 0.0;

}

units::radian_t SubIMU::getRadian()
{
  
  return (units::radian_t)0;  
}