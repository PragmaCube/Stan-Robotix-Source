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
  
  //m_PeriodeAuto = new frc2::CommandPtr(pathplanner::PathPlannerAuto("Test Auto").ToPtr());

  mIMU = new SubIMU;
  mDriveTrain = new SubDriveTrain{mIMU};
  mSubAlgaePivot = new SubAlgaePivot;
  mSubAlgaeIntake = new SubAlgaeIntake;
  mSubCoralPivot = new SubCoralPivot;
  mSubCoralIntake = new SubCoralIntake;
  mJoystick = new frc::Joystick{0};
  mJoystickSecondaire = new frc::XboxController{1};

  mDriveTrain->SetDefaultCommand(frc2::RunCommand(
      [this] {
      mDriveTrain->driveFieldRelative(-mJoystick->GetX(), -mJoystick->GetY(), -mJoystick->GetZ());
      },
      {mDriveTrain}));

  mSubCoralPivot->SetDefaultCommand(frc2::RunCommand(
    [this] {
      mSubCoralPivot->CounterGravity();
    },
    {mSubCoralPivot}));

  mSubAlgaePivot->SetDefaultCommand(frc2::RunCommand(
    [this] {
      mSubAlgaePivot->CounterGravity();
    },
    {mSubAlgaePivot}));

  ConfigureBindings();

  mIMU->resetAngle();



  pathplanner::NamedCommands::registerCommand("Go to tag", std::move(SequentialGoToTag(mDriveTrain, mIMU, mSubCoralPivot).ToPtr()));

  pathplanner::NamedCommands::registerCommand("Pivot coral up", std::move(CoralPivotUp(mSubCoralPivot).ToPtr()));
  pathplanner::NamedCommands::registerCommand("Pivot coral down", std::move(CoralPivotDown(mSubCoralPivot).ToPtr()));
  pathplanner::NamedCommands::registerCommand("Coral intake", std::move(CoralIntake(mSubCoralIntake, mJoystick).ToPtr()));
  pathplanner::NamedCommands::registerCommand("Coral outtake", std::move(CoralOuttake(mSubCoralIntake, mJoystickSecondaire).ToPtr()));

  pathplanner::NamedCommands::registerCommand("Pivot algae up", std::move(AlgaePivotUp(mSubAlgaePivot).ToPtr()));
  pathplanner::NamedCommands::registerCommand("Pivot algae down", std::move(AlgaePivotDown(mSubAlgaePivot).ToPtr()));
  pathplanner::NamedCommands::registerCommand("Algae full intake", std::move(AlgaeFullIntake(mJoystick, mSubAlgaeIntake, mSubAlgaePivot).ToPtr()));
  pathplanner::NamedCommands::registerCommand("Algae intake", std::move(AlgaeIntakeIn(mSubAlgaeIntake, mJoystick).ToPtr()));
  pathplanner::NamedCommands::registerCommand("Algae outtake", std::move(AlgaeIntakeOut(mSubAlgaeIntake, mJoystickSecondaire).ToPtr()));





  autoChooser = pathplanner::AutoBuilder::buildAutoChooser("New Auto 1m");

  // Build an auto chooser. This will use frc2::cmd::None() as the default option.
  // frc::SendableChooser<frc2::Command *> autoChooser = pathplanner::AutoBuilder::buildAutoChooser("Default Auto");
  
  frc::SmartDashboard::PutData("Auto Chooser", &autoChooser);
}


void RobotContainer::periodic(){}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  // Schedule `ExampleCommand` when `exampleCondition` changes to `true`
  frc2::Trigger([this] {
    return m_subsystem.ExampleCondition();
  }).OnTrue(ExampleCommand(&m_subsystem).ToPtr());



  frc2::Trigger([this] {
    return mJoystick->GetRawButton(10);
  }).WhileTrue(ClimbPivotUp(mSubAlgaePivot).ToPtr());  

  frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::kGoToTag);
  }).OnTrue(SequentialGoToTag(mDriveTrain, mIMU, mSubCoralPivot).ToPtr());

  frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::kResetIMU);
  }).WhileTrue(frc2::RunCommand([this] {mIMU->resetAngle();},{mIMU}).ToPtr());  

   frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(12);
  }).OnTrue(frc2::RunCommand([this] {mSubAlgaePivot->StayStill();},{mSubAlgaePivot}).ToPtr());

  // frc2::Trigger([this] {
  //   return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::kClimb);
  // }).OnTrue(Climb(mSubAlgaePivot, mJoystick).ToPtr());

  frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::Coral::kManualIn);
  }).OnTrue(CoralIntake(mSubCoralIntake, mJoystick).ToPtr());

  frc2::Trigger([this] {
    return mJoystickSecondaire->GetLeftBumperButtonPressed();
  }).OnTrue(CoralOuttake(mSubCoralIntake, mJoystickSecondaire).ToPtr());

  frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::Algae::kManualIn);
  }).OnTrue(AlgaeIntakeIn(mSubAlgaeIntake, mJoystick).ToPtr());

  frc2::Trigger([this] {
    return mJoystickSecondaire->GetRightBumperButtonPressed();
  }).OnTrue(AlgaeIntakeOut(mSubAlgaeIntake, mJoystickSecondaire).ToPtr());

  frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::Algae::kPivotUp);
  }).OnTrue(AlgaePivotUp(mSubAlgaePivot).ToPtr());

  frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::Algae::kPivotDown);
  }).OnTrue(AlgaePivotDown(mSubAlgaePivot).ToPtr());  

  frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::Coral::kPivotUp);
  }).OnTrue(CoralPivotUp(mSubCoralPivot).ToPtr());

  frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::Coral::kPivotDown);
  }).OnTrue(CoralPivotDown(mSubCoralPivot).ToPtr());  

  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  m_driverController.B().WhileTrue(m_subsystem.ExampleMethodCommand());

}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  mDriveTrain->resetPose(PoseInit);
  return pathplanner::PathPlannerAuto("Comp Gauche").ToPtr();
  // return *autoChooser.GetSelected();
  // return autos::ExampleAuto(&m_subsystem);
}