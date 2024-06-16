// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ElevatorDown.h"

ElevatorDown::ElevatorDown(SubElevator *iElevator) {

  mElevator = iElevator;
  AddRequirements(mElevator);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void ElevatorDown::Initialize() 
{
  mElevator->setEnable(false);
  mElevator->setTargetPosition(ElevatorConstants::kElevatorLimitDown);
}

// Called repeatedly when this Command is scheduled to run
void ElevatorDown::Execute() 
{
  mElevator->setElevatorPosition();
}

// Called once the command ends or is interrupted.
void ElevatorDown::End(bool interrupted) 
{
  mElevator->setEnable(true);
}

// Returns true when the command should end.
bool ElevatorDown::IsFinished() 
{
  return (std::abs(mElevator->getEncoderPositionMotor(Motor1) - mElevator->getTargetPosition()) < 0.05);
}