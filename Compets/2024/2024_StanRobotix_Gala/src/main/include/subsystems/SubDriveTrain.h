// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/Spark.h>

#include "Constants.h"

class SubDriveTrain : public frc2::SubsystemBase {
 public:
  SubDriveTrain();

  void arcadeDrive(double xSpeed, double zRotations);
  void setCoef(int iPosition);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  
  frc::Spark mLeftMotors{DriveTrainConstants::kLeftMotor}; //spark gauche 
  frc::Spark mRightMotors{DriveTrainConstants::kRightMotor}; //spark droite 

  // frc::DifferentialDrive mDrive(std::function< void(double)> mLeftMotors,
  //   std::function< void(double)> mRightMotors);

  // frc::DifferentialDrive mDrive(frc::Spark mLeftMotors, frc::Spark mRightMotors);

  frc::DifferentialDrive mDrive{mLeftMotors, mRightMotors};
};