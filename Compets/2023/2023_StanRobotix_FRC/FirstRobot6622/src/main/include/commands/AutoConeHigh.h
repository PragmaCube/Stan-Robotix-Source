// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "../subsystems/PerformanceMonitor.h"
#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubLimelight.h"

class AutoConeHigh : public PerformanceMonitor
{
private:
  enum step_t
  {
    Phase1_,
    Phase2_,
    phase3_,
    Phase4_,
    Phase5_,
    Phase6_,
    Phase7_,
    Phase8_,
    Phase9_,
    PhaseFinish
  };
  step_t mCurrentStep;

public:
  /**
   * Creates a new ExampleCommand.
   *
   * @param subsystem The subsystem used by this command.
   */
  AutoConeHigh(RobotContainer *iRobotContainer);

  void Init();

  virtual void doExecute();

  virtual bool isFinish();
  virtual void reset();

  virtual std::string getName() { return "AutoConeHigh"; }


  void doExecutePhase1();
  void doExecutePhase2();
  void doExecutePhase3();
  void doExecutePhase4();
  void doExecutePhase5();
  void doExecutePhase6();
  void doExecutePhase7();
  void doExecutePhase8();
  void doExecutePhase9();
  void doFinish();

  bool isPhase1Finished();
  bool isPhase2Finished();
  bool isPhase3Finished();
  bool isPhase4Finished();
  bool isPhase5Finished();
  bool isPhase6Finished();
  bool isPhase7Finished();
  bool isPhase8Finished();
  bool isPhase9Finished();

private:
  frc::Timer mGenericTimer;

  SubDriveTrain * mSubDriveTrain = nullptr;
  SubLimelight * mSubLimelight = nullptr;

};
