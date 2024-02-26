// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include <cmath>

#include "commands/AscenseurMilieu.h"

AscenseurMilieu::AscenseurMilieu(SubAscenseur *iAscenseur) {

  mAscenseur = iAscenseur;
  AddRequirements(mAscenseur);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void AscenseurMilieu::Initialize() 
{
  mAscenseur->setEnable(false);
  mAscenseur->setPositionVoulue(AscenseurConstants::kAscenseurLimitMiddle);
}

// Called repeatedly when this Command is scheduled to run
void AscenseurMilieu::Execute() 
{
  mAscenseur->setPositionAscenseur(mAscenseur->getPositionVoulue());
}

// Called once the command ends or is interrupted.
void AscenseurMilieu::End(bool interrupted) 
{
  mAscenseur->setEnable(true);
}

// Returns true when the command should end.
bool AscenseurMilieu::IsFinished() {
  return std::abs(mAscenseur->getEncoderPositionMotor1()-mAscenseur->getPositionVoulue()) < 0.05 ;
}
