// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CoralPivotUp.h"

CoralPivotUp::CoralPivotUp(SubCoralPivot * iCoralPivot, SubCoralIntake * iCoralIntake) {
  mCoralPivot = iCoralPivot;
  mCoralIntake = iCoralIntake;

  AddRequirements(mCoralIntake);
  AddRequirements(mCoralPivot);
}

// Called when the command is initially scheduled.
void CoralPivotUp::Initialize() {
  mCoralPivot->SetPIDEnable(true);
}

// Called repeatedly when this Command is scheduled to run
void CoralPivotUp::Execute() {
  // if (mCoralPivot->GetPosition() >= -1.15)
  // {
    
  // }

  mCoralIntake->SetVoltage(0.25);
    mCoralPivot->SetVoltage(-2.75 * cos(mCoralPivot->GetPosition()));
}

// Called once the command ends or is interrupted.
void CoralPivotUp::End(bool interrupted) {
  mCoralPivot->SetPIDEnable(false);
}

// Returns true when the command should end.
bool CoralPivotUp::IsFinished() {
  return false;
}
