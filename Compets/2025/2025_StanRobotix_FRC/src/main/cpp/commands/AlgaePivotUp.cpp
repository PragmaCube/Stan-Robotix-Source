// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AlgaePivotUp.h"
#include <frc/shuffleboard/Shuffleboard.h>

AlgaePivotUp::AlgaePivotUp(SubAlgaePivot * iAlgaePivot) {
  // Use addRequirements() here to declare subsystem dependencies.
  mAlgaePivot = iAlgaePivot;
  AddRequirements(mAlgaePivot);
}

void AlgaePivotUp::Initialize() {
  ReachedSetPoint = false;
  Timer = -1;
    frc::Shuffleboard::GetTab("Main Tab").Add("AlgaePivotUp", true).GetEntry()->SetBoolean(true);

}

// Called repeatedly when this Command is scheduled to run
void AlgaePivotUp::Execute() {
  mAlgaePivot->SetPosition(1.3);
  if((mAlgaePivot->AtSetPoint()) || (ReachedSetPoint))
  {
    ReachedSetPoint = true;
    Timer++;
  }
}

// Called once the command ends or is interrupted.
void AlgaePivotUp::End(bool interrupted) {
    frc::Shuffleboard::GetTab("Main Tab").Add("AlgaepivotUp", true).GetEntry()->SetBoolean(false);

}

// Returns true when the command should end.
bool AlgaePivotUp::IsFinished() {
  return (mAlgaePivot->AtSetPoint()) && (Timer >= 25);
}