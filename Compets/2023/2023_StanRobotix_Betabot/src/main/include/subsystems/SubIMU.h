// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once



#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>

class SubIMU : public frc2::SubsystemBase {
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


  ctre::phoenix::sensors::WPI_Pigeon2* mGyro = nullptr;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};


