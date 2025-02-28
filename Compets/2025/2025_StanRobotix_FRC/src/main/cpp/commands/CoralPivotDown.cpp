// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CoralPivotDown.h"

CoralPivotDown::CoralPivotDown(SubCoralPivot * iCoralPivot) {
  mCoralPivot = iCoralPivot;
  AddRequirements(mCoralPivot);
}

// Called when the command is initially scheduled.
void CoralPivotDown::Initialize() {
  mCoralPivot->SetPIDEnable(true);
}

// Called repeatedly when this Command is scheduled to run
void CoralPivotDown::Execute() {
  mCoralPivot->Pivot(-0.1);
  if ((mCoralPivot->AtSetPoint()) || (ReachedSetPoint))
  {
    ReachedSetPoint = true;
    Timer++;
  }
}

// Called once the command ends or is interrupted.
void CoralPivotDown::End(bool interrupted) {
  mCoralPivot->SetPIDEnable(false);
}

// Returns true when the command should end.
bool CoralPivotDown::IsFinished() {
  return (mCoralPivot->AtSetPoint()) && (Timer >= 25);
}
