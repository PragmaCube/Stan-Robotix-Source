// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>
#include <frc2/command/RunCommand.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here
  mDriveTrain = new SubDriveTrain;
  mIMU = new SubIMU;
  //m_PeriodeAuto = new frc2::CommandPtr(pathplanner::PathPlannerAuto("Test Auto").ToPtr());
  mDriveTrain->SetDefaultCommand(frc2::RunCommand(
    [this] {
    mDriveTrain->driveFieldRelative(-mJoystick.GetX(), -mJoystick.GetY(), -mJoystick.GetZ());
    },
    {mDriveTrain}));
  // Configure the button bindings
  ConfigureBindings();

  mIMU->resetAngle();


  autoChooser = pathplanner::AutoBuilder::buildAutoChooser("New Auto 1m");

  // Build an auto chooser. This will use frc2::cmd::None() as the default option.
  // frc::SendableChooser<frc2::Command *> autoChooser = pathplanner::AutoBuilder::buildAutoChooser("Default Auto");
  
  frc::SmartDashboard::PutData("Auto Chooser", &autoChooser);
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  // Schedule `ExampleCommand` when `exampleCondition` changes to `true`
  frc2::Trigger([this] {
    return m_subsystem.ExampleCondition();
  }).OnTrue(ExampleCommand(&m_subsystem).ToPtr());
  
  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(6);
  }).OnTrue(frc2::RunCommand([this] {mIMU->resetAngle();},{mIMU}).ToPtr());  


  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  m_driverController.B().WhileTrue(m_subsystem.ExampleMethodCommand());
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return pathplanner::PathPlannerAuto("Test_avant_arrière_2m").ToPtr();
  // return *autoChooser.GetSelected();
  // return autos::ExampleAuto(&m_subsystem);
}