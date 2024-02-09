
#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc/controller/PIDController.h>
#include "LimelightHelpers.h"
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <networktables/GenericEntry.h>
#include <frc/shuffleboard/BuiltInWidgets.h>
#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubIMU.h"
#include "Constants.h"

class GoToTag
    : public frc2::CommandHelper<frc2::Command, GoToTag> {
 public:
  GoToTag(SubDriveTrain *iDriveTrain);

  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End(bool interrupted) override;
 private:
  nt::GenericEntry* mCoefP = nullptr;
  nt::GenericEntry* mCoefI = nullptr;
  nt::GenericEntry* mCoefD = nullptr;
  SubDriveTrain *mDriveTrain = nullptr;
  frc::PIDController mPIDController {50, 12, 0};
  double Output;
};