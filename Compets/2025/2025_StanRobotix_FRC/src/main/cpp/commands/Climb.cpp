// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Climb.h"

Climb::Climb(SubAlgaePivot * iAlgaePivot, frc::Joystick * iJoystick) {
  mAlgaePivot = iAlgaePivot;
  AddRequirements(mAlgaePivot);

  mJoystick = iJoystick;
}

// Called when the command is initially scheduled.
void Climb::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Climb::Execute() {
  mAlgaePivot->Climb();
}

// Called once the command ends or is interrupted.
void Climb::End(bool interrupted) {
  mAlgaePivot->StayStill();
}

// Returns true when the command should end.
bool Climb::IsFinished() {
  return mJoystick->GetRawButtonReleased(JoystickBindingsConstants::kClimb);
}
