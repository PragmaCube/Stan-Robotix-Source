// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/PivotDown.h"


PivotDown::PivotDown(SubPivot *iPivot, SubAscenseur *iAscensseur) {
  // Use addRequirements() here to declare subsystem dependencies.
  mPivot = iPivot;
  mAscenseur=iAscensseur;
  
  AddRequirements(mPivot);
  AddRequirements(mAscenseur);
}

// Called when the command is initially scheduled.
void PivotDown::Initialize() 
{
  mPivot->setEnable(false);
}

// Called repeatedly when this Command is scheduled to run
void PivotDown::Execute() 
{
  mPivot->pivotDown();
}

// Called once the command ends or is interrupted.
void PivotDown::End(bool interrupted) 
{
  mPivot->setEnable(true);
}

// Returns true when the command should end.
bool PivotDown::IsFinished() {
  return (std::abs(mPivot->getEncodeurPosition() - PivotConstants::kHeightDown) < 2 );     
}