// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubEjector.h"

SubEjector::SubEjector() = default;

// This method will be called once per scheduler run
void SubEjector::Periodic() {}

frc2::CommandPtr SubEjector::SubEjectorMethodCommand() {
  // Inline construction of command goes here.
  // Subsystem::RunOnce implicitly requires `this` subsystem.
  return RunOnce([/* this */] { /* one-time action goes here */ });
}
void SubEjector::Forward()
{
    mMotorElevator.Set(OperatorConstants::kSpeedPush);
}

void SubEjector::Backward()
{
    mMotorElevator.Set(-OperatorConstants::kSpeedPull);
}

void SubEjector::Stop()
{
    mMotorElevator.Set(0);
}

