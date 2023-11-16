// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/Talon.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>

#include "Constants.h"

class SubDriveTrain : public frc2::SubsystemBase {
 public:
  SubDriveTrain();


  void TankDrive(double left, double right);
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
 
  frc::Talon RearRight{OperatorConstants::kMotorRearRight};
  frc::Talon RearLeft{OperatorConstants::kMotorRearLeft};
  frc::Talon FrontRight{OperatorConstants::kMotorFrontRight};
  frc::Talon FrontLeft{OperatorConstants::kMotorFrontLeft};

  frc::MotorControllerGroup m_rightMotor{RearRight, FrontRight};
  frc::MotorControllerGroup m_leftMotor{RearLeft, FrontLeft};

  frc::DifferentialDrive m_drive{m_leftMotor, m_rightMotor};

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
