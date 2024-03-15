// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/Timer.h>
#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

 #include "subsystems/SubDriveTrain.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class Avancer

    : public frc2::CommandHelper<frc2::Command, Avancer> {
 public:
  Avancer(SubDriveTrain* iDriveTrain, double iSecondes);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
    SubDriveTrain* mDriveTrain;
    double mDuree;
    frc::Timer mTimer;
    
};