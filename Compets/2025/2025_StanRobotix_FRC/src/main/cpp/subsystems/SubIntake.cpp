// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <iostream>
#include "subsystems/SubIntake.h"

SubIntake::SubIntake() {
    motorIntake = new rev::spark::SparkMax (IntakeConstants::kIntakeMotorPort, rev::spark::SparkLowLevel::MotorType::kBrushless);
};

// This method will be called once per scheduler run
void SubIntake::Periodic() {}

void SubIntake::ChangeRotation() {
    rotation = !rotation;
}

void SubIntake::Start() {
    motorIntake->Set(IntakeConstants::kIntakeSpeed);

    if (rotation) {
        motorIntake->Set(IntakeConstants::kNegativeIntakeSpeed);
    };

    std::cout << "start" << std::endl;

}

void SubIntake::Stop() {
    motorIntake->StopMotor();
        std::cout << "stop" << std::endl;

}

bool SubIntake::getRotation() {
    return rotation;
        std::cout << "rotate" << std::endl;

}