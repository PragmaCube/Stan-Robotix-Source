// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "DylanAzeradSubsystem.h"
#include <cmath>

DylanAzeradSubsystem::DylanAzeradSubsystem(float iSetPoint, float iKproportional, float iKintegral, float iKderivative) {
  m_last_time = std::chrono::steady_clock::now();
  m_distance_so_far = 0;
  m_pid_controller = new rbtx::pidController(float iSetPoint, float iKproportional, float iKintegral, float iKderivative);
}

DylanAzeradSubsystem::~DylanAzeradSubsystem()
{
  delete m_pid_controller;
}

void DylanAzeradSubsystem::_update_distance()
{
  // Mise à jour des variables
  w_current_time = std::chrono::steady_clock::now();
  float wDt = std::chrono::duration_cast<std::chrono::microseconds>(w_current_time - m_last_time).count();
  m_total_time += wDt;
  m_last_time = std::chrono::steady_clock::now();

  // Calculs
  // TODO : trouver comment prendre les valeurs d'accélération
  float w_acceleration_x;
  float w_acceleration_y;
  float w_acceleration = sqrt(pow(w_acceleration_x, 2) + pow(w_acceleration_y, 2));
  m_distance_so_far += w_acceleration * w_dt * (1/2 * w_dt + m_total_time);
}

float DylanAzeradSubsystem::GetOutput()
{
  _update_distance();
  m_pid_controller->getOutput(m_distance_so_far);
}

void DylanAzeradSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void DylanAzeradSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}>
