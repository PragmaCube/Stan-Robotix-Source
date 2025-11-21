// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/MotorControllerGroup.h>

class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void Drive (double LeftSpeed,double RightSpeed);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  ctre::phoenix::motorcontrol::can::WPI_TalonSRX FrontLeftMotor{1};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX BackLeftMotor{2};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX FrontRightMotor{3};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX BackRightMotor{4};

  frc::MotorControllerGroup Leftgroup{FrontLeftMotor, BackLeftMotor};
  frc::MotorControllerGroup Rightgroup{FrontRightMotor, BackLeftMotor};
  
  frc::DifferentialDrive DriveTrain{Leftgroup, Rightgroup};
};