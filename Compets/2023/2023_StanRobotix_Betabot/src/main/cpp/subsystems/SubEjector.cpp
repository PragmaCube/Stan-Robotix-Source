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

void SubEjector::Set(eSpeeds iSpeed)
{
    switch (iSpeed)
    {
    case eForwards:
        mMotorElevator.Set(EjectorConstants::kSpeedPush);
        break;
    case eBackwards:
        mMotorElevator.Set(EjectorConstants::kSpeedPull);
        break;
    case eStop:
        mMotorElevator.Set(0);
        break;
    default:
        mMotorElevator.Set(0);
        break;
    }
}