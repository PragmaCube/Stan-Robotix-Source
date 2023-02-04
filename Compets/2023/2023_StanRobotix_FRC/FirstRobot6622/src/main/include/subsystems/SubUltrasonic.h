// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/AnalogInput.h>
#include <frc/RobotController.h>

#include "Constants.h"
#include "PerformanceMonitor.h"

class SubUltrasonic : public frc2::SubsystemBase, public PerformanceMonitor
{
public:
  SubUltrasonic();

  float getDistance();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void EnableImperialSystem() { mMetricSystem = false; }
  void EnableMetricSystem() { mMetricSystem = true; }

private:
  frc::AnalogInput mUltrasonic{kUltrasonicDIO};

  virtual void doExecute();

  virtual std::string getName() { return "SubUltrasonic"; }

  bool mMetricSystem = true;
};
