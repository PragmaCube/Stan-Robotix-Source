// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#pragma once
#include <rev/SparkMaxRelativeEncoder.h>
#include <rev/CANSparkMax.h>
#include <rev/ColorSensorV3.h>
#include <frc2/command/SubsystemBase.h>
#include "Constants.h"

class SubEjector : public frc2::SubsystemBase 
{
 public:
  SubEjector();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  void In();
  void OutUp();
  void OutDown();
  void Stop();
  void Init();
  
 private:
 rev::CANSparkMax mMotorEjector{EjectorConstants::kId, rev::CANSparkMax::MotorType::kBrushless};
 enum eState
 {
  eIn,
  eOutUp,
  eOutDown,
  eStop
 };
 eState mState =eStop;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
