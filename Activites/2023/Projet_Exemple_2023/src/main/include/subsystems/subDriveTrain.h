// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <frc/drive/MecanumDrive.h>
#include <ctre/Phoenix.h>

class subDriveTrain : public frc2::SubsystemBase 
{
 public:
  subDriveTrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void mecanumDrive(float x, float y, float z);

 private:
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX motorL1{1}; // 0 is the RIO PWM port this is connected to
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX motorL2{3};
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX motorR1{2};
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX motorR2{4};

  frc::MecanumDrive drive{motorL1, motorL2, motorR1, motorR2};
  

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};

