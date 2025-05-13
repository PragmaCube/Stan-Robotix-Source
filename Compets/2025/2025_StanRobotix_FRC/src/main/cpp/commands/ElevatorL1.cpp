// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ElevatorL1.h"

ElevatorL1::ElevatorL1(SubElevator *iElevator)
{
  mSubElevator = iElevator;
  AddRequirements(mSubElevator);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void ElevatorL1::Initialize()
{
  mSetpoint = ElevatorConstants::Commands::kL1Setpoint;
}

// Called repeatedly when this Command is scheduled to run
void ElevatorL1::Execute()
{
  mSubElevator->SetPositionFeedForward(mSetpoint);
}

// Called once the command ends or is interrupted.
void ElevatorL1::End(bool interrupted) {}

// Returns true when the command should end.
bool ElevatorL1::IsFinished()
{
  return mSubElevator->AtSetpointFeedForward();
}