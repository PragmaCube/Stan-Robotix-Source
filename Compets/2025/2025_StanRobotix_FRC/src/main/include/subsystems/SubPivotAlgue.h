// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/controller/PIDController.h>
#include <rev/RelativeEncoder.h>
#include "Constants.h"
#include <rev/SparkMax.h>


class SubPivotAlgue : public frc2::SubsystemBase {
 public:
  SubPivotAlgue();

  void Up();
  void Recup();
  void Down();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  rev::spark::SparkMax * mMoteurPivotAlgue = nullptr;
  frc::PIDController PIDController{Pivot::Algue::kP, Pivot::Algue::kI, Pivot::Algue::kD};

};
