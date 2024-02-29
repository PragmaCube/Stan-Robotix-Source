// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Amplificateur.h"

Amplificateur::Amplificateur(SubPivot *iPivot, SubAscenseur *iAscenseur) {
  mPivot = iPivot;
  mAscenseur = iAscenseur;
  
  AddRequirements(mPivot);
  AddRequirements(mAscenseur);
}

// Called when the command is initially scheduled.
void Amplificateur::Initialize() 
{
  mAscenseur->setEnable(false);
  mAscenseur->setPositionVoulue(AscenseurConstants::kAscenseurLimitMiddle);
}

// Called repeatedly when this Command is scheduled to run
void Amplificateur::Execute() 
{
  mPivot->pivotUp();
  mAscenseur->setPositionAscenseur(mAscenseur->getPositionVoulue());
}

// Called once the command ends or is interrupted.
void Amplificateur::End(bool interrupted) 
{
  mAscenseur->setEnable(true);
}

// Returns true when the command should end.
bool Amplificateur::IsFinished() {
    return std::abs(mPivot->getEncodeurPosition() - PivotConstants::kHeightMiddle) < 2 &&
          std::abs(mAscenseur->getEncoderPositionMotor1() - AscenseurConstants::kAscenseurLimitMiddle) < 5;
}