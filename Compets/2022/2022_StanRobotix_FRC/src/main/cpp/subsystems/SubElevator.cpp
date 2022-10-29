// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include "subsystems\SubElevator.h"

SubElevator::SubElevator() {}

// This method will be called once per scheduler run
void SubElevator::Periodic() {}

void SubElevator::Down(Climber iPosition)
{
    switch (iPosition)
    {
    case eLeftClimber:
        if (SubElevator::GetEncoderPosition(SubElevator::Encoder::eLeftEncoder) > kMinHeight)
        {
            mLMotorElevator.Set(-kSpeedDown);   
        }
        else
        {
            mLMotorElevator.Set(0);
        }
        break;

    case eRightClimber:
        if (SubElevator::GetEncoderPosition(SubElevator::Encoder::eRightEncoder) > kMinHeight)
        {
            mRMotorElevator.Set(-kSpeedDown);
        }
        else
        {
            mRMotorElevator.Set(0);
        }
        break;
    
    default:
        mRMotorElevator.Set(0);
        mLMotorElevator.Set(0);

        break;
    }
    
}

void SubElevator::Up(Climber iPosition)
{
    switch (iPosition)
    {
    case eLeftClimber:
        if (SubElevator::GetEncoderPosition(SubElevator::Encoder::eLeftEncoder) < kMaxHeight)
        {
            mLMotorElevator.Set(-kSpeedUp);
        }
        else
        {
            mLMotorElevator.Set(0);
        }
        break;

    case eRightClimber:
        if (SubElevator::GetEncoderPosition(SubElevator::Encoder::eRightEncoder) < kMaxHeight)
        {
            mRMotorElevator.Set(-kSpeedUp);
        }
        else
        {
            mRMotorElevator.Set(0);
        }
        break;
    
    default:
        mRMotorElevator.Set(0);
        mLMotorElevator.Set(0);

        break;
    }
}

void SubElevator::Stop(Climber iPosition)
{
    switch (iPosition)
    {
    case eLeftClimber:
        mLMotorElevator.Set(0);
        break;

    case eRightClimber:
        mRMotorElevator.Set(0);
        break;

    default:
        mRMotorElevator.Set(0);
        mLMotorElevator.Set(0);
        break;
    }
}

int SubElevator::GetEncoderPosition(Encoder iSide)
{
    switch (iSide)
    {
    case eRightEncoder:
        return -(int(mRMotorEncoder.GetPosition()));
        break;
    
    case eLeftEncoder:
        return -(int(mLMotorEncoder.GetPosition()));
        break;

    default:
        return 0;
        break;
    }
}

