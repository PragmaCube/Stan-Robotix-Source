// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DriveForward.h"

DriveForward::DriveForward(SubDriveTrain* iDriveTrain, units::meter_t iDistance) {
  // Use addRequirements() here to declare subsystem dependencies.
  mDriveTrain = iDriveTrain;
  AddRequirements(mDriveTrain);
  mDistance = iDistance;
  mPose2d = frc::Pose2d(0_m, 0_m, 0_rad);
}

// Called when the command is initially scheduled.
void DriveForward::Initialize() {
  mPIDController.SetSetpoint((double)mDistance);
  mPIDController.SetTolerance(0.05);
}

// Called repeatedly when this Command is scheduled to run
void DriveForward::Execute() {
  frc::ChassisSpeeds speeds = mDriveTrain->getRobotRelativeSpeeds();
  frc::ChassisSpeeds driveOutput = frc::ChassisSpeeds::FromRobotRelativeSpeeds(units::meters_per_second_t(mPIDController.Calculate((double)speeds.vx)), 0_mps, 0_rad_per_s, 0_rad);
  mDriveTrain->driveRobotRelative(driveOutput);
}

// Called once the command ends or is interrupted.
void DriveForward::End(bool interrupted) {}

// Returns true when the command should end.
bool DriveForward::IsFinished() {
  return mPIDController.AtSetpoint();
}
