// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Climb.h"
#include <frc/shuffleboard/Shuffleboard.h>

Climb::Climb(SubAlgaePivot * iSubAlgaePivot, frc::Joystick * iJostick) {
  // Use addRequirements() here to declare subsystem dependencies.
  mSubAlgaePivot = iSubAlgaePivot;
  mJoystick = iJostick;

  AddRequirements(mSubAlgaePivot);
}

// Called when the command is initially scheduled.
void Climb::Initialize() {
  frc::Shuffleboard::GetTab("Main Tab").Add("Climb", true).GetEntry()->SetBoolean(true);

}

// Called repeatedly when this Command is scheduled to run
void Climb::Execute() {
  if (mJoystick->GetRawButton(JoystickBindingsConstants::kClimb))
  {
    mSubAlgaePivot->SetVoltage(AlgaeConstants::Pivot::ClimbRiseVoltage);
  } else if (mJoystick->GetRawButton(JoystickBindingsConstants::kClimb) == false) {
    mSubAlgaePivot->SetVoltage(AlgaeConstants::Pivot::ClimbNeutralVoltage);
  }

}

// Called once the command ends or is interrupted.
void Climb::End(bool interrupted) {
    frc::Shuffleboard::GetTab("Main Tab").Add("Climb", true).GetEntry()->SetBoolean(false);

}

// Returns true when the command should end.
bool Climb::IsFinished() {
  return false;
}
