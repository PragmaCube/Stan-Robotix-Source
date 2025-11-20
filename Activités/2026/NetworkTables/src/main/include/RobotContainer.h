// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandJoystick.h>
#include <frc2/command/button/CommandXboxController.h>
#include <pathplanner/lib/commands/PathPlannerAuto.h>
#include <pathplanner/lib/auto/AutoBuilder.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/Command.h>
#include <pathplanner/lib/auto/NamedCommands.h>
#include <memory>

#include "Constants.h"

#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubIMU.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and trigger mappings) should be declared here.
 */
class RobotContainer
{
public:
  RobotContainer();

  enum Auto
  {
    RougeGauche,
    RougeCentre,
    RougeDroite,
    BleuGauche,
    BleuCentre,
    BleuDroite,
    Test
  };

  frc2::CommandPtr GetAutonomousCommand(Auto);

private:
  void ConfigureBindings();

  // Replace with CommandPS4Controller or CommandJoystick if needed
  frc2::CommandJoystick *m_commandJoystick = nullptr;
  frc2::CommandXboxController *m_commandXbox = nullptr;

  // The robot's subsystems are defined here...
  SubDriveTrain *mDriveTrain = nullptr;
  SubIMU *mIMU = nullptr;
};
