// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubDoor.h"

SubDoor::SubDoor() {
    mSparkMax = new rev::spark::SparkMax{DoorConstants::kSparkMaxDeviceID, rev::spark::SparkLowLevel::MotorType::kBrushless};
    mPID = new frc::PIDController{DoorConstants::kP, DoorConstants::kI, DoorConstants::kD};
};

// This method will be called once per scheduler run
void SubDoor::Periodic() {}

void SubDoor::Open() {
    mSparkMax->Set(1.0);
}

void SubDoor::Close() {
    mSparkMax->Set(-1.0);
}
