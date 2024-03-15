// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TrapDown.h"

TrapDown::TrapDown(SubPivot *iPivot, SubElevator *iElevator) {
  // Use addRequirements() here to declare subsystem dependencies.
  mPivot = iPivot;
  mElevator = iElevator;

  AddRequirements(mPivot);
  AddRequirements(mElevator);
}

// Called when the command is initially scheduled.
void TrapDown::Initialize() 
{
  mElevator->setEnable(false);   
  mElevator->setTargetPosition(AscenseurConstants::kAscenseurLimitDown);
}

// Called repeatedly when this Command is scheduled to run
void TrapDown::Execute() 
{
  mPivot->pivotMiddle();
  mElevator->setElevatorPosition();
}

// Called once the command ends or is interrupted.
void TrapDown::End(bool interrupted) 
{
  mElevator->setEnable(true);
}

// Returns true when the command should end.
bool TrapDown::IsFinished() {
  return std::abs(mPivot->getEncodeurPosition() - PivotConstants::kHeightUp) < 2 &&
        std::abs(mElevator->getEncoderPositionMotor(Motor1) - AscenseurConstants::kAscenseurLimitDown) < 4;
}
