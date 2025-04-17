// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ReefPivotUp.h"
#include <frc/shuffleboard/Shuffleboard.h>

ReefPivotUp::ReefPivotUp(SubReefPivot * iSubReefPivot, SubReefIntake * iSubReefIntake) {
  // Use addRequirements() here to declare subsystem dependencies.
  mSubReefPivot = iSubReefPivot;
  mSubReefIntake = iSubReefIntake;
  AddRequirements(mSubReefPivot);
  AddRequirements(mSubReefIntake);
}

// Called when the command is initially scheduled.
void ReefPivotUp::Initialize() {
    frc::Shuffleboard::GetTab("Main Tab").Add("TestShuffleBoard", true).GetEntry()->SetBoolean(true);

}

// Called repeatedly when this Command is scheduled to run
void ReefPivotUp::Execute() {
  mSubReefPivot->SetPosition(-0.4);
  mSubReefIntake->SetPercentage(0.9);
}

// Called once the command ends or is interrupted.
void ReefPivotUp::End(bool interrupted) {
    frc::Shuffleboard::GetTab("Main Tab").Add("TestShuffleBoard", true).GetEntry()->SetBoolean(false);

}

// Returns true when the command should end.
bool ReefPivotUp::IsFinished() {
  return false;
}
