// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/VisionGoToAlgae.h"

VisionGoToAlgae::VisionGoToAlgae(SubDriveTrain *iSubDrive, SubCameraVision *iSubCamera, SubIMU *iSubIMU)
{
  // Use addRequirements() here to declare subsystem dependencies.
  mSubDriveTrain = iSubDrive;
  mSubVision = iSubCamera;
mSubIMU = iSubIMU;
  AddRequirements(mSubDriveTrain);
  AddRequirements(mSubVision);
  AddRequirements(mSubIMU);



  // mSubIMU = new SubIMU;
  mPIDController = new frc::PIDController{0.1, 0, 0};
  // mSubVision = new SubCameraVision;
  // mSubDriveTrain = new SubDriveTrain{mSubIMU};
  

 // mPIDController->SetPID(0.1, 0, 0);
 // mPIDController->SetTolerance(1);
 // mPIDController->SetSetpoint(1);
 PIDOut = 0;
}

// Called when the command is initially scheduled.
void VisionGoToAlgae::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void VisionGoToAlgae::Execute()
{
  PIDOut = mPIDController->Calculate(mSubVision->getYaw(), 0.0);
  std::cout << mPIDController->Calculate(mSubVision->getYaw(), 0.0) << std::endl;
  // mSubDriveTrain->driveFieldRelative(0,0,PIDOut/3,0.5);

}

// Called once the command ends or is interrupted.
void VisionGoToAlgae::End(bool interrupted) {}

// Returns true when the command should end.
bool VisionGoToAlgae::IsFinished()
{
  return mPIDController->AtSetpoint();
}
