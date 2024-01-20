// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include <frc/controller/PIDController.h>
#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubIMU.h"
#include "RobotContainer.h"
#include "Constants.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class TurnLeft
    : public frc2::CommandHelper<frc2::Command, TurnLeft> {
 public:
  TurnLeft(SubDriveTrain* iDriveTrain, SubIMU* iIMU);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
 
    SubDriveTrain* mDriveTrain;
    SubIMU* mIMU;

    frc::PIDController mPIDController {0.2, 1.2, 0.1};
    double Output;
};
