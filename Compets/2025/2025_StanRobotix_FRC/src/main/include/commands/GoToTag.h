// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include <frc/kinematics/ChassisSpeeds.h>

#include "commands/CoralPivotUp.h"

#include "subsystems/SubDriveTrain.h"

#include "LimelightHelpers.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class GoToTag
    : public frc2::CommandHelper<frc2::Command, GoToTag> {
 public:
  /* You should consider using the more terse Command factories API instead
   * https://docs.wpilib.org/en/stable/docs/software/commandbased/organizing-command-based.html#defining-commands
   */
  GoToTag(SubDriveTrain*, SubIMU*);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private :
    // frc::PIDController mPIDControllerAngle {0.08, 0, 0.017};
    // frc::PIDController mPIDControllerX {0.8, 0, 0.0};
    frc::PIDController mPIDControllerAngle {0.15, 0, 0.015};
    frc::PIDController mPIDControllerX {0.8, 0, 0.0};
    frc::PIDController mPIDControllerY {1.0, 0, 0.1};

    double OutputAngle;
    double OutputX;
    double OutputY;

    frc::ChassisSpeeds speeds;    

    int Timer = -1;

    int TimerSkip = 0;

    SubDriveTrain * mSubDriveTrain;
    SubIMU * mSubIMU;
  };
