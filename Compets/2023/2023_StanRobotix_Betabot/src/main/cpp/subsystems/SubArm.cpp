// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubArm.h"


SubArm::SubArm() = default;

// This method will be called once per scheduler run
void SubArm::Periodic() {}

void SubArm::Init()
{
    mArmTab.Add("Position Up", 1)
           .WithWidget("Number Slider")
           .GetEntry();
    mArmTab.Add("Position Down", 0)
           .WithWidget("Number Slider")
           .GetEntry();
    mArmTab.Add("Current Position", CurrentPosition())
           .WithWidget("Number Bar")
           .GetEntry();
    mArmTab.Add("Current Speed", CurrentSpeed())
           .WithWidget("Number Bar")
           .GetEntry();
}

void SubArm::PosDown()
{
    mPIDArmController.SetReference(ArmConstants::kPositionDown, rev::ControlType::kSmartMotion);
}

void SubArm::PosUp()
{
    mPIDArmController.SetReference(ArmConstants::kPositionUp, rev::ControlType::kSmartMotion);
}

void SubArm::Move(float iValue)
{
    mMotorArm.Set(iValue);
}

double SubArm::CurrentPosition()
{
    return mMotorArmEncoder.GetPosition();
}

double SubArm::CurrentSpeed()
{
    return mMotorArm.Get();
}