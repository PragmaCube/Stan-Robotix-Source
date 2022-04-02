// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include "subsystems\SubElevator.h"

SubElevator::SubElevator() { }
// This method will be called once per scheduler run
void SubElevator::Periodic() {}

void SubElevator::Down(Climber iPosition)
{
    switch (iPosition)
    {
    case eLeftClimber:
        mLMotorElevator.Set(-kSpeedDown);

        break;

    case eRightClimber:
        mRMotorElevator.Set(kSpeedDown);

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
        mLMotorElevator.Set(-kSpeedUp);

        break;

    case eRightClimber:
        mRMotorElevator.Set(kSpeedUp);

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

