// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Rotation90DegresDroite.h"

Rotation90DegresDroite::Rotation90DegresDroite(SubIMU *iIMU ,SubDriveTrain *iDriveTrain) 
{
  mIMU = iIMU;
  mDriveTrain = iDriveTrain;

  AddRequirements(mIMU);
  AddRequirements(mDriveTrain);


  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void Rotation90DegresDroite::Initialize() 
{
  RotationDroite = mIMU->getAngleYaw();
}

// Called repeatedly when this Command is scheduled to run
void Rotation90DegresDroite::Execute() 
{
  mDriveTrain->mecanumDrive(0 , 0 , 0.5, mIMU->getRotation2d());
}

// Called once the command ends or is interrupted.
void Rotation90DegresDroite::End(bool interrupted) {}

// Returns true when the command should end.
bool Rotation90DegresDroite::IsFinished() 
{
  if (mIMU->getAngleYaw() > RotationDroite + 90)
  {
    return true;
  }
  return false;
}
