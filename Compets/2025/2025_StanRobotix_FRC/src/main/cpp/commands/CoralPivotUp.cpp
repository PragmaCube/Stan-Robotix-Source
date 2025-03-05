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
  ReachedSetPoint = false;
  Timer = -1;
}

// Called repeatedly when this Command is scheduled to run
void CoralPivotUp::Execute() {
  mCoralIntake->SetVoltage(0.25);
  mCoralPivot->Pivot(-1.3);
  if ((mCoralPivot->AtSetPoint()) || (ReachedSetPoint))
  {
    ReachedSetPoint = true;
    Timer++;
  }
}

// Called once the command ends or is interrupted.
void CoralPivotUp::End(bool interrupted) {
  mCoralPivot->SetPIDEnable(false);
  std::cout << "Coral Pivot Up Fini" << std::endl;
}

// Returns true when the command should end.
bool CoralPivotUp::IsFinished() {
  return (mCoralPivot->AtSetPoint()) && (Timer >= 50);
}
