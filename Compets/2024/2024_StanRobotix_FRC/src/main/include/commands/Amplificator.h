// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/Timer.h>
#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/SubPivot.h"
#include "subsystems/SubElevator.h"


/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class Amplificator
    : public frc2::CommandHelper<frc2::Command, Amplificator> {
 public:
  Amplificator(SubPivot *iPivot, SubElevator *iElevator);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
  SubPivot *mPivot;
  SubElevator *mElevator;
  double mDuration = 3.4;
  frc::Timer mTimer;
    
};
