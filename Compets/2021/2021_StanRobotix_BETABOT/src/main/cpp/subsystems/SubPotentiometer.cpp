// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubPotentiometer.h"

SubPotentiometer::SubPotentiometer() = default;

// This method will be called once per scheduler run
void SubPotentiometer::Periodic() {}

void SubPotentiometer::SimulationPeriodic() {}

double SubPotentiometer::getDistance()
{
    return pot.Get();
}