// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubUltrasonic.h"

SubUltrasonic::SubUltrasonic() = default;

// This method will be called once per scheduler run
void SubUltrasonic::Periodic() {}

float SubUltrasonic::getDistance()
{
    double rawValue = ultrasonic.GetValue();

    double voltage_scale_factor = 5/frc::RobotController::GetVoltage5V();

    //double currentDistanceCentimeters = rawValue * voltage_scale_factor * 0.125;
    double currentDistanceInches = rawValue * voltage_scale_factor * 0.0492;
    return currentDistanceInches; 
}
