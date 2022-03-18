// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include "subsystems/SubElevator.h"
SubElevator::SubElevator() { }
// This method will be called once per scheduler run
void SubElevator::Periodic() {}
void SubElevator::Down()
{
    mMotorElevator.Set(speedDown);
}

void SubElevator::Up()
{
    mMotorElevator.Set(speedUp);
}

void SubElevator::Stop()
{
    mMotorElevator.Set(0);
}