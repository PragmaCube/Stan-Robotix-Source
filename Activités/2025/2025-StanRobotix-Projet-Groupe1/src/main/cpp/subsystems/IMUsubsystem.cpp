// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/IMUsubsystem.h"


IMUsubsystem::IMUsubsystem()
{
    mIMU = new ctre::phoenix6::hardware::Pigeon2(IMUConstants::kPortIMU);
}

double IMUsubsystem::GetYawAxis()
{
    return mIMU->GetYaw().GetValue().value();
}
// This method will be called once per scheduler run
void IMUsubsystem::Periodic() {}
