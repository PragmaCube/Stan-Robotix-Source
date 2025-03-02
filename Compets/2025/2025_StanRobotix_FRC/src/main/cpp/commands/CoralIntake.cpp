// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CoralIntake.h"

CoralIntake::CoralIntake(SubCoralIntake *iCoralIntake, frc::Joystick *iJoystick ) {
  // Use addRequirements() here to declare subsystem dependencies.
  mCoralIntake = iCoralIntake;
  mJoystick = iJoystick;
  AddRequirements(mCoralIntake);
}

// Called when the command is initially scheduled.
void CoralIntake::Initialize() {
  mCoralIntake->SetCommandsState(true);
}

// Called repeatedly when this Command is scheduled to run
void CoralIntake::Execute() {
  mCoralIntake->Intake();
}

// Called once the command ends or is interrupted.
void CoralIntake::End(bool interrupted) {
  mCoralIntake->Stop();
}

// Returns true when the command should end.
bool CoralIntake::IsFinished() {
  return (mJoystick->GetRawButtonReleased(JoystickBindingsConstants::Coral::kManualIn)) || (!mCoralIntake->GetCommandsState());
}
