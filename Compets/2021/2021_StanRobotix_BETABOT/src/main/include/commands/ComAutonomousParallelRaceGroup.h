// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ParallelRaceGroup.h>

#include "commands/MoveStraightXSeconds.h"
#include "commands/PistonPulse.h"

class ComAutonomousParallelRaceGroup
    : public frc2::CommandHelper<frc2::ParallelRaceGroup,
                                 ComAutonomousParallelRaceGroup> {
 public:
  ComAutonomousParallelRaceGroup();
  ComAutonomousParallelRaceGroup(SubDriveTrain* iDriveTrain, SubSolenoid* iPiston);
};
