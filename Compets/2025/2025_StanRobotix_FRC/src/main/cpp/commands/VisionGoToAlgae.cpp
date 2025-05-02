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



  mPIDController = new frc::PIDController{0.05, 0, 0};

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


  // mSubDriveTrain->driveFieldRelative(0,0,PIDOut/3,0.5);

  std::cout << "pos 0 du vect X = " << mSubVision->getCorner().at(0).x << " Y = " << mSubVision->getCorner().at(0).y << std::endl;
  std::cout << "pos 1 du vect X = " << mSubVision->getCorner().at(1).x << " Y = " << mSubVision->getCorner().at(1).y << std::endl;
  std::cout << "largeur de la balle = " << (mSubVision->getCorner().at(1).x - mSubVision->getCorner().at(0).x) << std::endl;


}

// Called once the command ends or is interrupted.
void VisionGoToAlgae::End(bool interrupted) {
 // mSubDriveTrain->driveFieldRelative(0,0,0,0);
}

// Returns true when the command should end.
bool VisionGoToAlgae::IsFinished()
{
 // std::cout << mSubVision->getYaw() << std::endl;
 // std::cout << mPIDController->GetSetpoint() << std::endl;

  return mPIDController->AtSetpoint();
}
