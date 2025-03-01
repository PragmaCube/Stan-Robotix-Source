// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AlgaePivotDown.h"

AlgaePivotDown::AlgaePivotDown(SubAlgaePivot * iAlgaePivot) {
  // Use addRequirements() here to declare subsystem dependencies.
  mAlgaePivot = iAlgaePivot;
  AddRequirements(mAlgaePivot);
}

// Called when the command is initially scheduled.
void AlgaePivotDown::Initialize() {
  mAlgaePivot->SetPIDEnable(true);
  Timer = -1;
  ReachedSetPoint = false;
}

// Called repeatedly when this Command is scheduled to run
void AlgaePivotDown::Execute() {
  mAlgaePivot->Pivot(0.7);
  if ((mAlgaePivot->AtSetPoint()) || ReachedSetPoint)
  {    
    ReachedSetPoint = true;
    Timer++;
  }

}

// Called once the command ends or is interrupted.
void AlgaePivotDown::End(bool interrupted) {
  mAlgaePivot->SetPIDEnable(false);
}

// Returns true when the command should end.
bool AlgaePivotDown::IsFinished() {
  return (mAlgaePivot->AtSetPoint()) && (Timer >= 50);
}
