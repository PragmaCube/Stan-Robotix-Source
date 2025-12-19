// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include "Constants.h"
#include <frc/drive/MecanumDrive.h>

class SubDrivetrain : public frc2::SubsystemBase {
 public:
  SubDrivetrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Drive(double	xSpeed, double ySpeed, double	zRotation, frc::Rotation2d gyroAngle);

  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX mMotorL1Controller{DrivetrainConstants::kMotorL1Id};
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX mMotorL2Controller{DrivetrainConstants::kMotorL2Id};
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX mMotorR1Controller{DrivetrainConstants::kMotorR1Id};
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX mMotorR2Controller{DrivetrainConstants::kMotorR2Id};

  frc::MecanumDrive mRobotDrive{mMotorL1Controller, mMotorL2Controller,mMotorR1Controller ,mMotorR2Controller};
};
