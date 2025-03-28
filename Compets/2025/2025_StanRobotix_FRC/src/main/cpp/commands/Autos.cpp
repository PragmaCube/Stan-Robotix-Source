// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Autos.h"

#include <frc2/command/Commands.h>

#include "commands/ExampleCommand.h"

frc2::CommandPtr autos::ExampleAuto(SubDriveTrain* mDrivetrain) {
  return frc2::cmd::Sequence(//subsystem->ExampleMethodCommand(),
                             //ExampleCommand(subsystem).ToPtr(),
                             DriveForward(mDrivetrain, 2_m).ToPtr(),
                             DriveRotate(mDrivetrain, 180_deg).ToPtr());
}
