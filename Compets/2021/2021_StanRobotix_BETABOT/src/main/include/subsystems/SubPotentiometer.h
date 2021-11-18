// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/AnalogPotentiometer.h>
#include "Constants.h"

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
  frc::AnalogPotentiometer pot{kPotentiometerPort, 180, 30};
};
