// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "frc2/command/SubsystemBase.h"
#include "frc/motorcontrol/PWMMotorController.h"
#include <frc/motorcontrol/VictorSP.h>
#include "constants.h"
#include "frc/motorcontrol/MotorControllerGroup.inc"
#include <frc/drive/DifferentialDrive.h>
#include <ctre/Phoenix.h>

class SubDriveTrain : public frc2::SubsystemBase 
{


 public:

  SubDriveTrain();
  void Periodic() override;
  void ArcadeDrive(double iSpeed, double iRotation);
  void SetInverted();
  
 private:
  
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX victorLeft1{1};
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX victorLeft2{3};
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX victorRight1{2};
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX victorRight2{4};

  frc::MotorControllerGroup mLeftSide{victorLeft1, victorLeft2};
	frc::MotorControllerGroup mRightSide{victorRight1, victorRight2};

  frc::DifferentialDrive mDrive{mLeftSide, mRightSide};
};


