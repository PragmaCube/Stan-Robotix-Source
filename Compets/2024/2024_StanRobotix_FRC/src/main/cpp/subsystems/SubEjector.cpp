// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubEjector.h"

SubEjector::SubEjector() = default;

// This method will be called once per scheduler run
void SubEjector::Periodic() {
    // mProximity = mColorSensor.GetProximity();
    switch (mState)
    {
        case eIn:
            mMotorEjector.Set(EjectorConstants::kSpeedIn);
            break;
        case eOutUp:
            mMotorEjector.Set(EjectorConstants::kSpeedOutUp);
            break;
        case eOutDown:
            mMotorEjector.Set(EjectorConstants::kSpeedOutDown);
            break;
        default:
            mMotorEjector.Set(0);
    }
}
void SubEjector::In()
{
    mState = eIn;
}
void SubEjector::OutUp()
{
    mState = eOutUp;
}
void SubEjector::OutDown()
{
    mState = eOutDown;
}
void SubEjector::Stop()
{
    mState = eStop;
}

void SubEjector::Init() { }