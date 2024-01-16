// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Bas.h"

Bas::Bas(SubAscenseur *iAscenseur) {

  mAscenseur = iAscenseur;
  AddRequirements(mAscenseur);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void Bas::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Bas::Execute() {}

// Called once the command ends or is interrupted.
void Bas::End(bool interrupted) {}

// Returns true when the command should end.
bool Bas::IsFinished() {
  return false;
}
