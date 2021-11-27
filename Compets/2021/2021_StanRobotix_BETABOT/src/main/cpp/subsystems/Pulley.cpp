// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Pulley.h"

Pulley::Pulley() = default;

// This method will be called once per scheduler run
void Pulley::Periodic() {}

void Pulley::Up()
{
    if(!mTopSwitch.Get())
    {
        mMotor.Set(0.1);
    }
}

void Pulley::Down()
{
    if(!mBottomSwitch.Get())
    {
        mMotor.Set(- 0.1);
    }
}