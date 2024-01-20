// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubEjector.h"

SubEjector::SubEjector() = default;

// This method will be called once per scheduler run
void SubEjector::Periodic() {
    mProximity = mColorSensor.GetProximity();
    switch (mState)
    {
        case eIn:
            
            if(mProximity !=0 && mProximity < EjectorConstants::kInProximity)
            {
                mState=eStop;
            }
            else
            {
                mMotorEjector.Set(EjectorConstants::kSpeedPull);
            }
            break;
        case eOut:
            mMotorEjector.Set(EjectorConstants::kSpeedPush);
            break;
        default:
            mMotorEjector.Set(0);


    }
}
void SubEjector::In()
{
    mState=eIn;
}
void SubEjector::Out()
{
    mState=eOut;
}
void SubEjector::Stop()
{
    mState=eStop;
}
void SubEjector::Init() { }