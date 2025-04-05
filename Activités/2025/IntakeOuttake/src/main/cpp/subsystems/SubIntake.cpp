// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubIntake.h"
#include "Constants.h"

SubIntake::SubIntake() {
    mSparkMax = new rev::spark::SparkMax{SubIntakeConstants::kSubIntakeDeviceId, rev::spark::SparkLowLevel::MotorType::kBrushless};
}

// This method will be called once per scheduler run
void SubIntake::Periodic() {}
