// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubEjector.h"

#include <iostream>

SubEjector::SubEjector() 
{
   
}

// This method will be called once per scheduler run
void SubEjector::Periodic() {}

frc2::CommandPtr SubEjector::SubEjectorMethodCommand() {
  // Inline construction of command goes here.
  // Subsystem::RunOnce implicitly requires `this` subsystem.
  return RunOnce([/* this */] { /* one-time action goes here */ });
}

void SubEjector::SetRoll(int roll)
{
  Roll = roll;
}

int SubEjector::GetRoll()
{
  return Roll;
}

void SubEjector::Set(eSpeeds iSpeed, double Coefficient)
{
    
    switch (iSpeed)
    {
    case eForwards:
          mMotorElevator.Set(EjectorConstants::kSpeedPush*Coefficient);
          std::cout << EjectorConstants::kSpeedPush*Coefficient << std::endl;
        break;
    case eBackwards:
          mMotorElevator.Set(EjectorConstants::kSpeedPull*Coefficient);
          std::cout << -EjectorConstants::kSpeedPush*-Coefficient << std::endl;
        break;
    case eStop:
        mMotorElevator.Set(0);
        std::cout << "stop" << std::endl;
        break;
    default:
        mMotorElevator.Set(0);
        break;
    }
}


float SubEjector::GetMoveState()
{
  return MoveState;
}

void SubEjector::SetMoveState(bool MoveStateToSet)
{
  MoveState=MoveStateToSet;

}