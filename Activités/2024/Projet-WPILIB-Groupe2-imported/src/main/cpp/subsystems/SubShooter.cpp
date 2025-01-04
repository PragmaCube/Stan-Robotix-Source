// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubShooter.h"



SubShooter::SubShooter() {
     mMotorShooter = new rev::spark::SparkMax(ShooterConstants::motorShooter, rev::spark::SparkLowLevel::MotorType::kBrushless);
}



  void SubShooter::invertRotation() {
    isRotated = !isRotated;
  }

  void SubShooter::Shoot(){
    mMotorShooter->Set(ShooterConstants::kShooterSpeed);
  }

  void SubShooter::stop(){
    mMotorShooter->StopMotor();
  }

  void SubShooter::startAndStop(){
    mMotorShooter->Set(ShooterConstants::kShooterSpeed);
    mMotorShooter->StopMotor();
  }

// This method will be called once per scheduler run
void SubShooter::Periodic() {}

