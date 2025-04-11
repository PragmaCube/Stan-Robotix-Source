// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubIntake.h"
#include "Constants.h"

SubIntake::SubIntake() {
    mSparkMax = new rev::spark::SparkMax{SubIntakeConstants::kSubIntakeDeviceId, rev::spark::SparkLowLevel::MotorType::kBrushless};
}
void SubIntake::Intake() {
    mSparkMax->Set(SubIntakeConstants::kSubIntakeForceMul);
}

void SubIntake::Outtake() {
    mSparkMax->Set(-SubIntakeConstants::kSubIntakeForceMul);
}

void SubIntake::StopMotor() {
    mSparkMax->Set(0.0);
}

// This method will be called once per scheduler run
void SubIntake::Periodic() {}
