// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Foward.h"

Foward::Foward(SubDriveTrain *iDriveTrain, double iSeconds) {
  // Use addRequirements() here to declare subsystem dependencies.
  mDriveTrain = iDriveTrain;
  mDuration = iSeconds;
  AddRequirements(mDriveTrain);
}

// Called when the command is initially scheduled.
void Foward::Initialize() {
  mTimer.Start();
}

// Called repeatedly when this Command is scheduled to run
void Foward::Execute() {
      mDriveTrain->mecanumDrive(0, -FowardConstants::Vitesse, 0, frc::Rotation2d(0_rad));
}

// Called once the command ends or is interrupted.
void Foward::End(bool interrupted) 
{
  mTimer.Reset();
}

// Returns true when the command should end.
bool Foward::IsFinished() {
  return mTimer.Get().value() > mDuration;
}