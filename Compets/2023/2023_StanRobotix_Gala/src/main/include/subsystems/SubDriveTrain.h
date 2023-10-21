// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "Constants.h"

#include <frc/motorcontrol/VictorSP.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/drive/MecanumDrive.h>


#include "SubGyro.h"
// R�f�rence: https://docs.wpilib.org/en/stable/docs/software/hardware-apis/motors/wpi-drive-classes.html

class SubDriveTrain : public frc2::SubsystemBase
{
  
 public:
  SubDriveTrain();

  void setParameters(const double iX, const double iY, const double iTwist, const bool iFieldOriented); // TODO: casser la fonction en deux
  void doExecute();
  void SetSpeed();
  SubGyro mGyro;

  void Periodic() override;

 private:
 
  
  frc::VictorSP * m_frontLeft = nullptr;
  frc::VictorSP * m_rearLeft = nullptr;
  frc::VictorSP * m_frontRight = nullptr;
  frc::VictorSP * m_rearRight = nullptr;

  frc::MecanumDrive * m_robotDrive = nullptr;

  double mX, mY, mTwist;
  bool mFieldOriented;

  
};
