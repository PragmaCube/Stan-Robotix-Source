// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ClimbPivotUp.h"

ClimbPivotUp::ClimbPivotUp(SubAlgaePivot * iSubAlgaePivot) {
  // Use addRequirements() here to declare subsystem dependencies.
  mSubAlgaePivot = iSubAlgaePivot;
  AddRequirements(mSubAlgaePivot);
}

// Called when the command is initially scheduled.
void ClimbPivotUp::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ClimbPivotUp::Execute() {
  mSubAlgaePivot->PivotUpSmooth();
}

// Called once the command ends or is interrupted.
void ClimbPivotUp::End(bool interrupted) {}

// Returns true when the command should end.
bool ClimbPivotUp::IsFinished() {
  return false;
}
