// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubCoralIntake.h"

SubCoralIntake::SubCoralIntake() {
    mCoralIntakeMotor = new rev::spark::SparkMax (CoralConstants::Intake::kMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless);
}

// This method will be called once per scheduler run
void SubCoralIntake::Periodic() {}

void SubCoralIntake::Intake(){
    mCoralIntakeMotor->Set(0.3);
}

void SubCoralIntake::Outtake(){
    mCoralIntakeMotor->Set(-0.3);
}