// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TrapUp.h"

TrapUp::TrapUp(SubPivot *iPivot, SubElevator *iElevator) {
  // Use addRequirements() here to declare subsystem dependencies.
  mPivot = iPivot;
  mElevator = iElevator;

  AddRequirements(mPivot);
  AddRequirements(mElevator);
}

// Called when the command is initially scheduled.
void TrapUp::Initialize() 
{
  mElevator->setEnable(false);   
  mElevator->setTargetPosition(ElevatorConstants::kElevatorLimitUp);
}

// Called repeatedly when this Command is scheduled to run
void TrapUp::Execute() 
{
  mPivot->pivotMiddle();
  mElevator->setElevatorPosition();
}

// Called once the command ends or is interrupted.
void TrapUp::End(bool interrupted) 
{
  mElevator->setEnable(true);
}

// Returns true when the command should end.
bool TrapUp::IsFinished() {
  return std::abs(mPivot->getEncodeurPosition() - PivotConstants::kHeightUp) < 2 &&
        std::abs(mElevator->getEncoderPositionMotor(Motor1) - ElevatorConstants::kElevatorLimitDown) < 4;
}