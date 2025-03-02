// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CoralOuttake.h"

CoralOuttake::CoralOuttake(SubCoralIntake *iCoralIntake, frc::Joystick *iJoystick ) {
  // Use addRequirements() here to declare subsystem dependencies.
  mCoralIntake = iCoralIntake;
  mJoystick = iJoystick;
  AddRequirements(mCoralIntake);
}

// Called when the command is initially scheduled.
void CoralOuttake::Initialize() {
  mCoralIntake->SetCommandsState(true);
}

// Called repeatedly when this Command is scheduled to run
void CoralOuttake::Execute() {
  mCoralIntake->Outtake();
}

// Called once the command ends or is interrupted.
void CoralOuttake::End(bool interrupted) {
  mCoralIntake->Stop();
}

// Returns true when the command should end.
bool CoralOuttake::IsFinished() {
  return (mJoystick->GetRawButtonReleased(JoystickBindingsConstants::Coral::kManualOut)) || (!mCoralIntake->GetCommandsState());
}
