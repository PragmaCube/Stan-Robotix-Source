// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/drive/MecanumDrive.h>
#include <ctre/phoenix6/Pigeon2.hpp>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>

#include "Constants.h"

class SubDriveTrain : public frc2::SubsystemBase 
{
 public:
  SubDriveTrain();  

  void setEnableDriveTrain(bool iEnable);

  bool getEnableDriveTrain();

  void Periodic() override;

  void mecanumDrive(float iX, float iY, float iZ, frc::Rotation2d iRotation2d);
  void mecanumDrive(float iX, float iY, float iZ);

  void setVitesse(float iVitesse);

  int getVitesse();

 private:

  bool mEnable = true;

  float mVitesse = 1;

  ctre::phoenix::motorcontrol::can::WPI_VictorSPX* mMotorL1{}; // 0 is the RIO PWM port this is connected to
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX* mMotorL2{};
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX* mMotorR1{};
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX* mMotorR2{};

  frc::MecanumDrive* mDrive;
};