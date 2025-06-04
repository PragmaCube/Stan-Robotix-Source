// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubDoor.h"
#include <cmath>

SubDoor::SubDoor() {
    mSparkMax = new rev::spark::SparkMax{DoorConstants::kSparkMaxDeviceID, rev::spark::SparkLowLevel::MotorType::kBrushless};
};

// This method will be called once per scheduler run
void SubDoor::Periodic() {}

double SubDoor::GetAngle()
{
    return (mSparkMax->GetEncoder().GetPosition() + DoorConstants::kOffset) / DoorConstants::gearRatio * 2 * std::numbers::pi;
}

void SubDoor::Stop()
{
    mSparkMax->StopMotor();
}

void SubDoor::SetVoltage(units::volt_t iVoltage){
    mSparkMax->SetVoltage(iVoltage);
}

void SubDoor::CounterGravity()
{
    double pivotAngle = GetAngle();
    mSparkMax->SetVoltage(units::voltage::volt_t(DoorConstants::kG * cos(pivotAngle)));
}