// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include <cmath>

#include "commands/Milieu.h"

Milieu::Milieu(SubAscenseur *iAscenseur) {

  mAscenseur = iAscenseur;
  AddRequirements(mAscenseur);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void Milieu::Initialize() 
{
  mAscenseur->setPositionVoulue(AscenseurConstants::kAscenseurLimitMiddle);
}

// Called repeatedly when this Command is scheduled to run
void Milieu::Execute() 
{
  mAscenseur->setPositionAscenseur(mAscenseur->getPositionVoulue());
}

// Called once the command ends or is interrupted.
void Milieu::End(bool interrupted) {}

// Returns true when the command should end.
bool Milieu::IsFinished() {
  return std::abs(mAscenseur->getEncoderPositionMotor1()-mAscenseur->getPositionVoulue()) < 0.05 && std::abs(mAscenseur->getEncoderPositionMotor2()-mAscenseur->getPositionVoulue()) < 0.05;
}
