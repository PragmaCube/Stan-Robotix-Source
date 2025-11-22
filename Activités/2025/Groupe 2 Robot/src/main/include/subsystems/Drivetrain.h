// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <frc/drive/DifferentialDrive.h>
#include "Constants.h"
#include <frc/motorcontrol/MotorControllerGroup.h>


class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  void TankDrive(double leftSpeed, double rightSpeed);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  ctre::phoenix::motorcontrol::can::WPI_TalonSRX* moteur1L;
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX* moteur2L;
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX* moteur1R;
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX* moteur2R;

  frc::DifferentialDrive* Drive;


	frc::MotorControllerGroup* GroupL;
 
  frc::MotorControllerGroup* GroupR;

   

};
