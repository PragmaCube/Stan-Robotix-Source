// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "../subsystems/PerformanceMonitor.h"
#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubLimelight.h"
#include "subsystems/SubIMU.h"

class RobotContainer;

class AutoFinalStabilisation : public PerformanceMonitor
{
private:
  enum step_t
  {
    Phase1_,
   PhaseFinish,
  };
  step_t mCurrentStep;

public:
  /**
   * Creates a new ExampleCommand.
   *
   * @param subsystem The subsystem used by this command.
   */
  AutoFinalStabilisation(RobotContainer *iRobotContainer);

  void Init();

  void EnableSubsystemLog(bool iEnable) { mSubsystemLogEnabled = iEnable; }

  virtual void doExecute();

  virtual bool isFinish();
  virtual void Reset();

  virtual std::string getName() { return "AutoFinalStabilisation"; }

  void End(bool interrupted);

  void doExecutePhase1();
 

  bool isPhase1Finished();

private:
  frc::Timer mGenericTimer;
  RobotContainer *mRobotContainer;

  SubDriveTrain * mSubDriveTrain = nullptr;
  SubLimelight * mSubLimelight = nullptr;

  bool mSubsystemLogEnabled = false;
};
