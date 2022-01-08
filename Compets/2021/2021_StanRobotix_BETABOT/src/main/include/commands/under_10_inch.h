// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/DriveTrain.h"
#include "subsystems/SubPotentiometer.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class under_10_inch
    : public frc2::CommandHelper<frc2::CommandBase, under_10_inch> {
      SubDriveTrain* mDriveTrain;
      SubPotentiometer* mUltrasonic;

 public:
  under_10_inch();
  under_10_inch(SubDriveTrain* iDriveTrain);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

};
