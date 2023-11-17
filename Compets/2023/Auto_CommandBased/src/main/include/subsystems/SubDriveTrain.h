// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "Constants.h"

#include <ctre/Phoenix.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/drive/MecanumDrive.h>


#include "SubGyro.h"
// R�f�rence: https://docs.wpilib.org/en/stable/docs/software/hardware-apis/motors/wpi-drive-classes.html

class SubDriveTrain : public frc2::SubsystemBase
{
  
 public:
  SubDriveTrain();

  void drive(const double iX, const double iY, const double iTwist, const frc::Rotation2d iRotation2d);
  void drive(const double iX, const double iY, const double iTwist);                                                 // Function overloading pour double déclaration
  void SetSpeed();

  void Periodic() override;

 private:
  
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX * m_frontLeft = nullptr;
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX * m_rearLeft = nullptr;
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX * m_frontRight = nullptr;
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX * m_rearRight = nullptr;

  frc::MecanumDrive * m_robotDrive = nullptr;

  
};
