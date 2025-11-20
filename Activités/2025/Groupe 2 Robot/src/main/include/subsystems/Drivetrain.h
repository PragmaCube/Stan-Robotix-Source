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

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  ctre::phoenix::motorcontrol::can::WPI_TalonSRX* moteur1{DriveTrainConstants::moteur1ID};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX* moteur2{DriveTrainConstants::moteur2ID};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX* moteur3{DriveTrainConstants::moteur3ID};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX* moteur4{DriveTrainConstants::moteur4ID};
frc::DifferentialDrive* Drive;
	MotorControllerGroup
  (ctre::phoenix::motorcontrol::can::WPI_TalonSRX &moteur1, 
   ctre::phoenix::motorcontrol::can::WPI_TalonSRX &moteur2, 
  );

};
