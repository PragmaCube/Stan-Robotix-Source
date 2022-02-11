// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "frc/Spark.h"
#include "Constants.h"

class LaunchSystem : public frc2::SubsystemBase {
 public:
  LaunchSystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  void Run(bool iButton, double iLauncherSpeed);
  void SetSpeedLauncher(int iMotorIndex);

 private:
 frc::Spark mLaunchMotor{kLaunchMotorPort};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
