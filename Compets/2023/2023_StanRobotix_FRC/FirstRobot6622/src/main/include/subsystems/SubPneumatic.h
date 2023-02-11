// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <vector>
#include <frc2/command/SubsystemBase.h>
#include <frc/Compressor.h>
#include <frc/PneumaticsBase.h>

class SubPneumatic : public frc2::SubsystemBase
{
private:
   frc::DoubleSolenoid * mDoubleSolenoid; 
   frc::Compressor * pcmCompressor;

public:
  SubPneumatic();

  ~SubPneumatic();

  //Enables the forward doublesolenoid's channel and pushes the pneumatic cylinder forward.
  void Extract();

  //Enables the reverse doublesolenoid's channel and retracts the pneumatic cylinder.
  void Retract();

  //Disables the solenoid.
  void Stop();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  void Enable();
  
};
