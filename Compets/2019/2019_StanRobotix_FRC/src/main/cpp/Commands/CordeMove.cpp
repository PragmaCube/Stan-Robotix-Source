/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/CordeMove.h"
#include <Robot.h>

CordeMove::CordeMove() {
  Requires(&Robot::m_CordeMoteur);
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void CordeMove::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CordeMove::Execute() {
  Robot::m_CordeMoteur.Set(Robot::m_oi.GetLT()+Robot::m_oi.GetRT());
}

// Make this return true when this Command no longer needs to run execute()
bool CordeMove::IsFinished() { return false; }

// Called once after isFinished returns true
void CordeMove::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CordeMove::Interrupted() {}
