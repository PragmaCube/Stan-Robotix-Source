// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <vector>

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>

#include "PerformanceMonitor.h"

class SubIMU : public frc2::SubsystemBase, public PerformanceMonitor
{
public:
  typedef enum
  {
    eYaw,
    ePitch,
    e_roll
  } DataType;

private:
  float mInitialValue[3] = {0.0, 0.0, 0.0};
  ctre::phoenix::sensors::WPI_Pigeon2 * mGyro = nullptr; 

  float mYawStart;
  float mPitchStart;
  float mRollStart;

  static constexpr double kAngleSetpoint = 0.0;
  static constexpr double kP = 0.005;
  std::vector<double> m_gyroVals;

  virtual void doExecute();

  virtual std::string getName() { return "SubIMU"; }
  
public:
  SubIMU();

  void Init();

  void ResetGlobal();

  double getAngleYaw();
  double getAnglePitch();
  double getAngleRoll();
  units::radian_t getRadian();
  frc::Rotation2d getRotation2d();
};
