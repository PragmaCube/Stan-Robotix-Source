// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubPneumatic.h"
#include "Constants.h"

SubPneumatic::SubPneumatic() = default;

// This method will be called once per scheduler run
void SubPneumatic::Init()
{
    Retract();
 }
void SubPneumatic::Extract()
{
  mDoubleSolenoid.Set(frc::DoubleSolenoid::Value::kForward);
  mState = eExtract;
}
void SubPneumatic::Retract()
{
  mDoubleSolenoid.Set(frc::DoubleSolenoid::Value::kReverse);
  mState = eRetract;
}
void SubPneumatic::Toggle()
{
    mDoubleSolenoid.Toggle();
}


