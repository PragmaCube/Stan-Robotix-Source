/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Command.h>
#include <RobotMap.h>
#include "Robot.h"

class Turn : public frc::Command {
 private:
  double mTargetAngle;
  double mAngleIncrement;
  RotationPID* mRPidPtr;
  bool mDynamicAngle;

 public:
  Turn(double iAngle, RotationPID *iPid, bool dynamicAngle = false);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};