// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/PIDSubsystem.h>
#include <frc/BuiltInAccelerometer.h>

#include <frc/Talon.h>
#include <frc/SpeedController.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>

#include "Constants.h"
#include <chrono>
#include <algorithm>
#include <iostream>

#include "subsystems/DriveTrain.h"

class MotorPIDSubsystem : public frc2::SubsystemBase {
 public:
  MotorPIDSubsystem(double kP, double kI, double kD);
  ~MotorPIDSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;

  void SetPoint(double iSetPoint);
  void StartTimer();

  double UseOutput();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  // Utilisation PID
  frc2::PIDController* mPid;
  double mSetPoint;

  // Accéléromètre
  frc::BuiltInAccelerometer m_accelerometer {};
  std::chrono::steady_clock::time_point m_last_time;
  double m_distance;
  double m_total_time;
  double _updateDistanceTraveled();
};
