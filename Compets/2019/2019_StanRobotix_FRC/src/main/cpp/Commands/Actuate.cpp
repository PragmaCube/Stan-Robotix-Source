/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/Actuate.h"
#include "Robot.h"
#include <iostream>

Actuate::Actuate() 
{
  Requires(&Robot::m_actuator);
}

// Called just before this Command runs the first time
void Actuate::Initialize() 
{
}

// Called repeatedly when this Command is scheduled to run
void Actuate::Execute() 
{ 
  Robot::m_actuator.MoveDelta(Robot::m_oi.GetActuatorInput());
}

// Make this return true when this Command no longer needs to run execute()
bool Actuate::IsFinished() { return false; }

// Called once after isFinished returns true
void Actuate::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Actuate::Interrupted() {}
