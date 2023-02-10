// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Solenoid.h"

SubSolenoid::SubSolenoid() = default;

// This method will be called once per scheduler run
void SubSolenoid::Periodic() {}

void SubSolenoid::SwitchCompressorState()
{
    if(mCompressorState)
    {
        mCompressor.Start();
    }

    else
    {
        mCompressor.Stop();
    }

    mCompressorState = !mCompressorState;   
}

void SubSolenoid::SwitchPistonState()
{
    if(mState)
    {
        mPiston.Set(frc::DoubleSolenoid::kForward);
    }

    else
    {
        mPiston.Set(frc::DoubleSolenoid::kReverse);   
    }
    
    mState = !mState;    
}

void SubSolenoid::SetInactive()
{
    mCompressor.Stop();
}