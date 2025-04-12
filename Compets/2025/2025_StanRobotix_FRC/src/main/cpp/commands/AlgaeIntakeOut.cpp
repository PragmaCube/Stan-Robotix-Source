// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AlgaeOuttake.h"
#include <frc/shuffleboard/Shuffleboard.h>

AlgaeOuttake::AlgaeOuttake(SubAlgaeIntake *iSubAlgaeIntake, frc::XboxController *iJoystick) {
  // Use addRequirements() here to declare subsystem dependencies.
  mAlgaeIntake = iSubAlgaeIntake;
  mJoystick = iJoystick;
  AddRequirements(mAlgaeIntake);
}

// Called when the command is initially scheduled.
void AlgaeOuttake::Initialize() {
  Timer = -1;
  frc::Shuffleboard::GetTab("Main Tab").Add("AlgaeOuttake", true).GetEntry()->SetBoolean(true);

}

// Called repeatedly when this Command is scheduled to run
void AlgaeOuttake::Execute() {
  mAlgaeIntake->Intake(0.45);
  Timer++;
}

// Called once the command ends or is interrupted.
void AlgaeOuttake::End(bool interrupted) {
    frc::Shuffleboard::GetTab("Main Tab").Add("AlgaeOuttake", true).GetEntry()->SetBoolean(false);
}

// Returns true when the command should end.
bool AlgaeOuttake::IsFinished() {
  return false;
}
