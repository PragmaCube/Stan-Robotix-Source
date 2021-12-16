// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>
#include <frc/AnalogPotentiometer.h>

#include "Constants.h"

class SubSolenoid : public frc2::SubsystemBase {
 public:
  SubSolenoid();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void SwitchCompressorState();
  void SwitchPistonState();
  void SetInactive();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  frc::DoubleSolenoid mPiston{kSolenoid1Port, kSolenoid2Port};
  frc::Compressor mCompressor;
  bool mState = false;

  double mPressure;
  bool mCompressorState = true;
};
