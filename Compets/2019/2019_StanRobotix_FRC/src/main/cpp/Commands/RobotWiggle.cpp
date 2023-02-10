/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/RobotWiggle.h"
#include <Robot.h>

int lastDid;
int direction;

RobotWiggle::RobotWiggle() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&Robot::m_drivetrain);
}

// Called just before this Command runs the first time
void RobotWiggle::Initialize() {
  lastDid = 0;
  direction = 1;
}

// Called repeatedly when this Command is scheduled to run
void RobotWiggle::Execute()
{
  lastDid++;
  Robot::m_drivetrain.TankDrive(0.4*direction, 0.4*direction);
  
  if (lastDid % 14 ==0)
  {
    direction *=-1;
  }
}

// Make this return true when this Command no longer needs to run execute()
bool RobotWiggle::IsFinished() { return lastDid>=28 || Robot::m_oi.GetStart(); }

// Called once after isFinished returns true
void RobotWiggle::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RobotWiggle::Interrupted() {}
