// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ElevatorUp.h"

ElevatorUp::ElevatorUp(SubElevator *iElevator) {

  mElevator = iElevator;
  AddRequirements(mElevator);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void ElevatorUp::Initialize() 
{
  mElevator->setEnable(false);
  mElevator->setTargetPosition(AscenseurConstants::kAscenseurLimitUp);
}

// Called repeatedly when this Command is scheduled to run
void ElevatorUp::Execute() 
{
  mElevator->setElevatorPosition();
}

// Called once the command ends or is interrupted.
void ElevatorUp::End(bool interrupted) 
{
  mElevator->setEnable(true);
}

// Returns true when the command should end.
bool ElevatorUp::IsFinished() {
  return std::abs(mElevator->getEncoderPositionMotor(Motor1)-mElevator->getTargetPosition()) < 0.05;
}
