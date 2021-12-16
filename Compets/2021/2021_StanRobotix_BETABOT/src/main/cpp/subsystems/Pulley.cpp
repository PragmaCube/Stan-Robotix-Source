// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Pulley.h"

SubPulley::SubPulley() = default;

// This method will be called once per scheduler run
void SubPulley::Periodic() {}

void SubPulley::Up()
{
    mMotor.Set(0.35);
}

void SubPulley::Down()
{
    mMotor.Set(- 0.25);
}

void SubPulley::setInactive()
{
    mMotor.Set(0);
}