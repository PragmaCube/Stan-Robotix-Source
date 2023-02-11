// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubPneumatic.h"
#include "Constants.h"


SubPneumatic::SubPneumatic()
{
  //mDoubleSolenoid = new frc::DoubleSolenoid(frc::PneumaticsModuleType::CTREPCM, 1, 2);
  pcmCompressor = new frc::Compressor{0, frc::PneumaticsModuleType::CTREPCM};
  Enable();
}

SubPneumatic::~SubPneumatic(){}



void SubPneumatic::Enable()
{
  pcmCompressor->EnableDigital();
}

void SubPneumatic::Periodic() 
{
    
}

void SubPneumatic::Extract() 
{
  //  mDoubleSolenoid->Set(frc::DoubleSolenoid::Value::kForward);
}

void SubPneumatic::Retract()
{
 // mDoubleSolenoid->Set(frc::DoubleSolenoid::Value::kReverse);
}