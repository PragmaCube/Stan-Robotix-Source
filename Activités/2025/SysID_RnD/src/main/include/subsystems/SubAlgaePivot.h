// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <iostream>
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/sysid/SysIdRoutine.h>
#include <rev/SparkMax.h>
#include <rev/SparkRelativeEncoder.h>
#include <rev/config/SparkMaxConfig.h>
#include <frc/controller/PIDController.h>
#include <frc/controller/ProfiledPIDController.h>
#include <frc/controller/ArmFeedforward.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/RobotController.h>

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

  void PIDPivot(double);
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  bool AtSetPoint();

  void SetSetPoint(double);

  void SetPIDEnable(bool);

  void StayStill();

  void ManualVoltage(units::volt_t iVoltage);

  frc2::CommandPtr SysIdQuasistatic(frc2::sysid::Direction direction);
  frc2::CommandPtr SysIdDynamic(frc2::sysid::Direction direction);

  StatesAlgae GetState();

  void SetState(StatesAlgae);

  void CounterGravity();

 private:

  StatesAlgae mState;

  bool PIDEnable = true;

  frc2::sysid::SysIdRoutine * m_sysIdRoutine;

  rev::spark::SparkRelativeEncoder * mMotorRelativeEncoder;
  rev::spark::SparkMax * mAlgaePivotMotor = nullptr;
  frc::PIDController * mPIDController;
  frc::ProfiledPIDController<units::radians> * mProfiledPIDController;
  frc::ArmFeedforward * mArmFeedForward;
  rev::spark::SparkMaxConfig * mSparkMaxConfig;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};