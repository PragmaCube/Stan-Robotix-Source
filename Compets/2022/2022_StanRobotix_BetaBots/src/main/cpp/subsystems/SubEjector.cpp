// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubEjector.h"

#include <iostream>
//#define DISPLAY_EJECTOR_LOG 1
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
    mRPIDController.SetReference(-kPosOut,rev::ControlType::kSmartMotion);
    mLPIDController.SetReference(kPosOut,rev::ControlType::kSmartMotion);
    
}

void SubEjector::Periodic(const bool iButtonPressed)
{
  if ((mCurrentState == inactive ) && iButtonPressed)
  {
  #ifdef DISPLAY_EJECTOR_LOG
    std::cout << "Inactive" << std::endl;
  #endif
    Push();
     mCurrentState = pushing;
  }

  if ((mCurrentState == pushing) && (GetEncoder() > kPosOut))
  {
  #ifdef DISPLAY_EJECTOR_LOG
    std::cout << "pushing" << std::endl;
  #endif
    mCurrentState = pulling;
  } 

  if (mCurrentState == pulling)
  {
  #ifdef DISPLAY_EJECTOR_LOG
    std::cout << "pulling" << std::endl;
  #endif
    Pull();
    mCurrentState = WaitingButtonReleased;
  }

  if (mCurrentState == WaitingButtonReleased && !iButtonPressed)
  {
  #ifdef DISPLAY_EJECTOR_LOG
    std::cout << "WaitingButtonReleased" << std::endl;
  #endif
    mCurrentState = inactive;
  }
}

bool SubEjector::isOperationCompleted()
{
    return mCurrentState == inactive;
}

void SubEjector::Pull()
{
    mRPIDController.SetReference(-kPosIn,rev::ControlType::kSmartMotion);
    mLPIDController.SetReference(kPosIn,rev::ControlType::kSmartMotion);  
}

double SubEjector::GetEncoder()
{
    return (mLMotorEncoder.GetPosition() - mRMotorEncoder.GetPosition())/2;
}
