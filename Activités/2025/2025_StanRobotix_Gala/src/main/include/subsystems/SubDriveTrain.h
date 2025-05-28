// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <frc/drive/MecanumDrive.h>
#include "Constants.h"

class SubDriveTrain : public frc2::SubsystemBase {
 public:
  SubDriveTrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void drive(const double iX, const double iY, const double iZ, const frc::Rotation2d iRotate);


 private:
  
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX * mMotor4 = nullptr;
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX * mMotor2 = nullptr;
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX * mMotor3 = nullptr;
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX * mMotor1 = nullptr;
  
  frc::MecanumDrive * mDrive = nullptr;
  
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.


};