// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/PosStorage.h"

PosStorage::PosStorage(SubPivot *iPivot, SubAscenseur *iAscenseur)
{
  mPivot = iPivot;
  mAscenceur = iAscenseur;

  AddRequirements(mPivot);
  AddRequirements(mAscenceur);
}

// Called when the command is initially scheduled.
void PosStorage::Initialize() 
{
  mAscenceur->setEnable(false);   
  mAscenceur->setPositionVoulue(AscenseurConstants::kAscenseurLimitDown);
}

// Called repeatedly when this Command is scheduled to run
void PosStorage::Execute() 
{
  mPivot->pivotUp();
  mAscenceur->setPositionAscenseur(mAscenceur->getPositionVoulue());
}

// Called once the command ends or is interrupted.
void PosStorage::End(bool interrupted) 
{
  mAscenceur->setEnable(true);
}

// Returns true when the command should end.
bool PosStorage::IsFinished() {
  return std::abs(mPivot->getEncodeurPosition() - PivotConstants::kHeightUp) < 2 &&
        std::abs(mAscenceur->getEncoderPositionMotor1() - AscenseurConstants::kAscenseurLimitDown) < 4;
}