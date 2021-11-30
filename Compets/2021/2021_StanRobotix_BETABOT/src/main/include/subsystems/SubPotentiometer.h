// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/AnalogInput.h>
#include "Constants.h"
#include <frc/RobotController.h>

class SubPotentiometer : public frc2::SubsystemBase {
 public:
  SubPotentiometer();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;

  double getDistance();

 private:
  frc::AnalogInput ultrasonic{kPotentiometerPort};
  frc::RobotController mRobotController;
};
