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

// AJOUT COMMANDE AUTOMATISEE
class AutoFollowTape : public PerformanceMonitor {
public:
  AutoFollowTape(RobotContainer *iRobotContainer);

  void Init();

  virtual void doExecute();

  virtual bool isFinish();
  virtual void reset();

  virtual std::string getName() { return "AutoCmdExample"; }

private:
  frc::Timer mGenericTimer;

  SubDriveTrain *mSubDriveTrain = nullptr;
  SubLimelight *mSubLimelight = nullptr;
  
  frc2::PIDController mYController{0.3f, 0.1f, 0.2f};
  frc2::PIDController mXController{0.5f, 0.05f, 0.2f};
  frc2::PIDController mYawController{0.05f, 0.01f, 0.0f};

  bool mCorrectPipeline_QuestionMark = 0;
};
