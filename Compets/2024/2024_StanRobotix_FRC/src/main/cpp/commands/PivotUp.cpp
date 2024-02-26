// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/PivotUp.h"
#include <iostream>

PivotUp::PivotUp(SubPivot *iPivot) {
  // Use addRequirements() here to declare subsystem dependencies.
  mPivot = iPivot;
  AddRequirements(mPivot);
}

// Called when the command is initially scheduled.
void PivotUp::Initialize() 
{
  mPivot->setEnable(false);
}

// Called repeatedly when this Command is scheduled to run
void PivotUp::Execute() 
{
  mPivot->pivotUp();
  // std::cout << "Pivot Up" << std::endl;
}

// Called once the command ends or is interrupted.
void PivotUp::End(bool interrupted) 
{
  mPivot->setEnable(true);
}

// Returns true when the command should end.
bool PivotUp::IsFinished() {
  return std::abs(mPivot->getEncodeurPosition() - PivotConstants::kHeightUp) < 0.05;
}
