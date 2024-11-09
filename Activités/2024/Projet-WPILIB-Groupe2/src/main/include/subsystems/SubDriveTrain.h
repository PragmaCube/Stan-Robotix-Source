// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <frc/drive/MecanumDrive.h>
#include "Constants.h"

class SubDriveTrain : public frc2::SubsystemBase {
 public:
  SubDriveTrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  
ctre::phoenix::motorcontrol::can::WPI_VictorSPX motor1{OperatorConstants::motor1port};
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX motor2{OperatorConstants::motor2port};
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX motor3{OperatorConstants::motor3port};
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX motor4{OperatorConstants::motor4port};

  frc::MecanumDrive drive{motor1, motor2, motor3, motor4};
  
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
