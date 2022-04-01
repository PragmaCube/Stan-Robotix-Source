// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/motor_pid_subsystem.h"

MotorPIDSubsystem::MotorPIDSubsystem(double kP, double kI, double kD) {
  // Implementation of subsystem constructor goes here.
  mPid = new frc2::PIDController(kP, kI, kD);
}

MotorPIDSubsystem::~MotorPIDSubsystem() {
  delete mPid;
}

void MotorPIDSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void MotorPIDSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}

void MotorPIDSubsystem::SetPoint(double iSetPoint)
{
  mPid->reset();
  mSetPoint = iSetPoint;
  m_distance = 0;
}

void MotorPIDSubsystem::StartTimer()
{
  m_total_time = 0;
  m_last_time = std::chrono::steady_clock::now();
}

double MotorPIDSubsystem::_updateDistanceTraveled()
{
  // Mise à jour des variables
  std::chrono::steady_clock::time_point w_current_time = std::chrono::steady_clock::now();
  float wDt = std::chrono::duration_cast<std::chrono::seconds>(w_current_time - m_last_time).count();
  // Diviser par 10^0 car nous avons compté des microsecondes
  wDt /= 1;
  m_total_time += wDt;
  m_last_time = w_current_time;

  // Calculs
  // TODO : trouver comment prendre les valeurs d'accélération
  float w_acceleration_x = m_accelerometer.getX();
  float w_acceleration_y = m_accelerometer.getY();
  float w_acceleration = sqrt(pow(w_acceleration_x, 2) + pow(w_acceleration_y, 2));
  m_distance += w_acceleration * w_dt * (1/2 * w_dt + m_total_time);
}

void MotorPIDSubsystem::UseOutput()
{
  _updateDistanceTraveled();
  double w_output = mPid->Calculate(m_distance, mSetPoint);
  mDriveTrain.TankDrive(w_output, w_output, false)
}

