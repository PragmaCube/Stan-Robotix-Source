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
    m_frontLeft  = new ctre::phoenix::motorcontrol::can::WPI_VictorSPX (DriveTrainConstants::kMotorFL);
    m_rearLeft   = new ctre::phoenix::motorcontrol::can::WPI_VictorSPX (DriveTrainConstants::kMotorRL);
    m_frontRight = new ctre::phoenix::motorcontrol::can::WPI_VictorSPX (DriveTrainConstants::kMotorFR);
    m_rearRight  = new ctre::phoenix::motorcontrol::can::WPI_VictorSPX (DriveTrainConstants::kMotorRR);    

    m_rearRight->SetInverted(true);        // Le filage est inverse pour ce moteur dans le robot.
    m_frontRight->SetInverted(true);       // Le filage est inverse pour ce moteur dans le robot.

    m_robotDrive = new frc::MecanumDrive(*m_frontLeft, *m_rearLeft, *m_frontRight, *m_rearRight);
}

void SubDriveTrain::drive(const double iX, const double iY, const double iTwist, const frc::Rotation2d iRotation2d) // le prefix i est necessaire, pour specifier que c est une entree.
{
  m_robotDrive->DriveCartesian(-iY, iX, iTwist, iRotation2d);
}

void SubDriveTrain::drive(const double iX, const double iY, const double iTwist) // le prefix i est necessaire, pour specifier que c est une entree.
{
  m_robotDrive->DriveCartesian(-iY, iX, iTwist);
}

void SubDriveTrain::SetSpeed() { }

void SubDriveTrain::Periodic() { }