// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/PistonPulse.h"
#include <frc2/command/WaitCommand.h>

PistonPulse::PistonPulse() {}

PistonPulse::PistonPulse(SubSolenoid* iPiston, bool iAutonomous) : mPiston(iPiston)
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(iPiston);

  if(iAutonomous)
  {
    frc2::Wait(2.0_s);
  }
}

// Called when the command is initially scheduled.
void PistonPulse::Initialize()
{
  mPiston->SetInactive();
}

// Called repeatedly when this Command is scheduled to run
void PistonPulse::Execute()
{
  mPiston->SwitchPistonState();
  frc2::Wait(2.0_s);
  mPiston->SwitchPistonState();
}

// Called once the command ends or is interrupted.
void PistonPulse::End(bool interrupted) {}

// Returns true when the command should end.
bool PistonPulse::IsFinished() {
  return false;
}
