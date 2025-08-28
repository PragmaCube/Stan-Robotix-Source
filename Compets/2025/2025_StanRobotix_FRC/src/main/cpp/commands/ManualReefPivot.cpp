// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ManualReefPivot.h"

ManualReefPivot::ManualReefPivot(SubReefPivot * iSubReefPivot, SubReefIntake * iSubReefIntake){
  // Use addRequirements() here to declare subsystem dependencies.
  mSubReefPivot = iSubReefPivot;
  mSubReefIntake = iSubReefIntake;
  AddRequirements(mSubReefPivot);
  AddRequirements(mSubReefIntake);
}

// Called when the command is initially scheduled.
void ManualReefPivot::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ManualReefPivot::Execute() {
  mSubReefPivot->SetVoltage(1);
  mSubReefIntake->SetPercentage(-0.4);
}

// Called once the command ends or is interrupted.
void ManualReefPivot::End(bool interrupted) {}

// Returns true when the command should end.
bool ManualReefPivot::IsFinished() {
  return false;
}
