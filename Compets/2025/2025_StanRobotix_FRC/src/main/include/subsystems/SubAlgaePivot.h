// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <iostream>
#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <rev/RelativeEncoder.h>
#include <frc/controller/PIDController.h>
#include <frc/controller/ArmFeedforward.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <rev/SparkRelativeEncoder.h>
#include <frc/controller/ArmFeedforward.h>

#include "Constants.h"



class SubAlgaePivot : public frc2::SubsystemBase {

 public:

 enum StatesAlgae {
    cage,
    horizontale,
    pickAlgae,
    replié
  };

  SubAlgaePivot();

  void Stop();

  void Pivot(double);
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  bool AtSetPoint();

  void SetSetPoint(double);

  void SetPIDEnable(bool);

  void Climb();

  void StayStill();

  StatesAlgae GetState();

  void SetState(StatesAlgae);

 private:

 

  StatesAlgae mState;

  const double kG = 0.22;
  const double kOffset = 33.6426;
  bool PIDEnable = true;


  rev::spark::SparkMax * mAlgaePivotMotor = nullptr;
  frc::PIDController mPIDController{0.2, 0, 0};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};