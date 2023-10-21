// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Compressor.h>
#include <frc/PneumaticsBase.h>
#include <frc/DoubleSolenoid.h>

#include "Constants.h"


class SubPneumatic : public frc2::SubsystemBase
{
private:
  frc::DoubleSolenoid mDoubleSolenoid{frc::PneumaticsModuleType::CTREPCM, SubPneumaticConstants::kSolenoid1Port, SubPneumaticConstants::kSolenoid2Port};

public:
  SubPneumatic();


  enum eState
  {
    eRetract = 0,
    eExtract = 1
  };
  eState mState = eRetract;

  void Init();

  // Enables the forward doublesolenoid's channel and pushes the pneumatic cylinder forward.
  void Extract();

  // Enables the reverse doublesolenoid's channel and retracts the pneumatic cylinder.
  void Retract();

  // toggle le piston
  void Toggle();


  void Periodic() override;
};
