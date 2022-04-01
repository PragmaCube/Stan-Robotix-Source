#include "subsystems/LaunchSystem.h"

#include <iostream>
LaunchSystem::LaunchSystem() = default;

// This method will be called once per scheduler run
void LaunchSystem::Periodic() {}

void LaunchSystem::Launch()
{
    mLaunchMotor.Set(0.6);
}

void LaunchSystem::LaunchStop()
{
    mLaunchMotor.Set(0);
}

void LaunchSystem::Collect()
{
    mCollectMotor.Set(-0.90);
}

void LaunchSystem::CollectReverse()
{
    mCollectMotor.Set(0.50);
}

void LaunchSystem::CollectStop()
{
    mCollectMotor.Set(0);
}