// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

#include <frc/motorcontrol/Spark.h>

#include "Constants.h"

class SubEjector : public frc2::SubsystemBase {
 public:
  SubEjector();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  // iDirection : true --> valeur positive
  // iDirection : false --> valeur négative
  void Rotate(bool iDirection);
  
  void Stop();

 private:
  frc::Spark mMotor{EjectorConstants::kEjectorPort};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
