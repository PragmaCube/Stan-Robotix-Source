// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TrapUp.h"

TrapUp::TrapUp(SubPivot *iPivot, SubAscenseur *iAscenseur) {
  // Use addRequirements() here to declare subsystem dependencies.
  mPivot = iPivot;
  mAscenceur = iAscenseur;

  AddRequirements(mPivot);
  AddRequirements(mAscenceur);
}

// Called when the command is initially scheduled.
void TrapUp::Initialize() 
{
  mAscenceur->setEnable(false);   
  mAscenceur->setPositionVoulue(AscenseurConstants::kAscenseurLimitUp);
}

// Called repeatedly when this Command is scheduled to run
void TrapUp::Execute() 
{
  mPivot->pivotMiddle();
  mAscenceur->setPositionAscenseur(mAscenceur->getPositionVoulue());
}

// Called once the command ends or is interrupted.
void TrapUp::End(bool interrupted) 
{
  mAscenceur->setEnable(true);
}

// Returns true when the command should end.
bool TrapUp::IsFinished() {
  return std::abs(mPivot->getEncodeurPosition() - PivotConstants::kHeightUp) < 0.05 &&
        std::abs(mAscenceur->getEncoderPositionMotor1() - AscenseurConstants::kAscenseurLimitDown) < 0.05;
}