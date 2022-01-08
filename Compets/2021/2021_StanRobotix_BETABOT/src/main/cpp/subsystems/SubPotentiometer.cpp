// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubPotentiometer.h"

SubPotentiometer::SubPotentiometer() = default;

// This method will be called once per scheduler run
void SubPotentiometer::Periodic() {}

void SubPotentiometer::SimulationPeriodic() {}

double SubPotentiometer::getDistance()
{/*
    double mDistance = 0;
    for (int i = 0; i < 4 ; i++)
    {
        mDistance += ultrasonic.GetValue()
    }
    return mDistance/4;*/
    double raw_value = ultrasonic.GetValue();
    double voltage_scale_factor = 5/frc::RobotController::GetVoltage5V();
    //double currentDistanceCentimeters = raw_value * voltage_scale_factor * 0.125;
    double currentDistanceInches = raw_value * voltage_scale_factor * 0.0492;
    return currentDistanceInches;
}