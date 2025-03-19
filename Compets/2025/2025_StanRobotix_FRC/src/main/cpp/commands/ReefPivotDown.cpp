// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ReefPivotDown.h"

ReefPivotDown::ReefPivotDown(SubReefPivot * iSubReefPivot) {
  // Use addRequirements() here to declare subsystem dependencies.
  mSubReefPivot = iSubReefPivot;
  AddRequirements(mSubReefPivot);
}

// Called when the command is initially scheduled.
void ReefPivotDown::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ReefPivotDown::Execute() {
  mSubReefPivot->Pivot(-0.9);
  mSubReefPivot->Intake(0.3);
}

// Called once the command ends or is interrupted.
void ReefPivotDown::End(bool interrupted) {}

// Returns true when the command should end.
bool ReefPivotDown::IsFinished() {
  return false;
}
