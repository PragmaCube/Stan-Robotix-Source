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

  void Init();

  void Extract();
  void Retract();
  void Stop();

  virtual void doExecute();
  virtual std::string getName() { return "SubGamePieceHandler"; }

 private:
  enum eStatus            {eRetract , eExtract , eStop};  // Enum pour le statut actuel du GamePieceHandler
  eStatus mState = eStop;
  bool mIsUpdated = false;

  rev::CANSparkMax * mMotorRight = nullptr;
  rev::CANSparkMax * mMotorLeft = nullptr;

  const double kNoPower = 0.0;
  const double kFullPower = 0.5;

  double mRequestedPowerLeft = 0.0;
  double mRequestedPowerRight = 0.0;
};
