// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

#include <frc/SolenoidBase.h>
#include <frc/Solenoid.h>
#include <frc/AnalogPotentiometer.h>


class SubSolenoid : public frc2::SubsystemBase {
 public:
  SubSolenoid();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void SwitchState();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  frc::Solenoid mPiston{0};
  frc::AnalogPotentiometer mPressureTransducer{1, 250, -25};
  double mPressure;
};
