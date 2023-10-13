// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubPneumatic.h"
#include "Constants.h"

#include <iostream>

SubPneumatic::SubPneumatic() {}

SubPneumatic::~SubPneumatic() {}

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
    if (mState == eRetract)
    {

      std::cout << "extrct" << std::endl;

      mState = eExtract;
    }
    else
    {

      std::cout << "Retrct" << std::endl;

      mState = eRetract;
    }
}

void SubPneumatic::doExecute()
{

    std::cout << "SubPneumatic\nStatus : " << mState << std::endl;

}