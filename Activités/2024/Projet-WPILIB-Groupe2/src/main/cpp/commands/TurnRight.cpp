// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TurnRight.h"

TurnRight::TurnRight(SubDriveTrain *iDriveTrain, SubIMU *iIMU) 
{
  mDriveTrain = iDriveTrain;
  mIMU = iIMU;
  AddRequirements(mDriveTrain);
  AddRequirements(mIMU);
}

// Called when the command is initially scheduled.
void TurnRight::Initialize() {
  angleDebut = mIMU->getAngleYaw();
}

// Called repeatedly when this Command is scheduled to run
void TurnRight::Execute() {
  mDriveTrain->drive(0, 0, , mIMU->getRotation2d());
}

// Called once the command ends or is interrupted.
void TurnRight::End(bool interrupted) {}

// Returns true when the command should end.
bool TurnRight::IsFinished() {
return (mIMU->getAngleYaw()-angleDebut) > 72;
}
