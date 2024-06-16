// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include <cmath>

#include "commands/ElevatorMiddle.h"

ElevatorMiddle::ElevatorMiddle(SubElevator *iElevator) {

  mElevator = iElevator;
  AddRequirements(mElevator);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void ElevatorMiddle::Initialize() 
{
  mElevator->setEnable(false);
  mElevator->setTargetPosition(ElevatorConstants::kElevatorLimitMiddle);
}

// Called repeatedly when this Command is scheduled to run
void ElevatorMiddle::Execute() 
{
  mElevator->setElevatorPosition();
}

// Called once the command ends or is interrupted.
void ElevatorMiddle::End(bool interrupted) 
{
  mElevator->setEnable(true);
}

// Returns true when the command should end.
bool ElevatorMiddle::IsFinished() {
  return std::abs(mElevator->getEncoderPositionMotor(Motor1)-mElevator->getTargetPosition()) < 0.05 ;
}
