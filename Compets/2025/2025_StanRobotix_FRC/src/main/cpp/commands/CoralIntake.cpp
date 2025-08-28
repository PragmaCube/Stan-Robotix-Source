// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CoralIntake.h"
#include <frc/shuffleboard/Shuffleboard.h>

CoralIntake::CoralIntake(SubCoralIntake *iCoralIntake) {
  // Use addRequirements() here to declare subsystem dependencies.
  mCoralIntake = iCoralIntake;
  
  AddRequirements(mCoralIntake);
  
}

// Called when the command is initially scheduled.
void CoralIntake::Initialize() {
    frc::Shuffleboard::GetTab("Main Tab").Add("CoralIntake", true).GetEntry()->SetBoolean(true);

}

// Called repeatedly when this Command is scheduled to run
void CoralIntake::Execute() {
  mCoralIntake->SetPercentage(0.45);
}

// Called once the command ends or is interrupted.
void CoralIntake::End(bool interrupted) {
  mCoralIntake->Stop();
    frc::Shuffleboard::GetTab("Main Tab").Add("CoralIntake", true).GetEntry()->SetBoolean(false);

}

// Returns true when the command should end.
bool CoralIntake::IsFinished() {
  return false;
}
