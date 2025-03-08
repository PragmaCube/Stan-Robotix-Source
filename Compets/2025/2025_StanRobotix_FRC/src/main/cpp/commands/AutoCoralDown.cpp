// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoCoralDown.h"

AutoCoralDown::AutoCoralDown(SubCoralPivot * iSubCoralPivot) {
  // Use addRequirements() here to declare subsystem dependencies.
  mSubCoralPivot = iSubCoralPivot;
  AddRequirements(mSubCoralPivot);
}

// Called when the command is initially scheduled.
void AutoCoralDown::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AutoCoralDown::Execute() {
  mSubCoralPivot->SetVoltage(0.9);
  Timer++;
}

// Called once the command ends or is interrupted.
void AutoCoralDown::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoCoralDown::IsFinished() {
  return Timer >= 35;
}
