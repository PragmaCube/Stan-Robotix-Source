// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ElevatorSetpoint.h"

ElevatorSetpoint::ElevatorSetpoint(SubElevator *iElevator, ElevatorLevels iLevel)
{
  mSubElevator = iElevator;
  AddRequirements(mSubElevator);
  mLevel = iLevel;
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void ElevatorSetpoint::Initialize()
{
  switch(mLevel)
  {
    case L1:
      mSetpoint = ElevatorConstants::Commands::kL1Setpoint;
      break;
    case L2:
      mSetpoint = ElevatorConstants::Commands::kL2Setpoint;
      break;
    case L3:
      mSetpoint = ElevatorConstants::Commands::kL3Setpoint;
      break;
    case L4:
      mSetpoint = ElevatorConstants::Commands::kL4Setpoint;
      break;
    case CoralSource:
      mSetpoint = ElevatorConstants::Commands::kCoralSourceSetpoint;
      break;
    default:
      mSetpoint = 0_rad;
  }
}

// Called repeatedly when this Command is scheduled to run
void ElevatorSetpoint::Execute()
{
  mSubElevator->SetPositionFeedForward(mSetpoint);
}

// Called once the command ends or is interrupted.
void ElevatorSetpoint::End(bool interrupted) {}

// Returns true when the command should end.
bool ElevatorSetpoint::IsFinished()
{
  return mSubElevator->AtSetpointFeedForward();
}