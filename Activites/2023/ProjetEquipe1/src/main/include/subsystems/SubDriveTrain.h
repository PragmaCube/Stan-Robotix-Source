// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once


#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/VictorSP.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <ctre/Phoenix.h>
#include "Constants.h"
#include "frc/motorcontrol/PWMMotorController.h"
class SubDriveTrain : public frc2::SubsystemBase {
 public:
  SubDriveTrain();


  void TankDrive(double left, double right);
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
 
  
 ctre::phoenix::motorcontrol::can::WPI_VictorSPX victorLeft1{1};
 ctre::phoenix::motorcontrol::can::WPI_VictorSPX victorLeft2{3};
 ctre::phoenix::motorcontrol::can::WPI_VictorSPX victorRight1{2};
 ctre::phoenix::motorcontrol::can::WPI_VictorSPX victorRight2{4};

  frc::MotorControllerGroup m_rightMotor{victorRight1, victorRight2};
  frc::MotorControllerGroup m_leftMotor{victorLeft1, victorLeft2};

  frc::DifferentialDrive m_drive{m_leftMotor, m_rightMotor};

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
