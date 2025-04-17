// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AlgaeIntake.h"
#include <frc/shuffleboard/Shuffleboard.h>

AlgaeIntake::AlgaeIntake(SubAlgaeIntake *iSubAlgaeIntake) {
  // Use addRequirements() here to declare subsystem dependencies.
  mAlgaeIntake = iSubAlgaeIntake;
  AddRequirements(mAlgaeIntake);
}

// Called when the command is initially scheduled.
void AlgaeIntake::Initialize() {
    frc::Shuffleboard::GetTab("Main Tab").Add("AlgaeIntake", true).GetEntry()->SetBoolean(true);

}

// Called repeatedly when this Command is scheduled to run
void AlgaeIntake::Execute() {
  mAlgaeIntake->SetPercentage(-0.45);
}

// Called once the command ends or is interrupted.
void AlgaeIntake::End(bool interrupted) {
    frc::Shuffleboard::GetTab("Main Tab").Add("AlgaeIntake", true).GetEntry()->SetBoolean(false);

}

// Returns true when the command should end.
bool AlgaeIntake::IsFinished() {
  return false;
}