// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AlgaePivotUp.h"

AlgaePivotUp::AlgaePivotUp(SubAlgaePivot * iAlgaePivot) {
  // Use addRequirements() here to declare subsystem dependencies.
  mAlgaePivot = iAlgaePivot;
  AddRequirements(mAlgaePivot);
}

void AlgaePivotUp::Initialize() {
  mAlgaePivot->SetPIDEnable(true);
  ReachedSetPoint = false;
  Timer = -1;
}

// Called repeatedly when this Command is scheduled to run
void AlgaePivotUp::Execute() {
  mAlgaePivot->Pivot(1.5);
  if((mAlgaePivot->AtSetPoint()) || (ReachedSetPoint))
  {
    ReachedSetPoint = true;
    Timer++;
  }
}

// Called once the command ends or is interrupted.
void AlgaePivotUp::End(bool interrupted) {
  mAlgaePivot->SetPIDEnable(false);
}

// Returns true when the command should end.
bool AlgaePivotUp::IsFinished() {
  return (mAlgaePivot->AtSetPoint()) && (Timer >= 25);
}