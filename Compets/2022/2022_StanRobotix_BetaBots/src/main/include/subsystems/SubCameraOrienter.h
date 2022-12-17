// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Servo.h>

#include "Constants.h"

class SubCameraOrienter : public frc2::SubsystemBase {
 public:
  SubCameraOrienter();

  void Periodic() override;

  void setAngle(double iAngle);
    
 private:
  
  frc::Servo mServo{kCameraOrienteerPort};
};
