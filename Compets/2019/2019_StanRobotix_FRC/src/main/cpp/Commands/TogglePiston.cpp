/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/TogglePiston.h"
#include "Robot.h"

TogglePiston::TogglePiston() {
  Requires(&Robot::m_piston);
}

// Called just before this Command runs the first time
void TogglePiston::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TogglePiston::Execute() {
  Robot::m_piston.Toggle();
}

// Make this return true when this Command no longer needs to run execute()
bool TogglePiston::IsFinished() { return true; }

// Called once after isFinished returns true
void TogglePiston::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TogglePiston::Interrupted() {}
