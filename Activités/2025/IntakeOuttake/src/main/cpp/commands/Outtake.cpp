// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Outtake.h"

Outtake::Outtake(SubIntake * iIntake, frc2::JoystickButton * iButton) {
  // Use addRequirements() here to declare subsystem dependencies.
  mIntake = iIntake;
  mButton = iButton;
  AddRequirements(mIntake);
}

// Called when the command is initially scheduled.
void Outtake::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Outtake::Execute() {
  mIntake->Outtake();
}

// Called once the command ends or is interrupted.
void Outtake::End(bool interrupted) {
  mIntake->StopMotor();
}

// Returns true when the command should end.
bool Outtake::IsFinished() {
  return !mButton->Get();
}
