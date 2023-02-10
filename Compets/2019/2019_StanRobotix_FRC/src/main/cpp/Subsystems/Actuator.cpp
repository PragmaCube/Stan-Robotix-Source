/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/Actuator.h"
#include <math.h>
#include <iostream>
#include <RobotMap.h>
#include <Commands/Actuate.h>

Actuator::Actuator() : Subsystem("Actuator"), mActuator(nullptr) 
{
  mActuator = new Servo{kActuator};
  mActuator->Set(0.5);
  
}

void Actuator::InitDefaultCommand() 
{
  SetDefaultCommand(new Actuate());
}

void Actuator::MoveDelta(double iDistance)
{
  
  
  if(mActuator != nullptr)
  {
    
    // assure que la valeur soit comprise entre le minimum et le maximum
    if (iDistance != 0)
    {
      double wDistance = std::max(std::min(mActuator->Get() + iDistance * 0.002, 0.8), 0.2);
      mActuator->Set(wDistance);
    }
  }
}
