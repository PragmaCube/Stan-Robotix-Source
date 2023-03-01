// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "rev/CANSparkMax.h"
#include "PerformanceMonitor.h"

class SubGamePieceHandler : public PerformanceMonitor {
 public:
  SubGamePieceHandler();

  void EnableSubsystemLog(bool iEnable) { mSubsystemLogEnabled = iEnable; }
  void Enable(bool iEnable) { mIsEnable = iEnable; }

  void Init();

  void Extract();
  void Retract();
  void Stop();

  virtual void doExecute();
  virtual std::string getName() { return "SubGamePieceHandler"; }

 private:
  rev::CANSparkMax m_motor1{0, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_motor2{1, rev::CANSparkMax::MotorType::kBrushless};

  bool mSubsystemLogEnabled = false;
  bool mIsEnable = true;
};
