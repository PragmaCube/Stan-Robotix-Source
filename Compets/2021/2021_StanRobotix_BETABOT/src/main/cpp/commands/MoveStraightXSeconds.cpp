// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc2/command/Command.h>

#include "commands/MoveStraightXSeconds.h"

MoveStraightXSeconds::MoveStraightXSeconds() {}

MoveStraightXSeconds::MoveStraightXSeconds(SubDriveTrain* iDriveTrain) : mDriveTrain(iDriveTrain)
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(iDriveTrain);
}

// Called when the command is initially scheduled.
void MoveStraightXSeconds::Initialize() {}

// Called repeatedly  when this Command is scheduled to run
void MoveStraightXSeconds::Execute()
{
  mDriveTrain->TankDrive(0.25, 0.25, SubDriveTrain::MotorSpeed::eSlow);
}

// Called once the command ends or is interrupted.
void MoveStraightXSeconds::End(bool interrupted) {}

// Returns true when the command should end.
bool MoveStraightXSeconds::IsFinished() {
  return false;
}
