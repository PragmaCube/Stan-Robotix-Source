// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Ultrasonic.h>
#include"Constants.h"

class ultrason : public frc2::SubsystemBase {
 public:
  ultrason();
  float getDistance();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
    frc::Ultrasonic mUltrasonic{kUltrasonicDIO_1, kUltrasonicDIO_2};
    units::meter_t distance;
};
