// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TurnRight.h"

TurnRight::TurnRight(SubDriveTrain *iDrivetrain) {
  // Use addRequirements() here to declare subsystem dependencies.
  mDriveTrain = iDrivetrain;
}

// Called when the command is initially scheduled.
void TurnRight::Initialize() {
  startAngle = mIMU.getAngleYaw();
}

// Called repeatedly when this Command is scheduled to run
void TurnRight::Execute() {
  mDriveTrain->mecanumDrive(0, 0, 0.9);
  currentAngle = mIMU.getAngleYaw();
}

// Called once the command ends or is interrupted.
void TurnRight::End(bool interrupted) {}

// Returns true when the command should end.
bool TurnRight::IsFinished() {
  return currentAngle >= (startAngle + 90);
}
