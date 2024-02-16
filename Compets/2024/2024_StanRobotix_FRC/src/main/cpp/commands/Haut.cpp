// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Haut.h"

Haut::Haut(SubAscenseur *iAscenseur) {

  mAscenseur = iAscenseur;
  AddRequirements(mAscenseur);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void Haut::Initialize() 
{
  mAscenseur->setPositionVoulue(AscenseurConstants::kAscenseurLimitUp);
}

// Called repeatedly when this Command is scheduled to run
void Haut::Execute() 
{
  mAscenseur->setPositionAscenseur(mAscenseur->getPositionVoulue());
}

// Called once the command ends or is interrupted.
void Haut::End(bool interrupted) {}

// Returns true when the command should end.
bool Haut::IsFinished() {
  return std::abs(mAscenseur->getEncoderPositionMotor1()-mAscenseur->getPositionVoulue()) < 0.05 &&
         std::abs(mAscenseur->getEncoderPositionMotor2()-mAscenseur->getPositionVoulue()) < 0.05 &&
         std::abs(mAscenseur->getVelocityMotor1()) == 0 &&
         std::abs(mAscenseur->getVelocityMotor2()) == 0;
}
