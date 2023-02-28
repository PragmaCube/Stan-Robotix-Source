// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "../subsystems/PerformanceMonitor.h"
#include "subsystems/SubDriveTrain.h"
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
 float mSpeed =1;
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

private:
  frc::Timer mGenericTimer;
  RobotContainer *mRobotContainer;

  SubIMU * mSubIMU = nullptr;
  SubDriveTrain * mSubDriveTrain = nullptr;

  bool mSubsystemLogEnabled = false;

  enum ChargeDir_t {eNotInit, eForward, eBackward};
  ChargeDir_t mCurrentDir = eNotInit;
};
