// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <ctre/Phoenix.h>
#include <ctre/phoenix6/Pigeon2.hpp>

#include <frc2/command/SubsystemBase.h>

class SubIMU : public frc2::SubsystemBase 
{
 public:

  SubIMU();

  frc::Rotation2d getRotation2d();

  double getAngleYaw();
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void ResetAngle();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  ctre::phoenix6::hardware::Pigeon2 mIMU{0};
};