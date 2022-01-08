// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ParallelRaceGroup.h>

#include "subsystems/DriveTrain.h"
#include "subsystems/Solenoid.h"

class Parallel
    : public frc2::CommandHelper<frc2::ParallelRaceGroup,
                                 Parallel> {
 public:
  Parallel();
  Parallel(SubDriveTrain* iDriveTrain, SubSolenoid* iPiston);
};
