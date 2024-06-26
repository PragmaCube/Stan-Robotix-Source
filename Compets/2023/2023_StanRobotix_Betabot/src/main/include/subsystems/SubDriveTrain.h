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

  void mecanumDrive(float iX, float iY, float iZ, frc::Rotation2d iRotation2d);

  void setVitesse(int iVitesse);

  int getVitesse();


 private:
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX motorL1{1}; // 0 is the RIO PWM port this is connected to
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX motorL2{3};
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX motorR1{2};
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX motorR2{4};


  int mVitesse = 2;

  ctre::phoenix::motorcontrol::can::WPI_VictorSPX* mMotorL1; // 0 is the RIO PWM port this is connected to
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX* mMotorL2;
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX* mMotorR1;
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX* mMotorR2;

  frc::MecanumDrive* mDrive;



  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};

