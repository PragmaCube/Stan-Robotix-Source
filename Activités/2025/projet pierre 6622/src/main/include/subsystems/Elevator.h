// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <rev/SparkMax.h>

#include <frc2/command/SubsystemBase.h>
 
class Elevator : public frc2::SubsystemBase {
 public:
  Elevator();

void Up();

void Down();

void Stop();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:

rev::spark::SparkMax m_LeftSparkMax{4, rev::spark::SparkLowLevel::MotorType
::kBrushless};

rev::spark::SparkMax m_RightSparkMax{4, rev::spark::SparkLowLevel::MotorType
::kBrushless};



  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
