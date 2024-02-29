// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/EjectorOut.h"

EjectorOut::EjectorOut(SubEjector *iEjector, double iSecondes) {
  // Use addRequirements() here to declare subsystem dependencies.
  mEjector = iEjector;
  mDuree = iSecondes;
  AddRequirements(mEjector);
}

// Called when the command is initially scheduled.
void EjectorOut::Initialize() 
{
  mTimer.Start();
}

// Called repeatedly when this Command is scheduled to run
void EjectorOut::Execute() 
{
  mEjector->OutDown();
}

// Called once the command ends or is interrupted.
void EjectorOut::End(bool interrupted) {}

// Returns true when the command should end.
bool EjectorOut::IsFinished() {
  return mTimer.Get().value() > mDuree;
}