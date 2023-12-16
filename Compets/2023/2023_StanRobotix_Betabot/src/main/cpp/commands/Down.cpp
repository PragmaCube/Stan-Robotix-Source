// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Down.h"
#include "subsystems/SubArm.h"
#include "Constants.h"


Down::Down(SubArm *iArm)
{

}

void Down::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Down::Execute() 
{
  SubArm::
}

// Called once the command ends or is interrupted.
void Down::End(bool interrupted) {}

// Returns true when the command should end.
bool Down::IsFinished() {
  return mArm->GetEncodeurPosition() == ArmConstants::kArmLimitUp;
}
