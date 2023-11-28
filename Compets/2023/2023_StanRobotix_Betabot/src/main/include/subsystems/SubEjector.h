// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMaxRelativeEncoder.h>
#include "rev/CANSparkMax.h"
#include "Constants.h"

class SubEjector : public frc2::SubsystemBase {
 public:
  SubEjector();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  frc2::CommandPtr SubEjectorMethodCommand();
  enum eSpeeds
  {
    eForwards,
    eBackwards,
    eStop
  };
  void Set(const eSpeeds iSpeed);
  void SetEjectorSpeedCoeficient(float EjectorSpeedCoeficient);
  float GetEjectorSpeedCoeficient(float EjectorSpeedCoeficient);
 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  rev::CANSparkMax* mMotorElevator = nullptr;
  float EjectorSpeedCoeficient = 0;
};
