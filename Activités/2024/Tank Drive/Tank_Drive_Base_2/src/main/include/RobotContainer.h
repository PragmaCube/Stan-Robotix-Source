// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc/XboxController.h>

#include "Constants.h"
#include "subsystem/SubDriveTrain.h"

class RobotContainer {
 public:
  RobotContainer();

  void drive();

  frc2::CommandPtr GetAutonomousCommand();

 private:

  frc::XboxController mXboxController{OperatorConstants:: kDriveControllerPort};
  SubDriveTrain mDriveTrain;
  
  void ConfigureBindings();
};
