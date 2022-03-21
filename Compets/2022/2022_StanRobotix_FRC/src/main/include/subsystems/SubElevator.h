// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#pragma once
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include "Constants.h"

class SubElevator : public frc2::SubsystemBase {
 public:
  SubElevator();
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   * 
   */
  void Periodic() override;
 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  void Up();
  void Down();
  void Stop();
  rev::CANSparkMax mMotorElevatorR{kCanIdElevatorR, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax mMotorElevatorL{kCanIdElevatorL, rev::CANSparkMax::MotorType::kBrushless};
};