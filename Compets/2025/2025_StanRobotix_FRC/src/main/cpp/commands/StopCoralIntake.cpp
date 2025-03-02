// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/StopCoralIntake.h"

StopCoralIntake::StopCoralIntake(SubCoralIntake * iSubCoralIntake) {
  // Use addRequirements() here to declare subsystem dependencies.
  mSubCoralIntake = iSubCoralIntake;
}

// Called when the command is initially scheduled.
void StopCoralIntake::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void StopCoralIntake::Execute() {
  mSubCoralIntake->SetCommandsState(false);
}

// Called once the command ends or is interrupted.
void StopCoralIntake::End(bool interrupted) {}

// Returns true when the command should end.
bool StopCoralIntake::IsFinished() {
  return !mSubCoralIntake->GetCommandsState();
}
