/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/TankDrive_Joystick.h"
#include "Robot.h"
#include <iostream>

TankDrive_Joystick::TankDrive_Joystick() 
{
  Requires(&Robot::m_drivetrain);
}

// Called just before this Command runs the first time
void TankDrive_Joystick::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TankDrive_Joystick::Execute() 
{
  Robot::m_drivetrain.TankDrive(Robot::m_oi.GetLeftJoystick(), 
                                Robot::m_oi.GetRightJoystick());
}

// Make this return true when this Command no longer needs to run execute()
bool TankDrive_Joystick::IsFinished() 
{ 
  return false; 
}

// Called once after isFinished returns true
void TankDrive_Joystick::End() 
{
  Robot::m_drivetrain.TankDrive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDrive_Joystick::Interrupted() 
{
  Robot::m_drivetrain.TankDrive(0,0);
}
