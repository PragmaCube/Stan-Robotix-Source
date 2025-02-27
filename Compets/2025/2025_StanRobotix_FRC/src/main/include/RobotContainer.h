// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>
#include <frc/Joystick.h>
#include <pathplanner/lib/commands/PathPlannerAuto.h>
#include <pathplanner/lib/auto/AutoBuilder.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/Command.h>
#include <memory>

#include "Constants.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/SubDriveTrain.h"


/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and trigger mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::CommandPtr GetAutonomousCommand();

 private:
  // Replace with CommandPS4Controller or CommandJoystick if needed
  frc2::CommandXboxController m_driverController{
      OperatorConstants::kDriverControllerPort};

  // Build an auto chooser. This will use frc2::cmd::None() as the default option.
  frc::SendableChooser<frc2::Command *> autoChooser;

  // The robot's subsystems are defined here...
  ExampleSubsystem m_subsystem;
  SubDriveTrain * mDriveTrain = nullptr;
  SubIMU * mIMU = nullptr;
  frc::Joystick mJoystick{0};

  //frc2::CommandPtr * m_PeriodeAuto;
  // frc::SendableChooser<frc2::Command *> autoChooser;

  void ConfigureBindings();
};
