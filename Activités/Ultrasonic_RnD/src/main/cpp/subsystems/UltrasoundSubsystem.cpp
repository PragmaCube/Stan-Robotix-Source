// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/UltrasoundSubsystem.h"
#include "Constants.h"

#include <iostream>

UltrasoundSubsystem::UltrasoundSubsystem() {
    mUltrasonic = new frc::AnalogInput{UltrasonicConstants::kUltrasonicChannel};
};

// This method will be called once per scheduler run
void UltrasoundSubsystem::Periodic() {
    std::cout << getVoltage();
    std::cout << getValue();
}

double UltrasoundSubsystem::getVoltage() {
    return mUltrasonic->GetVoltage();
}

int UltrasoundSubsystem::getValue() {
    return mUltrasonic->GetValue();
}
