// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

#include <frc/Spark.h>
#include <frc/Talon.h>

#include <frc/SpeedController.h>
#include <frc/SpeedControllerGroup.h>

#include <frc/drive/DifferentialDrive.h>
#include <frc/drive/MecanumDrive.h>

#include "Constants.h"

class DriveTrain : public frc2::SubsystemBase {
 public:
  DriveTrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  frc::Spark mMotorL1{kMotorL1Port};
  frc::Talon mMotorL2{kMotorL2Port};
  frc::Talon mMotorR1{kMotorR1Port};
  frc::Talon mMotorR2{kMotorR2Port};  

  frc::MecanumDrive mMecanumDrive{mMotorL1, mMotorL2, mMotorR1, mMotorR2};

  frc::SpeedControllerGroup mLeftSide{mMotorL1, mMotorL2};
	frc::SpeedControllerGroup mRightSide{mMotorR1, mMotorR2};

  frc::DifferentialDrive mTankDrive{mLeftSide, mRightSide};
};
