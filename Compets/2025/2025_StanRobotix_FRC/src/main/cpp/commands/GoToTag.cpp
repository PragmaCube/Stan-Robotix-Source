// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/GoToTag.h"

GoToTag::GoToTag(SubDriveTrain * iSubDriveTrain, SubIMU * iSubIMU) {
  mSubDriveTrain = iSubDriveTrain;
  mSubIMU = iSubIMU;

  AddRequirements(mSubDriveTrain);
  AddRequirements(mSubIMU);
}

// Called when the command is initially scheduled.
void GoToTag::Initialize() {
  Timer = -1;
  mSubDriveTrain->driveFieldRelative(0, 0, 0);

  mPIDControllerAngle.SetTolerance(0.1);
  mPIDControllerX.SetTolerance(0.1);
}

// Called repeatedly when this Command is scheduled to run
void GoToTag::Execute() {
  OutputAngle = mPIDControllerAngle.Calculate(LimelightHelpers::getTX(""), 0) ; 
  // std::cout << LimelightHelpers::getTX("") << std::endl;
  OutputX = mPIDControllerX.Calculate(LimelightHelpers::getCameraPose_TargetSpace().at(0), 0) ; 
  OutputY = mPIDControllerY.Calculate(LimelightHelpers::getCameraPose_TargetSpace().at(2), 3) ;

  mSubDriveTrain->driveFieldRelative(-OutputX, 0, OutputAngle); 

  Timer++;
}

// Called once the command ends or is interrupted.
void GoToTag::End(bool interrupted) {}

// Returns true when the command should end.
bool GoToTag::IsFinished() {
  return (int(LimelightHelpers::getFiducialID()) != 1) || (Timer >= 150);
}
