// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/PIDCommand.h>
#include "LimelightHelpers.h"
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <networktables/GenericEntry.h>
#include <frc/shuffleboard/BuiltInWidgets.h>
#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubIMU.h"
class GoToTag
    : public frc2::CommandHelper<frc2::CommandBase, GoToTag> {
 public:
  GoToTag(SubDriveTrain *iDriveTrain);


  void Execute() override;
  bool IsFinished() override;
 private:
  nt::GenericEntry* mCoefP = nullptr;
  nt::GenericEntry* mCoefI = nullptr;
  nt::GenericEntry* mCoefD = nullptr;
  SubDriveTrain *mDriveTrain = nullptr;
  frc2::PIDController mPIDController {0.2, 1.2, 0.1};
  double Output;
};
