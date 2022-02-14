// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include "subsystems/SubElevator.h"
SubElevator::SubElevator() = default;
// This method will be called once per scheduler run
void SubElevator::Periodic() {}
void SubElevator::Down()
{
    mMotorL1.Set(speedDown);
    mMotorR1.Set(-speedDown);
}

void SubElevator::Up()
{
    mMotorL1.Set(speedUp);
    mMotorR1.Set(-speedUp);
}

void SubElevator::Stop()
{
    mMotorL1.Set(0);
    mMotorR1.Set(0);
}