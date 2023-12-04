// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <frc/drive/MecanumDrive.h>
#include <ctre/Phoenix.h>
#include "Constants.h"

class SubDriveTrain : public frc2::SubsystemBase 
{
 public:
  SubDriveTrain();  

  void Periodic() override;

  void mecanumDrive(float x, float y, float z, frc::Rotation2d iRotation2d);

  void setVitesse(int Vitesse);

  int getVitesse();

 private:

  int vitesse = 2;

  ctre::phoenix::motorcontrol::can::WPI_VictorSPX* motorL1; // 0 is the RIO PWM port this is connected to
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX* motorL2;
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX* motorR1;
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX* motorR2;

  frc::MecanumDrive* drive;

  

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
