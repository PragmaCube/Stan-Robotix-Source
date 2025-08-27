// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include <frc/controller/PIDController.h>

#include "Constants.h"

#include "subsystems/SubAlgaePivot.h"
#include "commands/AlgaeIntake.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class AlgaePivotDown
    : public frc2::CommandHelper<frc2::Command, AlgaePivotDown> {
 public:
  /* You should consider using the more terse Command factories API instead
   * https://docs.wpilib.org/en/stable/docs/software/commandbased/organizing-command-based.html#defining-commands
   */
  AlgaePivotDown(SubAlgaePivot * iAlgaePivot);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

private:

  frc::Joystick * mJoystick;

  SubAlgaePivot * mAlgaePivot;

  int Timer = -1; // true if the pivot reached its setpoint once.
  bool ReachedSetPoint = false; // Incremented in each iteration of the code, meaning each 20ms.
};
