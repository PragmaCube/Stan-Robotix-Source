// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "../Constants.h"

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/Spark.h>
#include <frc/drive/MecanumDrive.h>
#include <frc/motorcontrol/MotorControllerGroup.h>


class SubDriveTrain : public frc2::SubsystemBase {
 public:
  SubDriveTrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  enum MotorSpeed { eSlow = 0, eMedium = 1, eFast = 2 };

  void MoveDrive(double iLeft, double iRight, MotorSpeed iMotorSpeed);

  void MoveMeca(double x, double y, double twist);

 private:

  frc::Spark m_frontLeft{kMotorL1Port};
  frc::Spark m_rearLeft{kMotorL2Port};
  frc::Spark m_frontRight{kMotorR1Port};
  frc::Spark m_rearRight{kMotorR2Port};
  frc::MecanumDrive m_robotDrive{m_frontLeft, m_rearLeft, m_frontRight,
                                 m_rearRight};
  
};
