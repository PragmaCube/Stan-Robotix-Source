// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CoralPivotState.h"

CoralPivotState::CoralPivotState(SubCoralPivot * iCoralPivot, StatesCoral iState) {
  // Use addRequirements() here to declare subsystem dependencies.
  mCoralPivot = iCoralPivot;
  AddRequirements(mCoralPivot); 
  mState = iState;
}

// Called when the command is initially scheduled.
void CoralPivotState::Initialize() {
switch (mState)
{
case StatesCoral::horizontale:
  mCoralPivot->Pivot(0.2);
  mCoralPivot->SetState(StatesCoral::horizontale);
  break;

case StatesCoral::relaché:
  mCoralPivot->Pivot(0.2);
  mCoralPivot->SetState(StatesCoral::relaché);
  break;

case StatesCoral::vertical:
  mCoralPivot->Pivot(0.2);
  mCoralPivot->SetState(StatesCoral::vertical);
  break;

case StatesCoral::shoot:
  mCoralPivot->Pivot(0.2);
  mCoralPivot->SetState(StatesCoral::shoot);
  break;

default:
  break;
}
}

// Called repeatedly when this Command is scheduled to run
void CoralPivotState::Execute() {}

// Called once the command ends or is interrupted.
void CoralPivotState::End(bool interrupted) {}

// Returns true when the command should end.
bool CoralPivotState::IsFinished() {
  return mCoralPivot->atSetPoint();
}
