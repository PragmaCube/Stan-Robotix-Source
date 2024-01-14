// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Rotation90DegresGauche.h"

Rotation90DegresGauche::Rotation90DegresGauche(SubIMU *iIMU ,SubDriveTrain *iDriveTrain) 
{
  mIMU = iIMU;
  mDriveTrain = iDriveTrain;

  AddRequirements(mIMU);
  AddRequirements(mDriveTrain);


  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void Rotation90DegresGauche::Initialize() 
{
  RotationGauche = mIMU->getAngleYaw();
}

// Called repeatedly when this Command is scheduled to run
void Rotation90DegresGauche::Execute() 
{
  mDriveTrain->mecanumDrive(0 , 0 , -0.5, mIMU->getRotation2d());
}

// Called once the command ends or is interrupted.
void Rotation90DegresGauche::End(bool interrupted) {}

// Returns true when the command should end.
bool Rotation90DegresGauche::IsFinished() 
{
  if (mIMU->getAngleYaw() < RotationGauche - 90)
  {
    return true;
  }
  return false;
}
