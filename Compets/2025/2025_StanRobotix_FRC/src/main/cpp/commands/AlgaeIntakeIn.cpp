// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AlgaeIntakeIn.h"

AlgaeIntakeIn::AlgaeIntakeIn(SubAlgaeIntake *iSubAlgaeIntake) {
  // Use addRequirements() here to declare subsystem dependencies.
  mAlgaeIntake = iSubAlgaeIntake;
  AddRequirements(mAlgaeIntake);
}

// Called when the command is initially scheduled.
void AlgaeIntakeIn::Initialize() {
  i = 0;
}

// Called repeatedly when this Command is scheduled to run
void AlgaeIntakeIn::Execute() {
  mAlgaeIntake->AlgaeIntake();
  i++;
}

// Called once the command ends or is interrupted.
void AlgaeIntakeIn::End(bool interrupted) {
  mAlgaeIntake->AlgaeIntakeStop();
}

// Returns true when the command should end.
bool AlgaeIntakeIn::IsFinished() {
  return (i == CommandConstants::kIterationsGoal);
}