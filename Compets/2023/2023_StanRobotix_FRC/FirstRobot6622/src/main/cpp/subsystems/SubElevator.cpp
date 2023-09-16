// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubElevator.h"
#include "RobotContainer.h"

SubElevator::SubElevator(RobotContainer *iRobotContainer)
{
  mRobotContainer = iRobotContainer;

  resetPidData();

  Enable(kElevatorEnabled);
  EnableSubsystemLog(kLogElevator);
  EnablePerformanceLog(kLogPerf_ElevatorEnable);
}

void SubElevator::Init()
{
  if (isEnabled())
  {

  }
}

void SubElevator::setCommand(const int iPov, const bool iButtonUp, const bool iButtonDown)
{
  if (iPov == 180)
  {
    Stage(SubElevator::h0);
    mHeightManual = 0;
  }
  else if (iPov == 90)
  {
    Stage(SubElevator::h1);
    mHeightManual = 0;
  }
  else if (iPov == 0)
  {
    Stage(SubElevator::h2);
    mHeightManual = 0;
  }
  else if (iButtonUp)
  {
    Stage(SubElevator::hManual);
    mHeightManual = 1;
  }
  else if (iButtonDown)
  {
    Stage(SubElevator::hManual);
    mHeightManual = -1;
  }
  else
  {
    mHeightManual = 0;
  }
}

void SubElevator::resetPidData()
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

void SubElevator::Stage(eHeight iHeight)
{
  switch (iHeight)
  {
  case h0:
    mHeight_ = kMinHeight;
    break;

  case h1:
    mHeight_ = kHeightS1;
    break;

  case h2:
    mHeight_ = kHeightS2;
    break;
    
  case hManual:
    mHeight_= mHeight_+mHeightManual;
    break;

  default:
    mLMotorElevator.Set(0);
    mRMotorElevator.Set(0);
  }
  // TODO: executer ci-dessous si et seulement si la valeur change, 
    mRPIDController.SetReference(mHeight_,rev::ControlType::kSmartMotion); // ATTENTION, SIGNE - MIS SUR 1 DES 2 ARBITRAIREMENT !!!!!
    mLPIDController.SetReference(-mHeight_,rev::ControlType::kSmartMotion); // FAIRE DES TESTS POUR VOIR QUEL MOTEUR TOURNE DANS QUEL SENS !!!!!
}

void SubElevator::doExecute ()
{
  if (isEnabled())
  { // TODO: executer ci-dessous si et seulement si la valeur change, 
    mRPIDController.SetReference(mHeight_,rev::ControlType::kSmartMotion); // ATTENTION, SIGNE - MIS SUR 1 DES 2 ARBITRAIREMENT !!!!!
    mLPIDController.SetReference(-mHeight_,rev::ControlType::kSmartMotion); // FAIRE DES TESTS POUR VOIR QUEL MOTEUR TOURNE DANS QUEL SENS !!!!!
  }
}