// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AlgaeIntakeOut.h"
#include <frc/shuffleboard/Shuffleboard.h>

AlgaeIntakeOut::AlgaeIntakeOut(SubAlgaeIntake *iSubAlgaeIntake, frc::XboxController *iJoystick) {
  // Use addRequirements() here to declare subsystem dependencies.
  mAlgaeIntake = iSubAlgaeIntake;
  mJoystick = iJoystick;
  AddRequirements(mAlgaeIntake);
}

// Called when the command is initially scheduled.
void AlgaeIntakeOut::Initialize() {
  Timer = -1;
  frc::Shuffleboard::GetTab("Main Tab").Add("AlgaeIntakeOut", true).GetEntry()->SetBoolean(true);

}

// Called repeatedly when this Command is scheduled to run
void AlgaeIntakeOut::Execute() {
  mAlgaeIntake->Intake(0.2);
  Timer++;
}

// Called once the command ends or is interrupted.
void AlgaeIntakeOut::End(bool interrupted) {
  mAlgaeIntake->Stop();
    frc::Shuffleboard::GetTab("Main Tab").Add("AlgaeintakeOut", true).GetEntry()->SetBoolean(false);

}

// Returns true when the command should end.
bool AlgaeIntakeOut::IsFinished() {
  return Timer >= 50;
}
