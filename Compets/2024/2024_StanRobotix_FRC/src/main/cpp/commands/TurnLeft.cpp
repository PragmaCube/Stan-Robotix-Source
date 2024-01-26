// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TurnLeft.h"
#include <frc/drive/MecanumDrive.h>

TurnLeft::TurnLeft(SubDriveTrain *iDriveTrain, SubIMU *iIMU) 
{
  mDriveTrain = iDriveTrain;
  mIMU = iIMU;
  AddRequirements(mDriveTrain);
  AddRequirements(mIMU);

  
}
  
// Called when the command is initially scheduled.
void TurnLeft::Initialize() 
{
 mIMU->ResetAngle();
 mPIDController.SetSetpoint(90);
}

// Called repeatedly when this Command is scheduled to run
void TurnLeft::Execute() {
  mDriveTrain->mecanumDrive(0, 0, mPIDController.Calculate(mIMU->getAngleYaw()), mIMU->getRotation2d());
}

// Called once the command ends or is interrupted.
void TurnLeft::End(bool interrupted) 
{

}

// Returns true when the command should end.
bool TurnLeft::IsFinished() {
  if (mPIDController.AtSetpoint())
  {
    return true;
  }
return false;
}
