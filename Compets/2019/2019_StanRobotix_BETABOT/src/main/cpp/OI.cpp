/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include <commands/Autonome.h>
#include <commands/Advance.h>
#include <commands/ToggleTurn.h>
#include <commands/PistonPulse.h>
#include <Robot.h>
#include <algorithm>

#include <frc/WPILib.h>

OI::OI() {
   mJoystickPtr = new frc::Joystick(kJoystick);
   m1ButtonPtr = new frc::JoystickButton(mJoystickPtr, kJoystickButton1);
   // m1ButtonPtr->WhenPressed(new Autonome());
   m1ButtonPtr->WhenPressed(new PistonPulse());
   canTurn = true;

   m2ButtonPtr = new frc::JoystickButton(mJoystickPtr, kJoystickButton2);
   m2ButtonPtr->WhenPressed(new ToggleTurn());
  // Process operator interface input here.
}

double OI::GetXJoystick() 
{// if (Robot::m_senseurs.GetDist2()<2)
if (false)
  {
    if (Robot::wallLeft)
    {
      return std::max(double(mJoystickPtr->GetRawAxis(kJoystickX) * GetSlider()),0.0);
    }
    else
    {
      return std::min(double(mJoystickPtr->GetRawAxis(kJoystickX) * GetSlider()),0.0);
    }
  }
  else
  {
    return mJoystickPtr->GetRawAxis(kJoystickX) * GetSlider();
  }
}

double OI::GetYJoystick() 
{
  // a voir la sensibilite
  
  if (false)
  // if (Robot::m_senseurs.GetDist()<2)
  {
    return std::min(double(-mJoystickPtr->GetRawAxis(kJoystickY) * GetSlider()),0.0);
  }
  else
  {
    return -mJoystickPtr->GetRawAxis(kJoystickY) * GetSlider();
  }
}

double OI::GetZJoystick()
{
  if (!canTurn)
  {
    return 0;
  }
  else
  {
    return mJoystickPtr->GetRawAxis(kJoystickZ) * GetSlider();
  }
}

double OI::GetSlider()
{
  return (1-mJoystickPtr->GetRawAxis(kJoystickSlider))/2;
}

void OI::OIToggleTurn()
{
  canTurn = !canTurn;
}