// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <frc/drive/MecanumDrive.h>
#include <ctre/Phoenix.h>
#include "Constants.h"
#include <iostream>
class SubDriveTrain : public frc2::SubsystemBase 
{
 public:
  SubDriveTrain();


  void Periodic() override;

  void mecanumDrive(float x, float y, float z, frc::Rotation2d iRotation2d);

  void setVitesse(float Vitesse);

 private:

  float vitesse;

  ctre::phoenix::motorcontrol::can::WPI_VictorSPX motorL1 = ctre::phoenix::motorcontrol::can::WPI_VictorSPX{DriveTrainConstants::kMotorL1Id}; // 0 is the RIO PWM port this is connected to
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX motorL2 = ctre::phoenix::motorcontrol::can::WPI_VictorSPX{DriveTrainConstants::kMotorL2Id};
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX motorR1 = ctre::phoenix::motorcontrol::can::WPI_VictorSPX{DriveTrainConstants::kMotorR1Id};
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX motorR2 = ctre::phoenix::motorcontrol::can::WPI_VictorSPX{DriveTrainConstants::kMotorR2Id};

  frc::MecanumDrive drive = frc::MecanumDrive{motorL1, motorL2, motorR1, motorR2};

  

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
