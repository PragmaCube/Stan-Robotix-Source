
#pragma once

#include <frc/Timer.h>
#include <frc2/command/CommandHelper.h>
#include <frc/controller/PIDController.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <networktables/GenericEntry.h>
#include <frc/shuffleboard/BuiltInWidgets.h>

#include "LimelightHelpers.h"
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
  nt::GenericEntry* mCoefPAngle = nullptr;
  nt::GenericEntry* mCoefIAngle = nullptr;
  nt::GenericEntry* mCoefDAngle = nullptr;

  nt::GenericEntry* mCoefPX = nullptr;
  nt::GenericEntry* mCoefIX = nullptr;
  nt::GenericEntry* mCoefDX = nullptr;

  nt::GenericEntry* mCoefPY = nullptr;
  nt::GenericEntry* mCoefIY = nullptr;
  nt::GenericEntry* mCoefDY = nullptr;

  SubDriveTrain *mDriveTrain = nullptr;

  frc::PIDController mPIDControllerAngle {1, 0, 0};
  frc::PIDController mPIDControllerX {1, 0, 0};
  frc::PIDController mPIDControllerY {1, 0, 0};

  double OutputAngle;
  double OutputX;
  double OutputY;
  float SetPoint;
  bool WrongTag = false; 
  frc::Timer mTimer;
};