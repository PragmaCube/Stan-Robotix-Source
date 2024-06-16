// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Down.h"
#include "Constants.h"


Down::Down(SubArm *iArm)
{
  mArm = iArm;
  AddRequirements(mArm);
}

void Down::Initialize() 
{
  mArm->Down();
}

// Called repeatedly when this Command is scheduled to run
void Down::Execute() 
{
  mArm->Periodic();
}

// Called once the command ends or is interrupted.
void Down::End(bool interrupted) {}

// Returns true when the command should end.
bool Down::IsFinished() 
{
  return mArm->GetEncodeurPosition() == ArmConstants::kArmLimitDown;
}
