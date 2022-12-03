// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

#include <frc/ADIS16448_IMU.h>

class ImuSubsystem : public frc2::SubsystemBase
{
private:
   frc::ADIS16448_IMU m_Imu{};
   double mTurningValue = 0;

   	static constexpr double kAngleSetpoint = 0.0;
    static constexpr double kP = 0.005;

public:
  ImuSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  void Start();
  float getAngle();
};
