// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc2/command/Commands.h>

#include "commands/ExampleCommand.h"
#include "commands/Autos.h"

frc2::CommandPtr autos::Auto(SubDriveTrain* iDriveTrain, SubIMU* iIMU, SubElevator *iElevator, SubPivot *iPivot, SubEjector *iEjector ,ePeriodAuto iPeriodAuto, ExampleSubsystem *subsystem = new ExampleSubsystem()) {
  
  switch (iPeriodAuto)
      {
        case FowardSolo:
          return frc2::cmd::Sequence(Foward(iDriveTrain, 0.8).ToPtr());
          break;
        case BlueAlliance:
          return frc2::cmd::Sequence(Foward(iDriveTrain, 0.8).ToPtr(), TurnLeft(iDriveTrain, iIMU).ToPtr(),PosStorage(iPivot, iElevator).ToPtr(), GoToTag(iDriveTrain).ToPtr(), Foward(iDriveTrain, 0.1).ToPtr(), Amplificator(iPivot, iElevator).ToPtr(), EjectorOut(iEjector, EjectorConstants::kEjectorOutDownTime).ToPtr());
          break;
        case BlueAllianceLong:
          return frc2::cmd::Sequence(Foward(iDriveTrain, 0.8).ToPtr(), TurnLeft(iDriveTrain, iIMU).ToPtr(), Foward(iDriveTrain, 2).ToPtr(),PosStorage(iPivot, iElevator).ToPtr(), GoToTag(iDriveTrain).ToPtr(), Foward(iDriveTrain, 0.1).ToPtr(), Amplificator(iPivot, iElevator).ToPtr(), EjectorOut(iEjector, EjectorConstants::kEjectorOutDownTime).ToPtr());
          break;
        case RedAlliance:
          return frc2::cmd::Sequence(Foward(iDriveTrain, 0.8).ToPtr(), TurnRight(iDriveTrain, iIMU).ToPtr(), PosStorage(iPivot, iElevator).ToPtr(), GoToTag(iDriveTrain).ToPtr(), Foward(iDriveTrain, 0.1).ToPtr(), Amplificator(iPivot, iElevator).ToPtr(), EjectorOut(iEjector, EjectorConstants::kEjectorOutDownTime).ToPtr());
          break;
        case RedAllianceLong:
          return frc2::cmd::Sequence(Foward(iDriveTrain, 0.8).ToPtr(), TurnRight(iDriveTrain, iIMU).ToPtr(), Foward(iDriveTrain, 2).ToPtr(),PosStorage(iPivot, iElevator).ToPtr(), GoToTag(iDriveTrain).ToPtr(), Foward(iDriveTrain, 0.1).ToPtr(), Amplificator(iPivot, iElevator).ToPtr(), EjectorOut(iEjector, EjectorConstants::kEjectorOutDownTime).ToPtr());
          break;
        default:
          return frc2::cmd::Sequence(subsystem->ExampleMethodCommand(),
                          ExampleCommand(subsystem).ToPtr());
        }
      }
