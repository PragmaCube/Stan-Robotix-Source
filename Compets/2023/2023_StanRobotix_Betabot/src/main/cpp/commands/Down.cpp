// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Down.h"
#include "subsystems/SubArm.h"

Down::Down() {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
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
  return ArmConstants::kArmLimitDown == SubArm::GetEncodeurPosition;
}
