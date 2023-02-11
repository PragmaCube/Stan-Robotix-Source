// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Date       Auteur       Description                                               Test
// 09Fev2023  Antoine T.   IMU Version initiale                                      ...
// 11Fev2023  Andre W.     Remplacement avec Pigeon 2.0
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "subsystems/SubIMU.h"
#include "Constants.h"

#include <iostream>

SubIMU *SubIMU::mSingleton = nullptr;

SubIMU::SubIMU()
{
   mGyro = new ctre::phoenix::sensors::WPI_Pigeon2(0);
   mGyro->Calibrate();
   mGyro->Reset();
}

SubIMU::~SubIMU() {}

SubIMU *SubIMU::getInstance()
{
    if (mSingleton == nullptr)
    {
        mSingleton = new SubIMU();
    }
    return mSingleton;
}

void SubIMU::Enable(bool iEnable)
{
    mIsEnable = iEnable;
}

void SubIMU::Periodic()
{
    static int mNumberOfExecution = 0;
    static bool wRunOnce = false;
    if (!wRunOnce)
    {
          double ypr[3];
          mGyro->GetYawPitchRoll(ypr);
          mYawStart   = ypr[0];
          mPitchStart = ypr[1];
          mRollStart  = ypr[2];

          wRunOnce = true;
    }
  
    //ctre::phoenix::sensors::Pigeon2::GeneralStatus status;
    //mGyro->GetGeneralStatus(status);
    
    static double ypr[3];
    mGyro->GetYawPitchRoll(ypr);
    ypr[0] = ypr[0] - mYawStart;
    ypr[1] = ypr[1] - mPitchStart;
    ypr[2] = ypr[2] - mRollStart;

    if (mNumberOfExecution % 25 == 0 and kLogIMU)
    {
        std::cout << "Yaw:" << ypr[0] << "    Pitch :" << ypr[1] << "   Roll " << ypr[2] << std::endl;
    }
    mNumberOfExecution++;
}

double SubIMU::getAngle()
{
    return (mGyro->GetYaw()-mYawStart);
}

units::radian_t SubIMU::getRadian()
{
    units::radian_t mAngle{getAngle()};
    return mAngle;
}

void SubIMU::ResetYaw()
{
    mGyro->Reset();
}

frc::Rotation2d SubIMU::getRotation2d()
{
    return mGyro->GetRotation2d();
}