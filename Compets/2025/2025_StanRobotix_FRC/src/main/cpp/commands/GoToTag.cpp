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

  mSubDriveTrain->driveFieldRelative(0, 0, 0, 1);


  // mPIDControllerX.SetP(frc::SmartDashboard::GetNumber("Angle P", 0.15));
  // mPIDControllerX.SetI(frc::SmartDashboard::GetNumber("Angle I", 0));
  // mPIDControllerX.SetD(frc::SmartDashboard::GetNumber("Angle D", 0.015));

  mPIDControllerX.SetTolerance(0.1);
  mPIDControllerAngle.SetTolerance(0.1);
  mPIDControllerY.SetTolerance(0.1);

}

// Called repeatedly when this Command is scheduled to run
void GoToTag::Execute() {
  OutputAngle = mPIDControllerAngle.Calculate(LimelightHelpers::getTX(""), 0) ; 
  // std::cout << LimelightHelpers::getTX("") << std::endl;
  OutputX = mPIDControllerX.Calculate(LimelightHelpers::getCameraPose_TargetSpace().at(0), 0) ; 
  OutputY = mPIDControllerY.Calculate(LimelightHelpers::getCameraPose_TargetSpace().at(2), -0.4) ;

  speeds = frc::ChassisSpeeds{units::meters_per_second_t(OutputY), -units::meters_per_second_t(OutputX), units::radians_per_second_t(OutputAngle)};

  mSubDriveTrain->driveRobotRelative(speeds, 1); 

  Timer++;

  if (int(LimelightHelpers::getFiducialID()) != 1){
    TimerSkip++;
  } else {
    TimerSkip = 0;
  }
}

// Called once the command ends or is interrupted.
void GoToTag::End(bool interrupted) {}

// Returns true when the command should end.
bool GoToTag::IsFinished() {
  return ((int(LimelightHelpers::getFiducialID()) != 1) && (TimerSkip >= 5))  || ((mPIDControllerAngle.AtSetpoint()) && (mPIDControllerX.AtSetpoint()) && (mPIDControllerY.AtSetpoint()));
}
