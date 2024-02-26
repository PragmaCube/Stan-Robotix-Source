// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AscenseurHaut.h"

AscenseurHaut::AscenseurHaut(SubAscenseur *iAscenseur) {

  mAscenseur = iAscenseur;
  AddRequirements(mAscenseur);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void AscenseurHaut::Initialize() 
{
  mAscenseur->setEnable(false);
  mAscenseur->setPositionVoulue(AscenseurConstants::kAscenseurLimitUp);
}

// Called repeatedly when this Command is scheduled to run
void AscenseurHaut::Execute() 
{
  mAscenseur->setPositionAscenseur(mAscenseur->getPositionVoulue());
}

// Called once the command ends or is interrupted.
void AscenseurHaut::End(bool interrupted) 
{
  mAscenseur->setEnable(true);
}

// Returns true when the command should end.
bool AscenseurHaut::IsFinished() {
  return std::abs(mAscenseur->getEncoderPositionMotor1()-mAscenseur->getPositionVoulue()) < 0.05;
}
