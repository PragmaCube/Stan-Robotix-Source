// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AlgaeIntakeOut.h"

AlgaeIntakeOut::AlgaeIntakeOut(SubAlgaeIntake *iSubAlgaeIntake) {
  // Use addRequirements() here to declare subsystem dependencies.
  mAlgaeIntake = iSubAlgaeIntake;
  AddRequirements(mAlgaeIntake);
}

// Called when the command is initially scheduled.
void AlgaeIntakeOut::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AlgaeIntakeOut::Execute() {
  mAlgaeIntake->AlgaeOutake();
  i++;
}

// Called once the command ends or is interrupted.
void AlgaeIntakeOut::End(bool interrupted) {
  mAlgaeIntake->AlgaeIntakeStop();
}

// Returns true when the command should end.
bool AlgaeIntakeOut::IsFinished() {
return (i == CommandConstants::kIterationsGoal);
}

//50 iterations pour 1s car 1s/20ms = 50