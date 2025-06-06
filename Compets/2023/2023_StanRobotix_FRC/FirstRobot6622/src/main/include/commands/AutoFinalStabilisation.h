// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/PIDCommand.h>
#include <frc/controller/PIDController.h>
#include "../subsystems/PerformanceMonitor.h"
#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubIMU.h"

class AutoFinalStabilisation : public PerformanceMonitor
{
public:
  /**
   * Creates a new ExampleCommand.
   *
   * @param subsystem The subsystem used by this command.
   */
  AutoFinalStabilisation(RobotContainer *iRobotContainer);

  void Init();

  virtual void doExecute();

  virtual bool isFinish();
  virtual void Reset();

  virtual std::string getName() { return "AutoFinalStabilisation"; }

private:
  frc::Timer mGenericTimer;
  float mSpeed =1;

  SubIMU * mSubIMU = nullptr;
  SubDriveTrain * mSubDriveTrain = nullptr;

  enum ChargeDir_t {eNotInit, eForward, eBackward};
  ChargeDir_t mCurrentDir = eNotInit;

  frc2::PIDController mPitchController{0.3f, 0.1f, 0.2f}; // TODO : A tuner par-ce que pas teste
