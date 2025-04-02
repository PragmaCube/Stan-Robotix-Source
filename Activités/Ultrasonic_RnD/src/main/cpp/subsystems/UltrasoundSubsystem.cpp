// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/UltrasoundSubsystem.h"
#include "Constants.h"

#include <iostream>

UltrasoundSubsystem::UltrasoundSubsystem() {
    mUltrasonic = new frc::AnalogInput{UltrasonicConstants::kUltrasonicChannel};
    mPot = new frc::AnalogPotentiometer{mUltrasonic, UltrasonicConstants::kUltrasonicFullRange, UltrasonicConstants::kUltrasonicOffset};
}

// This method will be called once per scheduler run
void UltrasoundSubsystem::Periodic() {
    std::cout << "Voltage:" << getVoltage() << std::endl;
    std::cout << "Valeur: " << getValue() << std::endl;
    // std::cout << "Valeur convertie:" << valueToInch(double(getValue())) << std::endl;
    std::cout << "Valeur de mPot:" << getPot() << std::endl;
}

double UltrasoundSubsystem::getVoltage() {
    return mUltrasonic->GetVoltage();
}

double UltrasoundSubsystem::getValue() {
    return double(mUltrasonic->GetValue())/58.0;
}

double UltrasoundSubsystem::getPot() {
    return mPot->Get();
}

/*double UltrasoundSubsystem::valueToInch(double value) {
    return (14.0 / 3617.0) * value + (18496.0 / 3617.0);
}*/
