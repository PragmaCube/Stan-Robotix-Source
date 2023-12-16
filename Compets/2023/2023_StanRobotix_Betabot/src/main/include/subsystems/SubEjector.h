// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMaxRelativeEncoder.h>
#include "rev/CANSparkMax.h"
#include "Constants.h"

class SubEjector : public frc2::SubsystemBase {
 public:
  SubEjector();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  frc2::CommandPtr SubEjectorMethodCommand();
  enum eSpeeds
  {
    eForwards,
    eBackwards,
    eStop
  };

  void Set(eSpeeds iSpeed, double Coefficient);

  float GetMoveState();
  void SetMoveState(bool MoveStateToSet);
  
  int GetRoll();
  void SetRoll(int roll);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  rev::CANSparkMax mMotorElevator{EjectorConstants::kCanIdElevator, rev::CANSparkMax::MotorType::kBrushless};
  rev::SparkMaxRelativeEncoder mMotorEncoder = mMotorElevator.GetEncoder();
    bool MoveState = true;
    int Roll = 0;
};
