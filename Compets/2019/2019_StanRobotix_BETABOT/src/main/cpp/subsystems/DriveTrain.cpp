/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"
#include <commands/MecanumDriveJoystick.h>

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {}

void DriveTrain::Drive(double x, double y, double z)
{
    drive.DriveCartesian(x,y,z);
}

void DriveTrain::InitDefaultCommand() {
  SetDefaultCommand(new MecanumDriveJoystick());
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
