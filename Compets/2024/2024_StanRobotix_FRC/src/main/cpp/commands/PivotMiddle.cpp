// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/PivotMiddle.h"

PivotMiddle::PivotMiddle(SubPivot *iPivot) {
  // Use addRequirements() here to declare subsystem dependencies.
  mPivot=iPivot;
  AddRequirements(mPivot);
}

// Called when the command is initially scheduled.
void PivotMiddle::Initialize() 
{
  mPivot->setEnable(false);
}

// Called repeatedly when this Command is scheduled to run
void PivotMiddle::Execute() 
{
  mPivot->pivotMiddle();
}

// Called once the command ends or is interrupted.
void PivotMiddle::End(bool interrupted) 
{
  mPivot->setEnable(true);
}

// Returns true when the command should end.
bool PivotMiddle::IsFinished() {
  return std::abs(mPivot->getEncodeurPosition() - PivotConstants::kHeightMiddle) < 0.05;
}
