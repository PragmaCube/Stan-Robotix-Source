// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/SequentialGoToTag.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
SequentialGoToTag::SequentialGoToTag(SubDriveTrain * iSubDriveTrain, SubIMU * iSubIMU, SubCoralPivot * iSubCoralPivot) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand{}, BarCommand{});
  mSubDriveTrain = iSubDriveTrain;
  mSubIMU = iSubIMU;
  mSubCoralPivot = iSubCoralPivot;

  AddCommands(CoralPivotUp(mSubCoralPivot), GoToTag(mSubDriveTrain, mSubIMU));
}
