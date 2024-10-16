// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "commands/Foward.h"
#include "commands/TurnRight.h"
#include "commands/ElevatorMiddle.h"
#include "commands/PivotDown.h"
#include "commands/Amplificator.h"
#include "commands/Pickup.h"
#include"commands/PosStorage.h"
#include "commands/EjectorIn.h"
#include "commands/EjectorOut.h"

class Automatisation : public frc2::CommandHelper<frc2::SequentialCommandGroup, Automatisation> 
{
 public:
  enum ePeriodAuto
  {
    FowardSolo,
    BlueAlliance,
    BlueAllianceLong,
    RedAlliance,  
    RedAllianceLong
  };

  Automatisation(SubDriveTrain *iDriveTrain, SubIMU *iIMU, SubElevator *iElevator, SubPivot *iPivot, SubEjector *iEjector, ePeriodAuto iPeriodAuto);
  //JSON_BINARY_READER_MAKE_BJD_OPTIMIZED_TYPE_MARKERS_

  private:
    
};