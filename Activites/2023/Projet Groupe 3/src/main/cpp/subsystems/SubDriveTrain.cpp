// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubDriveTrain.h"

SubDriveTrain::SubDriveTrain() = default;

// This method will be called once per scheduler run
void SubDriveTrain::Periodic() {
} 
void SubDriveTrain::ArcadeDrive(double iSpeed, double iRotation)
{

    mDrive.ArcadeDrive(iSpeed, iRotation);
       
}
void SubDriveTrain::SetInverted()
{
  victorLeft1.SetInverted(true);
  victorLeft2.SetInverted(true);
  //victorRight1.SetInverted(true);
  //victorRight2.SetInverted(true);
}
