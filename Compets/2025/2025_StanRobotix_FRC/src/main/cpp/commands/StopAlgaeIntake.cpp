// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/StopAlgaeIntake.h"

StopAlgaeIntake::StopAlgaeIntake(SubAlgaeIntake * iSubAlgaeIntake) {
  // Use addRequirements() here to declare subsystem dependencies.
  mSubAlgaeIntake = iSubAlgaeIntake;
}

// Called when the command is initially scheduled.
void StopAlgaeIntake::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void StopAlgaeIntake::Execute() {
  mSubAlgaeIntake->SetCommandsState(false);
}

// Called once the command ends or is interrupted.
void StopAlgaeIntake::End(bool interrupted) {}

// Returns true when the command should end.
bool StopAlgaeIntake::IsFinished() {
  return !mSubAlgaeIntake->GetCommandsState();
}
