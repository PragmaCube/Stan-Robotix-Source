// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include "subsystems\SubElevator.h"
SubElevator::SubElevator() { }
// This method will be called once per scheduler run
void SubElevator::Periodic() {}
void SubElevator::Down()
{
    mMotorElevatorR.Set(speedDown);
    mMotorElevatorL.Set(-speedDown);
}

void SubElevator::Up()
{
    mMotorElevatorR.Set(speedUp);
    mMotorElevatorL.Set(-speedUp);
}

void SubElevator::Stop()
{
    mMotorElevatorR.Set(0);
    mMotorElevatorL.Set(0);
}

