// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Autos.h"

#include <frc2/command/Commands.h>

#include "commands/ExampleCommand.h"

frc2::CommandPtr autos::Auto(SubDriveTrain* iDriveTrain, SubIMU* iIMU, SubAscenseur *iAscenseur, SubPivot *iPivot, SubEjector *iEjector ,ePeriodAuto iPeriodAuto, ExampleSubsystem *subsystem = new ExampleSubsystem()) {
  
  switch (iPeriodAuto)
      {
        case AvancerSolo:
          return frc2::cmd::Sequence(Avancer(iDriveTrain, 0.8).ToPtr());
          break;
        case BlueAlliance:
          return frc2::cmd::Sequence(Avancer(iDriveTrain, 0.8).ToPtr(), TurnLeft(iDriveTrain, iIMU).ToPtr(),PosStorage(iPivot, iAscenseur).ToPtr(), GoToTag(iDriveTrain).ToPtr(), Avancer(iDriveTrain, 0.1).ToPtr(), Amplificateur(iPivot, iAscenseur).ToPtr(), EjectorOut(iEjector, EjectorConstants::kEjectorOutDownTime).ToPtr());
          break;
        case BlueAllianceLong:
          return frc2::cmd::Sequence(Avancer(iDriveTrain, 0.8).ToPtr(), TurnLeft(iDriveTrain, iIMU).ToPtr(), Avancer(iDriveTrain, 2).ToPtr(),PosStorage(iPivot, iAscenseur).ToPtr(), GoToTag(iDriveTrain).ToPtr(), Avancer(iDriveTrain, 0.1).ToPtr(), Amplificateur(iPivot, iAscenseur).ToPtr(), EjectorOut(iEjector, EjectorConstants::kEjectorOutDownTime).ToPtr());
          break;
        case RedAlliance:
          return frc2::cmd::Sequence(Avancer(iDriveTrain, 0.8).ToPtr(), TurnRight(iDriveTrain, iIMU).ToPtr(), PosStorage(iPivot, iAscenseur).ToPtr(), GoToTag(iDriveTrain).ToPtr(), Avancer(iDriveTrain, 0.1).ToPtr(), Amplificateur(iPivot, iAscenseur).ToPtr(), EjectorOut(iEjector, EjectorConstants::kEjectorOutDownTime).ToPtr());
          break;
        case RedAllianceLong:
          return frc2::cmd::Sequence(Avancer(iDriveTrain, 0.8).ToPtr(), TurnRight(iDriveTrain, iIMU).ToPtr(), Avancer(iDriveTrain, 2).ToPtr(),PosStorage(iPivot, iAscenseur).ToPtr(), GoToTag(iDriveTrain).ToPtr(), Avancer(iDriveTrain, 0.1).ToPtr(), Amplificateur(iPivot, iAscenseur).ToPtr(), EjectorOut(iEjector, EjectorConstants::kEjectorOutDownTime).ToPtr());
          break;
        default:
          return frc2::cmd::Sequence(subsystem->ExampleMethodCommand(),
                          ExampleCommand(subsystem).ToPtr());
        }
      }
