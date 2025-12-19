// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h> 

#include "subsystems/UltrasoundSubsystem.h"
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
  /* You should consider using the more terse Command factories API instead
   * https://docs.wpilib.org/en/stable/docs/software/commandbased/organizing-command-based.html#defining-commands
   */
  Avancer(SubDriveTrain* iDriveTrain, UltrasoundSubsystem* iUltrasound);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  // Example: a motor controller

  SubDriveTrain* mDriveTrain;
  UltrasoundSubsystem* mUltrasound;
};
