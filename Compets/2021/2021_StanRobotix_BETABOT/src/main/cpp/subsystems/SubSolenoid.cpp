// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubSolenoid.h"

SubSolenoid::SubSolenoid() = default;

// This method will be called once per scheduler run
void SubSolenoid::Periodic() {}

void SubSolenoid::SwitchState()
{
    mPiston.Set(!mPiston.Get());
}