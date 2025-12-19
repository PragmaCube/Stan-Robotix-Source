// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubEjectorCAN.h"

SubEjectorCAN::SubEjectorCAN() = default;

// This method will be called once per scheduler run
void SubEjectorCAN::Periodic() {}

void SubEjectorCAN::Rotate(bool iDirection)
{
    if (iDirection)
    {
        mMotor.Set(EjectorConstants::kEjectorSpeed);
    }

    else
    {
        mMotor.Set(- EjectorConstants::kEjectorSpeed);
    }
}

void SubEjectorCAN::Stop()
{
    mMotor.Set(0);
}