// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/under_10_inch.h"

under_10_inch::under_10_inch() {}

under_10_inch::under_10_inch(SubDriveTrain* iDriveTrain) : mDriveTrain(iDriveTrain)
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(iDriveTrain);
}

// Called when the command is initially scheduled.
void under_10_inch::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void under_10_inch::Execute() 
{
  if (mUltrasonic->getDistance() >= 10)
  {
     mDriveTrain->TankDrive(0.25, 0.25, SubDriveTrain::MotorSpeed::eSlow);
  }

  else
  {
     mDriveTrain->TankDrive(0, 0, SubDriveTrain::MotorSpeed::eSlow);
  }
}

// Called once the command ends or is interrupted.
void under_10_inch::End(bool interrupted) 
{
  mDriveTrain->TankDrive(0, 0, SubDriveTrain::MotorSpeed::eSlow);
}

// Returns true when the command should end.
bool under_10_inch::IsFinished() {
  return false;
}
