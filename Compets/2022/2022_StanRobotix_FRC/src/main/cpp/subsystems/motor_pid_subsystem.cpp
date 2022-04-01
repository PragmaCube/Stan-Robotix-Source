// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/motor_pid_subsystem.h"

MotorPIDSubsystem::MotorPIDSubsystem(double kP, double kI, double kD) {
  // Implementation of subsystem constructor goes here.
  mPid = new frc2::PIDController(kP, kI, kD);
  mPid->SetIntegratorRange(-0.5, 0.5);
  mPid->SetTolerance(5, 10);
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
  mPid->Reset();
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
  float w_dt = std::chrono::duration_cast<std::chrono::milliseconds>(w_current_time - m_last_time).count();
  // Diviser par 10^3 car nous avons compté des millisecondes
  w_dt /= 1000;
  m_total_time += w_dt;
  m_last_time = w_current_time;

  // Calculs
  // TODO : voir comment faire pour reculer
  float w_acceleration_x = m_accelerometer.GetX();
  float w_acceleration_y = m_accelerometer.GetY();
  float w_acceleration = sqrt(pow(w_acceleration_x, 2) + pow(w_acceleration_y, 2));
  m_distance += w_acceleration * w_dt * (1/2 * w_dt + m_total_time);
}

void MotorPIDSubsystem::UseOutput()
{
  _updateDistanceTraveled();
  std::cout << "Distance parcourue : " << m_distance << std::endl;

  // Regarder dans le constructeur pour changer la tolérance
  if (!mPid->AtSetpoint())
  {
    // Les valeurs doivent être entre -1 et 1 pour le moteur
    double w_output = std::clamp(mPid->Calculate(m_distance, mSetPoint), -0.2, 0.2);
    m_drive_train.TankDrive(w_output, w_output, false);
  }
}

