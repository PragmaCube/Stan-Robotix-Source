// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Spark.h>
#include <frc/DigitalInput.h>

class Pulley : public frc2::SubsystemBase {
 public:
  Pulley();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  void Up();
  void Down();

 private:
  frc::Spark mMotor{5};
  frc::DigitalInput mTopSwitch{0};
  frc::DigitalInput mBottomSwitch{1};
  
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};