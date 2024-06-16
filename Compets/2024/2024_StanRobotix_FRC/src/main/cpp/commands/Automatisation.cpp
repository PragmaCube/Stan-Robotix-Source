// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Automatisation.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
Automatisation::Automatisation(SubDriveTrain* iDriveTrain, SubIMU* iIMU, SubElevator *iElevator, SubPivot *iPivot, SubEjector *iEjector ,ePeriodAuto iPeriodAuto) 
{
  switch (iPeriodAuto)
    {
      case FowardSolo:
        AddCommands(Foward(iDriveTrain, 0.8));
        break;
      case BlueAlliance:
        AddCommands(Foward(iDriveTrain, 0.8), TurnLeft(iDriveTrain, iIMU),PosStorage(iPivot, iElevator), GoToTag(iDriveTrain), Foward(iDriveTrain, 0.1), Amplificator(iPivot, iElevator), EjectorOut(iEjector, EjectorConstants::kEjectorOutDownTime));
        break;
      case BlueAllianceLong:
        AddCommands(Foward(iDriveTrain, 0.8), TurnLeft(iDriveTrain, iIMU), Foward(iDriveTrain, 2),PosStorage(iPivot, iElevator), GoToTag(iDriveTrain), Foward(iDriveTrain, 0.1), Amplificator(iPivot, iElevator), EjectorOut(iEjector, EjectorConstants::kEjectorOutDownTime));
        break;
      case RedAlliance:
        AddCommands(Foward(iDriveTrain, 0.8), TurnRight(iDriveTrain, iIMU),PosStorage(iPivot, iElevator), GoToTag(iDriveTrain), Foward(iDriveTrain, 0.1), Amplificator(iPivot, iElevator), EjectorOut(iEjector, EjectorConstants::kEjectorOutDownTime));
        break;
      case RedAllianceLong:
        AddCommands(Foward(iDriveTrain, 0.8), TurnRight(iDriveTrain, iIMU), Foward(iDriveTrain, 2),PosStorage(iPivot, iElevator), GoToTag(iDriveTrain), Foward(iDriveTrain, 0.1), Amplificator(iPivot, iElevator), EjectorOut(iEjector, EjectorConstants::kEjectorOutDownTime));
        break;
    }
  // AddCommands(Foward(iDriveTrain, 2), TurnRight(iDriveTrain, iIMU), GoToTag(iDriveTrain), ElevatorMiddle(iElevator), PivotDown(iPivot, iElevator));
}