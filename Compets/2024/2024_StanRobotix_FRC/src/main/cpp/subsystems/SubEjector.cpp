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
            mMotorEjector.Set(EjectorConstants::kSpeedPull*mvitesse);
            break;
        case eOut:
            mMotorEjector.Set(EjectorConstants::kSpeedPush*mvitesse);
            break;
        default:
            mMotorEjector.Set(0);
    }
}
void SubEjector::In(double ivitesse)
{
    mState=eIn;
    mvitesse = ivitesse;
}
void SubEjector::Out(double ivitesse)
{
    mState=eOut;
    mvitesse = ivitesse;
}
void SubEjector::Stop()
{
    mState=eStop;
}
void SubEjector::Init() { }