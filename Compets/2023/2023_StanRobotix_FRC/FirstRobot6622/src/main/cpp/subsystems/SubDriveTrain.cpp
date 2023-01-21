// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

// Référence: https://docs.wpilib.org/en/stable/docs/software/hardware-apis/motors/wpi-drive-classes.html

#include "subsystems/SubDriveTrain.h"
#include <iostream>

SubDriveTrain::SubDriveTrain() 
{
  m_frontLeft.SetInverted(true);         // Le filage est inverse pour ce moteur dans le robot.
  m_rearRight.SetInverted(true);         // Le filage est inverse pour ce moteur dans le robot.
}

// This method will be called once per scheduler run
void SubDriveTrain::Periodic() {}

void SubDriveTrain::MoveMeca(const double iX, const double iY, const double iTwist)   // le prefix i est necessaire, pour specifier que c est une entree.
{
   m_robotDrive.DriveCartesian(-iY, iX, iTwist);
}
