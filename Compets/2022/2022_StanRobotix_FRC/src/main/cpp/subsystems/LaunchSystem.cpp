// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/LaunchSystem.h"
#include <iostream>
LaunchSystem::LaunchSystem() = default;

// This method will be called once per scheduler run
void LaunchSystem::Periodic() {}

void LaunchSystem::Run(bool iButton, LauncherSpeed iMotorSpeed)
{
    if (iButton)
    {
        switch (iMotorSpeed)
        {
        case eSlow:
            mLaunchMotor.Set(0.85);
            break;

        case eFast:
            mLaunchMotor.Set(1);
            break;

        default:
            mLaunchMotor.Set(0);
            break;
        }
    }

    else
    {
      mLaunchMotor.Set(0);
    }
    
}
