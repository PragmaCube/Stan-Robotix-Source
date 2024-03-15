// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "commands/Avancer.h"
#include "commands/TurnRight.h"
#include "commands/ElevatorMiddle.h"
#include "commands/PivotDown.h"
#include "commands/Amplificateur.h"
#include "commands/Pickup.h"
#include"commands/PosStorage.h"
#include "commands/EjectorIn.h"
#include "commands/EjectorOut.h"

#include "subsystems/ExampleSubsystem.h"

namespace autos {
enum ePeriodAuto
  {
    AvancerSolo,
    BlueAlliance,
    BlueAllianceLong,
    RedAlliance,  
    RedAllianceLong
  };
frc2::CommandPtr Auto(SubDriveTrain *iDriveTrain, SubIMU *iIMU, SubElevator *iElevator, SubPivot *iPivot, SubEjector *iEjector, ePeriodAuto iPeriodAuto, ExampleSubsystem *subsystem);
}  // namespace autos
