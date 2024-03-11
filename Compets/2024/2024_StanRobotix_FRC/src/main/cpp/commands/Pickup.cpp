// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.


#include "commands/Pickup.h"

Pickup::Pickup(SubPivot *iPivot, SubAscenseur *iAscenseur)
{
  mPivot = iPivot;
  mAscenceur = iAscenseur;

  AddRequirements(mPivot);
  AddRequirements(mAscenceur);
}

// Called when the command is initially scheduled.
void Pickup::Initialize() 
{
  mAscenceur->setEnable(false);   
  mAscenceur->setPositionVoulue(AscenseurConstants::kAscenseurLimitDown);
}

// Called repeatedly when this Command is scheduled to run
void Pickup::Execute() 
{
  mPivot->pivotDown();
  mAscenceur->setPositionAscenseur(mAscenceur->getPositionVoulue());
}

// Called once the command ends or is interrupted.
void Pickup::End(bool interrupted) 
{
  mAscenceur->setEnable(true);
}

// Returns true when the command should end.
bool Pickup::IsFinished() {
  return std::abs(mPivot->getEncodeurPosition() - PivotConstants::kHeightDown) < 2 &&
        std::abs(mAscenceur->getEncoderPositionMotor1() - AscenseurConstants::kAscenseurLimitDown) < 4;
}