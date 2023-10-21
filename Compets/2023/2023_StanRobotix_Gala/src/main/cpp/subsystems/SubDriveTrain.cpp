// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Date       Auteur          Description                                               Test
// 21jan2023  Andre W. Micha R.  mecanum operationel en robot-oriented-drive sans IMU      Deplacement omni-directionnel
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// R�f�rence: https://docs.wpilib.org/en/stable/docs/software/hardware-apis/motors/wpi-drive-classes.html


#include "subsystems/SubDriveTrain.h"


SubDriveTrain::SubDriveTrain()
{
    m_frontLeft  = new frc::VictorSP (DriveTrainConstants::kMotorFL);
    m_rearLeft   = new frc::VictorSP (DriveTrainConstants::kMotorRL);
    m_frontRight = new frc::VictorSP (DriveTrainConstants::kMotorFR);
    m_rearRight  = new frc::VictorSP (DriveTrainConstants::kMotorRR);    

    m_rearRight->SetInverted(true);        // Le filage est inverse pour ce moteur dans le robot.
    m_frontRight->SetInverted(true);       // Le filage est inverse pour ce moteur dans le robot.

    m_robotDrive = new frc::MecanumDrive(*m_frontLeft, *m_rearLeft, *m_frontRight, *m_rearRight);
}

void SubDriveTrain::setParameters(const double iX, const double iY, const double iTwist, const bool iFieldOriented) // le prefix i est necessaire, pour specifier que c est une entree.
{
  mX = iX;
  mY = iY;
  mTwist = iTwist;
  mFieldOriented = iFieldOriented;
}

void SubDriveTrain::doExecute()
{
  if (mFieldOriented)
  {
    m_robotDrive->DriveCartesian(-mY, mX, mTwist, mGyro.getRotation2D());
  }
  else
  {
    m_robotDrive->DriveCartesian(-mY, mX, mTwist);
  }
}


void SubDriveTrain::SetSpeed() { }
