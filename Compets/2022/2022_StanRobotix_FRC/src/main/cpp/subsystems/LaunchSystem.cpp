// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/LaunchSystem.h"
#include <iostream>
LaunchSystem::LaunchSystem() = default;

// This method will be called once per scheduler run
void LaunchSystem::Periodic() {}

void LaunchSystem::Run(bool iButton, double iLauncherSpeed)
{
    if (iButton)
    {
        mLaunchMotor.Set(iLauncherSpeed);
        std::cout << "on" << std::endl;
    }

    else
    {
        mLaunchMotor.Set(0);
        std::cout << "off" << std::endl;
    }
}

void LaunchSystem::SetSpeedLauncher(int iLauncherIndex)
{
if (iLauncherIndex == 3)
  {
    double mLauncherSpeed = 0.7;
  }
  if (iLauncherIndex == 4)
  {
    double mLauncherSpeed =0.3;
  }
}