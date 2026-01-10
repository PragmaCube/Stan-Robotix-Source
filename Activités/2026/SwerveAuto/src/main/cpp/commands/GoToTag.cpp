// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/GoToTag.h"
#include <frc/shuffleboard/Shuffleboard.h>


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

  mPIDControllerX.SetTolerance(0.1);
  mPIDControllerAngle.SetTolerance(0.1);
  mPIDControllerY.SetTolerance(0.2);

  frc::Shuffleboard::GetTab("Main Tab").Add("GoToTag", true).GetEntry()->SetBoolean(true);

}

// Called repeatedly when this Command is scheduled to run
void GoToTag::Execute() {
  OutputAngle = mPIDControllerAngle.Calculate(LimelightHelpers::getTX(""), 0) ; 
  // std::cout << LimelightHelpers::getTX("") << std::endl;
  OutputX = mPIDControllerX.Calculate(LimelightHelpers::getCameraPose_TargetSpace().at(0), 0) ; 
  OutputY = mPIDControllerY.Calculate(LimelightHelpers::getCameraPose_TargetSpace().at(2), -0.3) ;

  speeds = frc::ChassisSpeeds{units::meters_per_second_t(OutputY), 
  -units::meters_per_second_t(OutputX), units::radians_per_second_t(OutputAngle)};

  mSubDriveTrain->driveRobotRelative(speeds, 1); 

  Timer++;

  if (int(LimelightHelpers::getTV()) == 0){
    TimerSkip++;
  } else {
    TimerSkip = 0;
  }

  std::cout << "Gototag actif" << std::endl;
}

// Called once the command ends or is interrupted.
void GoToTag::End(bool interrupted) {
  frc::Shuffleboard::GetTab("Main Tab").Add("GoToTag", true).GetEntry()->SetBoolean(false);
}

// Returns true when the command should end.
bool GoToTag::IsFinished() {
  return ((int(LimelightHelpers::getTV()) == 0) && (TimerSkip >= 5))  || ((mPIDControllerAngle.AtSetpoint()) && (mPIDControllerX.AtSetpoint()) && (mPIDControllerY.AtSetpoint()));
}
