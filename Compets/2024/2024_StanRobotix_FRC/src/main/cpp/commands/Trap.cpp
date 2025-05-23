// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Trap.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
Trap::Trap(SubElevator *iElevator, SubPivot *iPivot) {
  // Add your commands here, e.g.
  AddCommands(TrapDown(iPivot, iElevator) , TrapUp(iPivot, iElevator), Amplificator(iPivot, iElevator));
  // AddCommands(FooCommand{}, BarCommand{});
}
