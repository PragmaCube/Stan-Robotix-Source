// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include <frc/controller/PIDController.h>

#include "subsystems/SubCameraVision.h"
#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubIMU.h"

#include "Constants.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class VisionGoToAlgae
    : public frc2::CommandHelper<frc2::Command, VisionGoToAlgae> {
 public:
  /* You should consider using the more terse Command factories API instead
   * https://docs.wpilib.org/en/stable/docs/software/commandbased/organizing-command-based.html#defining-commands
   */
  VisionGoToAlgae(SubDriveTrain*, SubCameraVision*);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
  SubDriveTrain * mSubDriveTrain;
  SubCameraVision * mSubVision;
  double PIDOut;
  frc::PIDController * mPIDController;
  int i;
  bool gotAValue;
  int iVect;
};
