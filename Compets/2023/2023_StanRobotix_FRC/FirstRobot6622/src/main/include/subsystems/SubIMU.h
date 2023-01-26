// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <vector>
#include <frc2/command/SubsystemBase.h>

#include <frc/ADIS16448_IMU.h>

class SubIMU : public frc2::SubsystemBase
{
private:
   frc::ADIS16448_IMU m_Imu{};

   	static constexpr double kAngleSetpoint = 0.0;
    static constexpr double kP = 0.005;
    std::vector<double> m_gyroVals; 

public:
  SubIMU();
  ~SubIMU();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  void Start();
  float getAngle();
  units::radian_t getRadian();
};
