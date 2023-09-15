// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "../subsystems/PerformanceMonitor.h"

class RobotContainer;

class SubColorSensor;
class SubDriveTrain;
class SubElevator;
class SubIMU;
class SubLimelight;
class SubPilotInterface;
class SubPneumatic;
class SubUltrasonic;

class ManualPilot : public PerformanceMonitor
{
private:
  

public:
  /**
   * Creates a new ExampleCommand.
   *
   * @param subsystem The subsystem used by this command.
   */
  ManualPilot(RobotContainer *iRobotContainer);

  void Init();

  virtual void doExecute();

  virtual std::string getName() { return "ManualPilot"; }

private:
  RobotContainer *mRobotContainer;

  SubDriveTrain * mSubDriveTrain  = nullptr;
  SubUltrasonic * mSubUltrasonic  = nullptr;
  SubElevator   * mSubElevator    = nullptr;
  SubIMU        * mSubIMU         = nullptr;
  SubColorSensor* mSubColorSensor = nullptr;
  SubLimelight  * mSubLimelight   = nullptr;
  SubPneumatic  * mSubPneumatic   = nullptr;
  SubPilotInterface * mSubPilotInterface = nullptr;
};
