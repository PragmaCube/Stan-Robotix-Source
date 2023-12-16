// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Up.h"
#include "subsystems/SubArm.h"


Up::Up() 
{
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void Up::Initialize() 
{

}

// Called repeatedly when this Command is scheduled to run
void Up::Execute() 
{

}

// Called once the command ends or is interrupted.
void Up::End(bool interrupted) {}

// Returns true when the command should end.
bool Up::IsFinished() {
  return   Height = ArmConstants::kArmLimitUp == ;
}
