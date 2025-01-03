// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/EjectorOut.h"

EjectorOut::EjectorOut(SubEjector *iEjector, double iSeconds) {
  // Use addRequirements() here to declare subsystem dependencies.
  mEjector = iEjector;
  mDuration = iSeconds;
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
void EjectorOut::End(bool interrupted) 
{
  mTimer.Reset();
  mEjector->Stop();
}

// Returns true when the command should end.
bool EjectorOut::IsFinished() {
  return mTimer.Get().value() > mDuration;
}