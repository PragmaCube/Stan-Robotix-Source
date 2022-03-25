#include "subsystems/LaunchSystem.h"

#include <iostream>
LaunchSystem::LaunchSystem() = default;

// This method will be called once per scheduler run
void LaunchSystem::Periodic() {}

void LaunchSystem::Launch()
{
    mLaunchMotor.Set(1);
}

void LaunchSystem::LaunchStop()
{
    mLaunchMotor.Set(0);
}

void LaunchSystem::Collect()
{
    mCollectMotor.Set(-1);
}

void LaunchSystem::CollectReverse()
{
    mCollectMotor.Set(1);
}

void LaunchSystem::CollectStop()
{
    mCollectMotor.Set(0);
}