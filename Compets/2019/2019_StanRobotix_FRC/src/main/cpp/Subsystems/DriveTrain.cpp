/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems\DriveTrain.h"
#include <math.h>

DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain"), mDefaultDrivePtr(nullptr) 
{
  mDefaultDrivePtr = new TankDrive_Joystick();
}

void DriveTrain::InitDefaultCommand() 
{
  SetDefaultCommand(mDefaultDrivePtr);
}

void DriveTrain::TankDrive(double iLeft, double iRight) 
{
  Drive.TankDrive(iLeft, iRight, false);
}
