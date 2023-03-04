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

SubIMU::SubIMU()
{
    EnableSubsystemLog(kLogIMU);
    EnablePerformanceLog(kLogPerf_IMUEnable);
    Enable(kIMUEnabled);
    setLogPeriodity(kLogPeriod_260ms);
}

void SubIMU::Init()
{
    if (mIsEnabled)
    {
        mGyro = new ctre::phoenix::sensors::WPI_Pigeon2(0);
        mGyro->Calibrate();
        mGyro->Reset();

        double ypr[3] = {0.0f, 0.0f, 0.0f};

        mGyro->GetYawPitchRoll(ypr);

        mYawStart = ypr[0];
        mPitchStart = ypr[1];
        mRollStart = ypr[2];
    }
}

void SubIMU::doExecute()
{
    static int wNumberOfExecution = 0; // TODO: changer avec un timer

    static double ypr[3] = {0.0f, 0.0f, 0.0f};
    if (mIsEnabled)
    {
        mGyro->GetYawPitchRoll(ypr);
    }

    ypr[0] = ypr[0] - mYawStart;
    ypr[1] = ypr[1] - mPitchStart;
    ypr[2] = ypr[2] - mRollStart;

    if (((wNumberOfExecution % mLogPeriodicity) == 0) && mSubsystemLogEnabled)
    {
        std::cout << "Yaw:" << ypr[0] << "    Pitch :" << ypr[1] << "   Roll " << ypr[2] << std::endl;
    }
    wNumberOfExecution++;
}

double SubIMU::getAnglePitch()
{
    return ((mGyro->GetPitch()) - mPitchStart);
}
double SubIMU::getAngleYaw()
{
    return ((mGyro->GetYaw()) - mYawStart);
}
double SubIMU::getAngleRoll()
{
    return ((mGyro->GetRoll()) - mRollStart);
}

units::radian_t SubIMU::getRadian()
{
    units::radian_t mAngle{getAngleYaw()};
    return mAngle;
}

void SubIMU::ResetGlobal()
{
    double ypr[3] = {0.0f, 0.0f, 0.0f};
    mGyro->GetYawPitchRoll(ypr);
    mYawStart = ypr[0];
    mPitchStart = ypr[1];
    mRollStart = ypr[2];
}

frc::Rotation2d SubIMU::getRotation2d()
{
    return -mGyro->GetRotation2d();
}
