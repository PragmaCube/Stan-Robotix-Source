// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

// Référence: https://docs.wpilib.org/en/stable/docs/software/hardware-apis/motors/wpi-drive-classes.html

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Date       Auteur     Description                                               Test
// 21jan2023  Andre W.   mecanum operationel en robot-oriented-drive sans IMU      Deplacement omni-directionnel
//////////////////////////////////////////////////////////////////////////////////////////////////////////
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

void SubDriveTrain::MoveMeca(const double iX, const double iY, const double iTwist, const bool iFieldOriented)   // le prefix i est necessaire, pour specifier que c est une entree.
{
  frc::Rotation2d imuAngle = mImu->getRadian();
  if (iFieldOriented)
  {
    m_robotDrive.DriveCartesian(-iY, iX, iTwist, imuAngle);
  }
  else
  {
    m_robotDrive.DriveCartesian(-iY, iX, iTwist);
  }
}

void SubDriveTrain::SetImuPointer(SubIMU* iImu)
{
  mImu = iImu;
}