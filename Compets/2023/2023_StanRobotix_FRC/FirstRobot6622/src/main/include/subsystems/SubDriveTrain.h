// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "../Constants.h"

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/Spark.h>
#include <frc/drive/MecanumDrive.h>
#include <units/angle.h>
#include "PerformanceMonitor.h"

// Référence: https://docs.wpilib.org/en/stable/docs/software/hardware-apis/motors/wpi-drive-classes.html
class SubIMU;

class SubDriveTrain : public PerformanceMonitor
{
 public:
  SubDriveTrain(RobotContainer * iRobotContainer);

  void Init();

  void setParameters(const double iX, const double iY, const double iTwist, const bool iFieldOriented); // TODO: casser la fonction en deux

 private:
 
  frc::Spark * m_frontLeft = nullptr;
  frc::Spark * m_rearLeft  = nullptr;
  frc::Spark * m_frontRight= nullptr;
  frc::Spark * m_rearRight = nullptr;

  frc::MecanumDrive * m_robotDrive    = nullptr;
  SubIMU            * mSubIMU         = nullptr;

  double mX, mY, mTwist;
  bool mFieldOriented;

  virtual std::string getName() { return "SubDriveTrain"; }
  virtual void doExecute();
};

