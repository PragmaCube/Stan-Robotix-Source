// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include <ctre/Phoenix.h>
#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix6/Pigeon2.hpp>
#include <cmath>
#include <units/acceleration.h>
#include <frc/filter/LinearFilter.h>

class SubIMU : public frc2::SubsystemBase 
{
 public:
  SubIMU();
  units::standard_gravity_t getShock();
  units::standard_gravity_t getAccelX();
  units::standard_gravity_t getAccelY();
  units::standard_gravity_t getAccel();
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
  frc::LinearFilter<units::standard_gravity_t> ShockFilter = frc::LinearFilter<units::standard_gravity_t>::HighPass(0.1,0.02_s);
  ctre::phoenix6::hardware::Pigeon2 IMU{0};
};