// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Automatisation.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
Automatisation::Automatisation(SubDriveTrain* iDriveTrain, SubIMU* iIMU, SubAscenseur *iAscenseur, SubPivot *iPivot, SubEjector *iEjector ,ePeriodAuto iPeriodAuto) 
{
  switch (iPeriodAuto)
    {
      case AvancerSolo:
        AddCommands(Avancer(iDriveTrain, 0.8));
        break;
      case BlueAlliance:
        AddCommands(Avancer(iDriveTrain, 0.8), TurnLeft(iDriveTrain, iIMU),PosStorage(iPivot, iAscenseur), GoToTag(iDriveTrain), Avancer(iDriveTrain, 0.1), Amplificateur(iPivot, iAscenseur), EjectorOut(iEjector, EjectorConstants::kEjectorOutDownTime));
        break;
      case BlueAllianceLong:
        AddCommands(Avancer(iDriveTrain, 0.8), TurnLeft(iDriveTrain, iIMU), Avancer(iDriveTrain, 2),PosStorage(iPivot, iAscenseur), GoToTag(iDriveTrain), Avancer(iDriveTrain, 0.1), Amplificateur(iPivot, iAscenseur), EjectorOut(iEjector, EjectorConstants::kEjectorOutDownTime));
        break;
      case RedAlliance:
        AddCommands(Avancer(iDriveTrain, 0.8), TurnRight(iDriveTrain, iIMU),PosStorage(iPivot, iAscenseur), GoToTag(iDriveTrain), Avancer(iDriveTrain, 0.1), Amplificateur(iPivot, iAscenseur), EjectorOut(iEjector, EjectorConstants::kEjectorOutDownTime));
        break;
      case RedAllianceLong:
        AddCommands(Avancer(iDriveTrain, 0.8), TurnRight(iDriveTrain, iIMU), Avancer(iDriveTrain, 2),PosStorage(iPivot, iAscenseur), GoToTag(iDriveTrain), Avancer(iDriveTrain, 0.1), Amplificateur(iPivot, iAscenseur), EjectorOut(iEjector, EjectorConstants::kEjectorOutDownTime));
        break;
    }
  // AddCommands(Avancer(iDriveTrain, 2), TurnRight(iDriveTrain, iIMU), GoToTag(iDriveTrain), AscenseurMilieu(iAscenseur), PivotDown(iPivot, iAscenseur));
}