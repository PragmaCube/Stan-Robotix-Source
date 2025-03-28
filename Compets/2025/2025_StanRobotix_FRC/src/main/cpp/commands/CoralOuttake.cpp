// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CoralOuttake.h"
#include <frc/shuffleboard/Shuffleboard.h>

CoralOuttake::CoralOuttake(SubCoralIntake *iCoralIntake, frc::XboxController *iJoystick ) {
  // Use addRequirements() here to declare subsystem dependencies.
  mCoralIntake = iCoralIntake;
  mJoystick = iJoystick;
  AddRequirements(mCoralIntake);
}

// Called when the command is initially scheduled.
void CoralOuttake::Initialize() {
  Timer = -1;
    frc::Shuffleboard::GetTab("Main Tab").Add("CoralOuttake", true).GetEntry()->SetBoolean(true);

}

// Called repeatedly when this Command is scheduled to run
void CoralOuttake::Execute() {
  mCoralIntake->Intake(-0.6);
  Timer++;
}

// Called once the command ends or is interrupted.
void CoralOuttake::End(bool interrupted) {
  mCoralIntake->Stop();
    frc::Shuffleboard::GetTab("Main Tab").Add("CoralOuttake", true).GetEntry()->SetBoolean(false);

}

// Returns true when the command should end.
bool CoralOuttake::IsFinished() {
  return Timer >= 50;
}
