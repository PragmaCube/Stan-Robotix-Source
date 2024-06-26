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
  //std::cout << "elapsed time is " << w_dt << std::endl;
  m_total_time += w_dt;
  m_last_time = w_current_time;

  // Calculs
  // TODO : voir comment faire pour reculer, accélération sera toujours positive
  // FIX ? : Peut-être utiliser l'opposé du output pour aller à reculons. 
  // Les composantes a extraire dependent de l'orientation du RoboRIO
  // l'accéléromètre renvoie l'accélération en G, et 1G = 9.80665 ms^-2
  float w_acceleration_x = m_accelerometer.GetX() / 9.80665;
  float w_acceleration_y = m_accelerometer.GetZ() / 9.80665;
  float w_acceleration = sqrt(pow(w_acceleration_x, 2) + pow(w_acceleration_y, 2));
  std::cout << "Acceleration is " << w_acceleration << "\n";

  m_distance += w_acceleration * w_dt * (1/2 * w_dt + m_total_time);

  /*
  Pour le côté maths, soit a l'accélération, v la vitesse, x la distance et t le temps
  x(t) = (at^2)/2 + v(0)t + x(0) <=> x(t+dt) = a(t^2+2tdt+dt^2)/2 + v(0)(t+dt) + x(0)
                                 <=> x(t+dt) = a(t^2)/2 + a(2tdt+dt^2)/2 + v(0)t + v(0)dt + x(0)
                                 <=> x(t+dt) = x(t) + a(2tdt+dt^2)/2 + v(0)dt
  En supposant que v(0) = 0:
  => x(t+dt) = a(2tdt + dt^2)/2
             = atdt + (adt^2)/2
             = adt (t+dt/2)
  C'est une intégration numérique de la position  
  */
}

double MotorPIDSubsystem::GetOutput()
{
  _updateDistanceTraveled();
  double w_output = std::clamp(mPid->Calculate(m_distance, mSetPoint), 0.0, 0.2);
  std::cout << "Output is " << w_output << "\n";
  std::cout << "Total distance traveled is " << m_distance << "\n\n";
  return w_output;
}

bool MotorPIDSubsystem::atSetpoint()
{
  return mPid->atSetpoint();
}