// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubEjector.h"

#include <iostream>

SubEjector::SubEjector()
{
    mRPIDController.SetP(kP);
    mLPIDController.SetP(kP);
    mRPIDController.SetI(kI);
    mLPIDController.SetI(kI);
    mRPIDController.SetD(kD);
    mLPIDController.SetD(kD);
    mRPIDController.SetIZone(kIz);
    mLPIDController.SetIZone(kIz);
    mRPIDController.SetFF(kFF);
    mLPIDController.SetFF(kFF);
    mRPIDController.SetOutputRange(kMinOutput, kMaxOutput);
    mLPIDController.SetOutputRange(kMinOutput, kMaxOutput);

    mRPIDController.SetSmartMotionMaxVelocity(kMaxVel);
    mLPIDController.SetSmartMotionMaxVelocity(kMaxVel);
    mRPIDController.SetSmartMotionMinOutputVelocity(kMinVel);
    mLPIDController.SetSmartMotionMinOutputVelocity(kMinVel);
    mRPIDController.SetSmartMotionMaxAccel(kMaxAcc);
    mLPIDController.SetSmartMotionMaxAccel(kMaxAcc);
    mRPIDController.SetSmartMotionAllowedClosedLoopError(kAllErr);
    mLPIDController.SetSmartMotionAllowedClosedLoopError(kAllErr);
}

// This method will be called once per scheduler run
void SubEjector::Periodic() {}

void SubEjector::Push()
{
    //mRMotorElevator.Set(-kSpeedPush);
    //mLMotorElevator.Set(kSpeedPush);
    mRPIDController.SetReference(-kPosOut,rev::ControlType::kSmartMotion);
    mLPIDController.SetReference(kPosOut,rev::ControlType::kSmartMotion);
    
}

void SubEjector::Periodic(const bool iButtonPressed)
{
  static bool ejector_in_use = false;
  
  if (iButtonPressed && !ejector_in_use)
  {
    ejector_in_use = true;
    std::cout << "Pressed A Button" << std::endl;
  }

  if (ejector_in_use)
  {
    if (GetEncoder() < kPosOut)
    {
      this->Push();
    }
    else
    {
      Pull();
      ejector_in_use = false;
    }
  }   
}

void SubEjector::Pull()
{
    //mRMotorElevator.Set(-kSpeedPull);
    //mLMotorElevator.Set(kSpeedPull);
    mRPIDController.SetReference(-kPosIn,rev::ControlType::kSmartMotion);
    mLPIDController.SetReference(kPosIn,rev::ControlType::kSmartMotion);
    
}

void SubEjector::Stop()
{
    mRMotorElevator.Set(0);
    mLMotorElevator.Set(0);
}

double SubEjector::GetEncoder()
{
    return (mLMotorEncoder.GetPosition() - mRMotorEncoder.GetPosition())/2;
}