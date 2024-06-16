// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/PosStorage.h"

PosStorage::PosStorage(SubPivot *iPivot, SubElevator *iElevator)
{
  mPivot = iPivot;
  mElevator = iElevator;

  AddRequirements(mPivot);
  AddRequirements(mElevator);
}

// Called when the command is initially scheduled.
void PosStorage::Initialize() 
{
  mElevator->setEnable(false);   
  mElevator->setTargetPosition(ElevatorConstants::kElevatorLimitDown);
}

// Called repeatedly when this Command is scheduled to run
void PosStorage::Execute() 
{
  mPivot->pivotUp();
  mElevator->setElevatorPosition();
}

// Called once the command ends or is interrupted.
void PosStorage::End(bool interrupted) 
{
  mElevator->setEnable(true);
}

// Returns true when the command should end.
bool PosStorage::IsFinished() {
  return std::abs(mPivot->getEncodeurPosition() - PivotConstants::kHeightUp) < 2 &&
        std::abs(mElevator->getEncoderPositionMotor(Motor1) - ElevatorConstants::kElevatorLimitDown) < 4;
}