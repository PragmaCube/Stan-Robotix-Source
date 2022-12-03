// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/SubEjector.h"
#include "subsystems/SubDriveTrain.h"
#include "subsystems/subClimber.h"

class AutonomousCommand
    : public frc2::CommandHelper<frc2::CommandBase, AutonomousCommand> {
 public:
  /**
   * Creates a new ExampleCommand.
   *
   * @param subsystem The subsystem used by this command.
   */
  explicit AutonomousCommand();
  
  void setSubsystem(Ejector* pEjector, DriveTrain * pDriveTrain, SubClimber * pClimber);

 private:
   Ejector* m_pEjectorSubsystem;
   DriveTrain * m_pDriveTrain;
   SubClimber * m_pClimber;
};
