// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "commands/Avancer.h"
#include "commands/TurnRight.h"
#include "commands/AscenseurMilieu.h"
#include "commands/PivotDown.h"
#include "commands/Amplificateur.h"
#include "commands/Pickup.h"
#include"commands/PosStorage.h"
#include "commands/EjectorIn.h"
#include "commands/EjectorOut.h"

class Automatisation
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 Automatisation> {
 public:
  enum ePeriodAuto
  {
    AvancerSolo,
    BlueAlliance,
    BlueAllianceLong,
    RedAlliance,  
    RedAllianceLong
  };

  Automatisation(SubDriveTrain *iDriveTrain, SubIMU *iIMU, SubAscenseur *iAscenseur, SubPivot *iPivot, SubEjector *iEjector, ePeriodAuto iPeriodAuto);
  

  private:
    
};