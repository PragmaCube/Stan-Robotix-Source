// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include "Constants.h"

class subLift : public frc2::SubsystemBase {
 public:
  subLift();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void LiftUp();

  void LiftDown();

  void StopLift();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  frc::PWMSparkMax * mSparkMaxG = nullptr;
  frc::PWMSparkMax * mSparkMaxD = nullptr;

};
