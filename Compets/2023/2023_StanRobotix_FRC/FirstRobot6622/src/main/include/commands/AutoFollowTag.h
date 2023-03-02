// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/PIDCommand.h>
#include <frc/controller/PIDController.h>
#include "../subsystems/PerformanceMonitor.h"
#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubLimelight.h"
#include "Constants.h"

class RobotContainer;

class AutoFollowTag : public PerformanceMonitor
    /*: public frc2::CommandHelper<frc2::PIDCommand, AutoFollowTag> */{
 public:
  AutoFollowTag(RobotContainer *iRobotContainer);

  void Init();

  void EnableSubsystemLog(bool iEnable) { mSubsystemLogEnabled = iEnable; }

  virtual void doExecute();

  virtual bool isFinish();
  virtual void reset();

  virtual std::string getName() { return "AutoCmdExample"; }

  void End(bool interrupted);
  
  
  // bool IsFinished() override;
  private:
  frc::Timer mGenericTimer;
  RobotContainer *mRobotContainer;

  SubDriveTrain * mSubDriveTrain = nullptr;
  SubLimelight * mSubLimelight = nullptr;
  frc2::PIDController mController{0.05f, 0, 0};
  bool mSubsystemLogEnabled = false;
};
