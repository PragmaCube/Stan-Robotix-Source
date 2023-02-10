/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/ToggleVentouse.h"
#include "Robot.h"

ToggleVentouse::ToggleVentouse() {
  Requires(&Robot::m_ventouse);
}

// Called just before this Command runs the first time
void ToggleVentouse::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ToggleVentouse::Execute() {
  Robot::m_ventouse.Toggle();
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleVentouse::IsFinished() { return true; }

// Called once after isFinished returns true
void ToggleVentouse::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleVentouse::Interrupted() {}
