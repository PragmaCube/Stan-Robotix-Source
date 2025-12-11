// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "subsystems/Drivetrain.h"

#include "subsystems/IMU.h"

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include <frc/controller/PIDController.h>

#include "Constants.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class TurnRight
    : public frc2::CommandHelper<frc2::Command, TurnRight> {
 public:
  /* You should consider using the more terse Command factories API instead
   * https://docs.wpilib.org/en/stable/docs/software/commandbased/organizing-command-based.html#defining-commands
   */
  TurnRight();

  void Initialize() override;

  void Execute() override;   

  void End(bool interrupted) override;

  bool IsFinished() override;

private :

IMU IMU;

Drivetrain Drivetrain;


frc::PIDController mPIDController{
PIDConstant::kPController,
PIDConstant::kIController,
PIDConstant::kDController
};


/*Laisser une note ggs 👍👍👍👍👍👍👍👍🕊️🕊️🕊️🕊️🕊️🕊️🕊️🕊️🕊️🕊️🕊️🕊️🕊️✈️✈️✈️✈️✈️✈️✈️✈️*/

};