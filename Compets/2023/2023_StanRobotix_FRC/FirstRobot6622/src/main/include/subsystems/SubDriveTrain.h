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

  void Init();

  void Enable(const bool iIsEnabled);
  
  void Periodic() override;

  void MoveMeca(const double iX, const double iY, const double iTwist, const bool iFieldOriented);

 private:
  bool mIsEnabled = false;
  RobotContainer * mRobotContainer = nullptr;

  frc::Spark * m_frontLeft = nullptr;
  frc::Spark * m_rearLeft  = nullptr;
  frc::Spark * m_frontRight= nullptr;
  frc::Spark * m_rearRight = nullptr;

  frc::MecanumDrive * m_robotDrive = nullptr;
};
