// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TurnRight.h"
#include <iostream>

TurnRight::TurnRight(IMU * iImu, Drivetrain * iDrivetrain) {
  // Use AddRequirements() here to declare subsystem dependencies.
  mImu = iImu;
  mDrivetrain = iDrivetrain;

  AddRequirements(mImu);
  AddRequirements(mDrivetrain);

  InitialAngle = mImu->GetAngle();

  mPIDController.SetSetpoint(InitialAngle - 90);
  mPIDController.SetTolerance(1);
}

// Called when the command is initially scheduled.
void TurnRight::Initialize() {


}

// Called repeatedly when this Command is scheduled to run
void TurnRight::Execute() {  
  double Output = mPIDController.Calculate(mImu->GetAngle());

  mDrivetrain->Drive(Output * 0.5, - Output * 0.5);
  
  }

// Called once the command ends or is interrupted.
void TurnRight::End(bool interrupted) {}

// Returns true when the command should end.
bool TurnRight::IsFinished() {
  return mPIDController.AtSetpoint();
}