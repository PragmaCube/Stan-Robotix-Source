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

class RobotContainer;

class SubPneumatic : public frc2::SubsystemBase
{
private:
  frc::DoubleSolenoid mDoubleSolenoid{frc::PneumaticsModuleType::CTREPCM, kSolenoid1Port, kSolenoid2Port};
  // frc::Compressor pcmCompressor{0, frc::PneumaticsModuleType::CTREPCM};
  
  bool mIsEnabled = false;
  RobotContainer * mRobotContainer;

public:
  SubPneumatic(RobotContainer * iRobotContainer);

  ~SubPneumatic();

  void Init() { }

  void Enable(const bool iEnable);

  //Enables the forward doublesolenoid's channel and pushes the pneumatic cylinder forward.
  void Extract();

  //Enables the reverse doublesolenoid's channel and retracts the pneumatic cylinder.
  void Retract();

  //toggle le piston
  void Toggle();
  
};
