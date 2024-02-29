// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/EjectorIn.h"

EjectorIn::EjectorIn(SubEjector *iEjector, double iSecondes) {
  // Use addRequirements() here to declare subsystem dependencies.
  mEjector = iEjector;
  mDuree = iSecondes;

  AddRequirements(mEjector);
}

// Called when the command is initially scheduled.
void EjectorIn::Initialize() 
{
  mTimer.Start();
}

// Called repeatedly when this Command is scheduled to run
void EjectorIn::Execute() 
{
  mEjector->In();
}

// Called once the command ends or is interrupted.
void EjectorIn::End(bool interrupted) {}

// Returns true when the command should end.
bool EjectorIn::IsFinished() {
  return mTimer.Get().value() > mDuree;
}