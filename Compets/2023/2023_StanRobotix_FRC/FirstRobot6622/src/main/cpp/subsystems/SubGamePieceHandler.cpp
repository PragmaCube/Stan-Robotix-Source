// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubGamePieceHandler.h"
#include "Constants.h"

#include <iostream>

SubGamePieceHandler::SubGamePieceHandler()
{
    EnableSubsystemLog(kLogGamePieceHandler);
    EnablePerformanceLog(kLogPerf_GamePieceHandlerEnable);
    Enable(kGamePieceHandlerEnabled);

    setLogPeriodity(kLogPeriod_260ms);
}

void SubGamePieceHandler::Extract()
{
    if (mState != eExtract)
    {
        mRequestedPowerLeft = -kFullPower;
        mRequestedPowerRight= kFullPower;
        mState = eExtract;
        mIsUpdated = true;
    }
}

void SubGamePieceHandler::Retract()
{
    if (mState != eRetract)
    {
        mRequestedPowerLeft = kFullPower;
        mRequestedPowerRight= -kFullPower;
        mState = eRetract;
        mIsUpdated = true;
    }
}

void SubGamePieceHandler::Stop()
{
    if (mState != eRetract)
    {
        mRequestedPowerLeft = kNoPower;
        mRequestedPowerRight= kNoPower;
        mState = eStop;
        mIsUpdated = true;
    }
}

// This method will be called once per scheduler run
void SubGamePieceHandler::doExecute()
{
    if (mIsEnabled && mIsUpdated)
    {
       mMotorRight->Set(mRequestedPowerLeft);
       mMotorRight->Set(mRequestedPowerRight);
       mIsUpdated = false;
       if (mSubsystemLogEnabled)
       {
        std::cout << "Sub GamePieceHandler\nStatus : " << mState << std::endl;
       }
    }
}

void SubGamePieceHandler::Init()
{
    if (mIsEnabled)
    {
        mMotorRight = new rev::CANSparkMax(kCanIdGamePieceHandlerR, rev::CANSparkMax::MotorType::kBrushless);
        mMotorLeft = new rev::CANSparkMax(kCanIdGamePieceHandlerL, rev::CANSparkMax::MotorType::kBrushless);
    }
}
