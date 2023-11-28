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
class GoToTag
    : public frc2::CommandHelper<frc2::PIDCommand, GoToTag> {
 public:
  GoToTag();

  bool IsFinished() override;
 private:
  nt::GenericEntry* mCoefP;
  nt::GenericEntry* mCoefI;
  nt::GenericEntry* mCoefD;
  


    
};
