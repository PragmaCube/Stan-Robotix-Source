// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Parallel.h"
#include "commands/MoveStraightXSeconds.h"
#include "commands/PistonPulse.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
Parallel::Parallel() {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
}

Parallel::Parallel(SubDriveTrain* iDriveTrain, SubSolenoid* iPiston)
{
 // AddCommands(MoveStraightXSeconds(iDriveTrain).WithTimeout(2.6_s), PistonPulse(iPiston, false));
}
