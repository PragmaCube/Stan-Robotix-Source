// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include <ctre/Phoenix.h>
#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/sensors/Pigeon2.h>

class SubIMU : public frc2::SubsystemBase 
{
   



 public:
  SubIMU();

double getAccelX();
double getAccelY();

double angle

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;



 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  ctre::phoenix::sensors::WPI_Pigeon2 IMU;
};
