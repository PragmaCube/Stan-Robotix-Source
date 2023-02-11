// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Date       Auteur     Description                                               Test
// 21jan2023  Andre W.   mecanum operationel en robot-oriented-drive sans IMU      Deplacement omni-directionnel
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Référence: https://docs.wpilib.org/en/stable/docs/software/hardware-apis/motors/wpi-drive-classes.html

#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubIMU.h"

#include <iostream>


SubDriveTrain::SubDriveTrain() 
{
  m_frontLeft.SetInverted(true);         // Le filage est inverse pour ce moteur dans le robot.
  m_rearRight.SetInverted(true);         // Le filage est inverse pour ce moteur dans le robot.
  m_frontRight.SetInverted(true);        // Le filage est inverse pour ce moteur dans le robot.
}

// This method will be called once per scheduler run
void SubDriveTrain::Periodic() {}

void SubDriveTrain::MoveMeca(const double iX, const double iY, const double iTwist, const bool iFieldOriented)   // le prefix i est necessaire, pour specifier que c est une entree.
{
  static bool wIsFieldOrientedActive = false;
  if (iFieldOriented != wIsFieldOrientedActive)  // TODO: rajouter un filtre
  {
    if (iFieldOriented)
    {
       std::cout << "In Field Oriented now Active " << std::endl;
    }
    else
    {
       std::cout << "In Field Oriented now InActive " << std::endl;
    }

    wIsFieldOrientedActive = iFieldOriented;
  }

  frc::Rotation2d imuAngle = SubIMU::getInstance()->getRotation2d();
  if (iFieldOriented)
  {
    m_robotDrive.DriveCartesian(-iY, iX, iTwist, imuAngle);
  }
  else
  {
    m_robotDrive.DriveCartesian(-iY, iX, iTwist);
  }
}