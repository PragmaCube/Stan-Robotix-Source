/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/MecanumDriveJoystick.h"

MecanumDriveJoystick::MecanumDriveJoystick() {
  Requires(&Robot::m_driveTrain);
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void MecanumDriveJoystick::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void MecanumDriveJoystick::Execute() {
  Robot::m_driveTrain.Drive(Robot::m_oi.GetXJoystick(), Robot::m_oi.GetYJoystick(), Robot::m_oi.GetZJoystick());
}

// Make this return true when this Command no longer needs to run execute()
bool MecanumDriveJoystick::IsFinished() { return false; }

// Called once after isFinished returns true
void MecanumDriveJoystick::End() {
  
  Robot::m_driveTrain.Drive(0,0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MecanumDriveJoystick::Interrupted() {
  
  Robot::m_driveTrain.Drive(0,0,0);
}
