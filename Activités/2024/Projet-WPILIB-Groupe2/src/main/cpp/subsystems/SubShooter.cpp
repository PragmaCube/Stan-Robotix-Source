// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubShooter.h"
#include <rev/CANSparkMax.h>


SubShooter::SubShooter() {
     mMotorShooter = new rev::CANSparkMax (ShooterConstants::motorShooter, rev::CANSparkMax::MotorType::kBrushless);
}



  void SubShooter::invertRotation() {
    isRotated = !isRotated;
  }

  void SubShooter::Shoot(){

  }

  void SubShooter::stop(){
        
  }

// This method will be called once per scheduler run
void SubShooter::Periodic() {}

