// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubPneumatic.h"
#include "Constants.h"

SubPneumatic::SubPneumatic(RobotContainer * iRobotContainer)
{
  Enable(kPneumaticEnabled);

  mRobotContainer = iRobotContainer;
}

SubPneumatic::~SubPneumatic(){}

void SubPneumatic::Enable(const bool iEnable)
{
   mIsEnabled = iEnable;

   if (mIsEnabled)
   {
      Retract();
   }
}
void SubPneumatic::Init()
{
  if (mIsEnabled)
  {

  }
}
void SubPneumatic::Extract()
{
  mDoubleSolenoid.Set(frc::DoubleSolenoid::Value::kForward);
}

void SubPneumatic::Retract()
{
  mDoubleSolenoid.Set(frc::DoubleSolenoid::Value::kReverse);
}

void SubPneumatic::Toggle()
{
  if (mIsEnabled)
  {
     mDoubleSolenoid.Toggle();
  }  
}

void SubPneumatic::doExecute ()
{
  if (mIsEnabled)
  { 
      // TODO: afficher potentiellement un log 
  }
}