// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubEjector.h"

SubEjector::SubEjector() = default;

// This method will be called once per scheduler run
void SubEjector::Periodic() 
{}

void SubEjector::On(double speed)
{
    mMotorArm.Set(-speed);
    state = true;
}

void SubEjector::Off()
{
    mMotorArm.Set(0);
    state = false;
}

bool SubEjector::IsRunning()
{
    return state;
}