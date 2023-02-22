// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "../Constants.h"

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/Spark.h>
#include <frc/drive/MecanumDrive.h>
#include <units/angle.h>

// Référence: https://docs.wpilib.org/en/stable/docs/software/hardware-apis/motors/wpi-drive-classes.html
class RobotContainer;

class SubDriveTrain : public frc2::SubsystemBase {
 public:
  SubDriveTrain(RobotContainer * iRobotContainer);

  void Init() { }

  void Enable(const bool iIsEnabled);
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void MoveMeca(const double iX, const double iY, const double iTwist, const bool iFieldOriented);

 private:
  bool mIsEnabled = false;
  RobotContainer * mRobotContainer = nullptr;

  frc::Spark m_frontLeft{kMotorL1Port};
  frc::Spark m_rearLeft{kMotorL2Port};
  frc::Spark m_frontRight{kMotorR1Port};
  frc::Spark m_rearRight{kMotorR2Port};

  frc::MecanumDrive m_robotDrive{m_frontLeft, m_rearLeft, m_frontRight, m_rearRight};
};
