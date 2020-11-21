/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/KeepAdvance.h"
#include <Robot.h>

KeepAdvance::KeepAdvance() {
  Requires(&Robot::m_driveTrain);
  SetTimeout(3.5);
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void KeepAdvance::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void KeepAdvance::Execute() {
  Robot::m_driveTrain.Drive(0,0.25,0);
}

// Make this return true when this Command no longer needs to run execute()
bool KeepAdvance::IsFinished() { return IsTimedOut(); }

// Called once after isFinished returns true
void KeepAdvance::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void KeepAdvance::Interrupted() {}
