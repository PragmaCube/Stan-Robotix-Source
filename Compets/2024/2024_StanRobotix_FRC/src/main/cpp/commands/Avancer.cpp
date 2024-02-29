// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Avancer.h"

Avancer::Avancer(SubDriveTrain *iDriveTrain, double iSecondes) {
  // Use addRequirements() here to declare subsystem dependencies.
  mDriveTrain=iDriveTrain;
  mDuree = iSecondes;
  AddRequirements(mDriveTrain);
}

// Called when the command is initially scheduled.
void Avancer::Initialize() {
  mTimer.Start();
}

// Called repeatedly when this Command is scheduled to run
void Avancer::Execute() {
      mDriveTrain->mecanumDrive(0, -AvancerConstants::Vitesse, 0, frc::Rotation2d(0_rad));
}

// Called once the command ends or is interrupted.
void Avancer::End(bool interrupted) {}

// Returns true when the command should end.
bool Avancer::IsFinished() {
  return mTimer.Get().value() > mDuree;
}