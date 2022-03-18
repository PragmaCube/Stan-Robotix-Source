// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "pid.h"

// Subsystem pour avancer d'une certaine longueur.
// Utilise l'accéléromètre
class DylanAzeradSubsystem : public frc2::SubsystemBase {
 public:
  DylanAzeradSubsystem(float iKproportional, float iKintegral, float iKderivative);
  ~DylanAzeradSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;

  void pidSetPoint(float iSetPoint);
  float GetOutput();

 private:
  rbtxpid::pidController* m_pid_controller;
  frc::BuiltInAccelerometer m_accelerometer;
  std::chrono::steady_clock::time_point m_last_time;
  float m_total_time;
  float m_distance_so_far;
  void _update_distance();
};
