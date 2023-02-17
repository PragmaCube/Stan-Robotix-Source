// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <vector>
#include <frc2/command/SubsystemBase.h>
#include <frc/Compressor.h>
#include <frc/PneumaticsBase.h>
#include <frc/DoubleSolenoid.h>
#include "Constants.h"

class SubPneumatic : public frc2::SubsystemBase
{
private:
  frc::DoubleSolenoid mDoubleSolenoid{frc::PneumaticsModuleType::CTREPCM, kSolenoid1Port, kSolenoid2Port};
  // frc::Compressor pcmCompressor{0, frc::PneumaticsModuleType::CTREPCM};
  static SubPneumatic *mSingleton;
public:
  SubPneumatic();

  ~SubPneumatic();

  static SubPneumatic * getInstance();

  //Enables the forward doublesolenoid's channel and pushes the pneumatic cylinder forward.
  void Extract();

  //Enables the reverse doublesolenoid's channel and retracts the pneumatic cylinder.
  void Retract();

  //Disables the solenoid.
  void Stop();

  //toggle le piston
  void Toggle();
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  void Enable();
  
};
