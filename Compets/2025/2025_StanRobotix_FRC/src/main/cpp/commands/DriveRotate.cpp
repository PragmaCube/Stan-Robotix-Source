// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DriveRotate.h"

DriveRotate::DriveRotate(SubDriveTrain* iDriveTrain, units::degree_t iRotation) {
  // Use addRequirements() here to declare subsystem dependencies.
  mDriveTrain = iDriveTrain;
  AddRequirements(mDriveTrain);
  mRotation = units::radian_t(iRotation/360);
  mPose2d = frc::Pose2d(0_m, 0_m, 0_rad);
}

// Called when the command is initially scheduled.
void DriveRotate::Initialize() {
  mPIDController.SetSetpoint((double)mRotation);
  mPIDController.SetTolerance(0.05);}

// Called repeatedly when this Command is scheduled to run
void DriveRotate::Execute() {
  frc::ChassisSpeeds speeds = mDriveTrain->getRobotRelativeSpeeds();
  frc::ChassisSpeeds driveOutput = frc::ChassisSpeeds::FromRobotRelativeSpeeds(0_mps, 0_mps, units::radians_per_second_t(mPIDController.Calculate((double)speeds.omega)), 0_rad);
  mDriveTrain->driveRobotRelative(driveOutput);}

// Called once the command ends or is interrupted.
void DriveRotate::End(bool interrupted) {}

// Returns true when the command should end.
bool DriveRotate::IsFinished() {
  return mPIDController.AtSetpoint();
}
