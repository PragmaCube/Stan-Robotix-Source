// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/VisionGoToAlgae.h"

VisionGoToAlgae::VisionGoToAlgae(SubDriveTrain *iSubDrive, SubCameraVision *iSubCamera)
{
  // Use addRequirements() here to declare subsystem dependencies.
  mSubDriveTrain = iSubDrive;
  mSubVision = iSubCamera;
  AddRequirements(mSubDriveTrain);
  AddRequirements(mSubVision);

  mPIDController->SetPID(Vision::GoToAlgae::kP, Vision::GoToAlgae::kI, Vision::GoToAlgae::kD);
  mPIDController->SetTolerance(Vision::GoToAlgae::kError);
}

// Called when the command is initially scheduled.
void VisionGoToAlgae::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void VisionGoToAlgae::Execute()
{
  PIDOut = mPIDController->Calculate(mSubVision->getYaw(), 0);
  mSubDriveTrain->driveFieldRelative(0,0,PIDOut,0.5);
}

// Called once the command ends or is interrupted.
void VisionGoToAlgae::End(bool interrupted) {}

// Returns true when the command should end.
bool VisionGoToAlgae::IsFinished()
{
  return mPIDController->AtSetpoint();
}
