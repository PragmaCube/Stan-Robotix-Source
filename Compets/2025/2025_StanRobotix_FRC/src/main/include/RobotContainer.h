// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>
#include <frc/Joystick.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubAlgaePivot.h"
#include "subsystems/SubCoralPivot.h"
#include "subsystems/SubAlgaeIntake.h"
#include "subsystems/SubCoralIntake.h"

#include "commands/AlgaePivotDown.h"
#include "commands/AlgaePivotUp.h"
#include "commands/AlgaeIntakeIn.h"
#include "commands/AlgaeIntakeOut.h"

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

  void periodic();
  void Initialize();
  frc2::CommandPtr GetAutonomousCommand();


 private:
  // Replace with CommandPS4Controller or CommandJoystick if needed
  frc2::CommandXboxController m_driverController{
      OperatorConstants::kDriverControllerPort};

  // The robot's subsystems are defined here...
  ExampleSubsystem m_subsystem;
  SubDriveTrain * mDriveTrain = nullptr;
  SubIMU * mIMU = nullptr;
  SubAlgaePivot * mSubAlgaePivot = nullptr;
  SubAlgaeIntake * mSubAlgaeIntake = nullptr;
  SubCoralPivot * mSubCoralPivot = nullptr;
  SubCoralIntake * mSubCoralIntake = nullptr;
  frc::Joystick mJoystick{0};

  void ConfigureBindings();
};
