/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Command.h>
#include <Subsystems/StraightPID.h>
#include "Robot.h"

class Advance : public frc::Command {
 public:
  Advance(double iDistance, StraightPID *iPid, bool dynamicDistance = false);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

  double mTargetDistance;
  double mDistanceIncrement;
  bool mDynamicDistance;

  StraightPID * mSPidPtr;
};
