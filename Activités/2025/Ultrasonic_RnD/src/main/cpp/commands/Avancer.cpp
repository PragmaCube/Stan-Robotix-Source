// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <iostream>

#include "commands/Avancer.h"

Avancer::Avancer(SubDriveTrain* iDriveTrain, UltrasoundSubsystem* iUltrasound) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(iDriveTrain);
  AddRequirements(iUltrasound);
  mDriveTrain = iDriveTrain;
  mUltrasound = iUltrasound;
}

// Called when the command is initially scheduled.
void Avancer::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Avancer::Execute() {
  mDriveTrain->mecanumDrive(0.25, 0, -0.25);
  std::cout << "Commande executée!" << std::endl;
}

// Called once the command ends or is interrupted.
void Avancer::End(bool interrupted) {
  mDriveTrain->mecanumDrive(0, 0, 0);
}

// Returns true when the command should end.
bool Avancer::IsFinished() {
  return abs(AvancerConstants::kTargetDistance - mUltrasound->getValue()) < AvancerConstants::kErrorMargin
  || AvancerConstants::kTargetDistance < AvancerConstants::kMinDistance
  || AvancerConstants::kTargetDistance > AvancerConstants::kMaxDistance;
}
