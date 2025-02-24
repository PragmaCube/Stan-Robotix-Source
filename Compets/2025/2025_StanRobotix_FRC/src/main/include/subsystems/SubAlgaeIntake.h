// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "Constants.h"
#include <rev/SparkMax.h>
#include <iostream>

class SubAlgaeIntake : public frc2::SubsystemBase {
 public:
  SubAlgaeIntake();

  void AlgaeOutake();
  
  void AlgaeIntake();
  
  void AlgaeIntakeStop();
  
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  rev::spark::SparkMax * mAlgaeIntakeMotor = nullptr;
};