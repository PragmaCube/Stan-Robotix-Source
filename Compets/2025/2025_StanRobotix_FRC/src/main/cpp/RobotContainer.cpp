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
  mSubReefPivot = new SubReefPivot;

  mJoystick = new frc::Joystick{0};
  mJoystickSecondaire = new frc::XboxController{1};

  mDriveTrain->SetDefaultCommand(frc2::RunCommand(
      [this] {
      mDriveTrain->driveFieldRelative(-mJoystick->GetX(), -mJoystick->GetY(), -mJoystick->GetZ(), (-(mJoystick->GetThrottle()) / 2) + 0.5);
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

  mSubReefPivot->SetDefaultCommand(frc2::RunCommand(
    [this] {
      mSubReefPivot->StopPivot();
      mSubReefPivot->StopIntake();
    },
    {mSubReefPivot}));

  mSubCoralIntake->SetDefaultCommand(frc2::RunCommand(
    [this] {
      mSubCoralIntake->Stop();
    },
    {mSubCoralIntake}));

   mSubAlgaeIntake->SetDefaultCommand(frc2::RunCommand(
    [this] {
      mSubAlgaeIntake->Stop();
    },
    {mSubAlgaeIntake}));

  ConfigureBindings();

  mIMU->resetAngle();

  frc::SmartDashboard::PutNumber("Angle P", 0.15);
  frc::SmartDashboard::PutNumber("Angle I", 0);
  frc::SmartDashboard::PutNumber("Angle D", 0.015);

  pathplanner::NamedCommands::registerCommand("Go to tag", std::move(GoToTag(mDriveTrain, mIMU).ToPtr()));

  pathplanner::NamedCommands::registerCommand("Pivot coral up", std::move(CoralPivotUp(mSubCoralPivot, mSubCoralIntake).ToPtr()));
  pathplanner::NamedCommands::registerCommand("Pivot coral down", std::move(CoralPivotDown(mSubCoralPivot).ToPtr()));
  pathplanner::NamedCommands::registerCommand("Coral intake", std::move(CoralIntake(mSubCoralIntake).ToPtr()));
  pathplanner::NamedCommands::registerCommand("Coral outtake", std::move(CoralOuttake(mSubCoralIntake, mJoystickSecondaire).ToPtr()));

  pathplanner::NamedCommands::registerCommand("Pivot algae up", std::move(AlgaePivotUp(mSubAlgaePivot).ToPtr()));
  pathplanner::NamedCommands::registerCommand("Pivot algae down", std::move(AlgaePivotDown(mSubAlgaePivot).ToPtr()));
  pathplanner::NamedCommands::registerCommand("Algae full intake", std::move(AlgaeFullIntake(mSubAlgaeIntake, mSubAlgaePivot).ToPtr()));
  pathplanner::NamedCommands::registerCommand("Algae intake", std::move(AlgaeIntakeIn(mSubAlgaeIntake).ToPtr()));
  pathplanner::NamedCommands::registerCommand("Algae outtake", std::move(AlgaeIntakeOut(mSubAlgaeIntake, mJoystickSecondaire).ToPtr()));





  autoChooser = pathplanner::AutoBuilder::buildAutoChooser("New Auto 1m");

  // Build an auto chooser. This will use frc2::cmd::None() as the default option.
  // frc::SendableChooser<frc2::Command *> autoChooser = pathplanner::AutoBuilder::buildAutoChooser("Default Auto");
  
  // frc::SmartDashboard::PutData("Auto Chooser", &autoChooser);

  mTabGeneral->AddCamera("camera Tab","Limelight + usb",std::span<const std::string>({ "http://10.66.22.11:5800/" })).WithWidget(frc::BuiltInWidgets::kCameraStream);
  mTabGeneral->Add("GoToTag",false);
}


void RobotContainer::periodic(){}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  // Schedule `ExampleCommand` when `exampleCondition` changes to `true`
  frc2::Trigger([this] {
    return m_subsystem.ExampleCondition();
  }).OnTrue(ExampleCommand(&m_subsystem).ToPtr());

  frc2::Trigger([this] {
    return mJoystick->GetRawButton(1);
  }).WhileTrue(ReefPivotUp(mSubReefPivot).ToPtr());  

  frc2::Trigger([this] {
    return mJoystick->GetRawButton(JoystickBindingsConstants::Algae::kManualPivotUp);
  }).WhileTrue(ClimbPivotUp(mSubAlgaePivot).ToPtr());  

  frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::kGoToTag);
  }).OnTrue(GoToTag(mDriveTrain, mIMU).ToPtr());

  frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::kResetIMU);
  }).WhileTrue(frc2::RunCommand([this] {mIMU->resetAngle();},{mIMU}).ToPtr());  

   frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(12);
  }).OnTrue(frc2::RunCommand([this] {mSubAlgaePivot->StayStill();},{mSubAlgaePivot}).ToPtr());

  frc2::Trigger([this] {
    return mJoystick->GetRawButton(11);
  }).WhileTrue(ManualReefPivot(mSubReefPivot).ToPtr());

  // frc2::Trigger([this] {
  //   return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::kClimb);
  // }).OnTrue(Climb(mSubAlgaePivot, mJoystick).ToPtr());

  frc2::Trigger([this] {
    return mJoystick->GetRawButton(JoystickBindingsConstants::Coral::kManualIn);
  }).WhileTrue(CoralIntake(mSubCoralIntake).ToPtr());

  frc2::Trigger([this] {
    return mJoystickSecondaire->GetLeftBumperButtonPressed();
  }).OnTrue(CoralOuttake(mSubCoralIntake, mJoystickSecondaire).ToPtr());

  frc2::Trigger([this] {
    return mJoystick->GetRawButton(JoystickBindingsConstants::Algae::kManualIn);
  }).WhileTrue(AlgaeIntakeIn(mSubAlgaeIntake).ToPtr());

  frc2::Trigger([this] {
    return mJoystickSecondaire->GetRightBumperButton();
  }).WhileTrue(AlgaeIntakeOut(mSubAlgaeIntake, mJoystickSecondaire).ToPtr());

  frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::Algae::kPivotUp);
  }).OnTrue(AlgaePivotUp(mSubAlgaePivot).ToPtr());

  frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::Algae::kPivotDown);
  }).OnTrue(AlgaePivotDown(mSubAlgaePivot).ToPtr());  

  frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::Coral::kPivotUp);
  }).OnTrue(CoralPivotUp(mSubCoralPivot, mSubCoralIntake).ToPtr());

  frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::Coral::kPivotDown);
  }).OnTrue(CoralPivotDown(mSubCoralPivot).ToPtr());  

  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  m_driverController.B().WhileTrue(m_subsystem.ExampleMethodCommand());

}

frc2::CommandPtr RobotContainer::GetAutonomousCommand(Auto iStartingPoint) {
  // An example command will be run in autonomous

  switch (iStartingPoint)
  {
  case BleuGauche:
    return pathplanner::PathPlannerAuto("Bleu Gauche").ToPtr();
    break;

  case BleuCentre:
    return pathplanner::PathPlannerAuto("Bleu Centre").ToPtr();
    break;

  case BleuDroite:
    return pathplanner::PathPlannerAuto("Bleu Droite").ToPtr();
    break;
  
  case RougeGauche:
    return pathplanner::PathPlannerAuto("Rouge Gauche").ToPtr();
    break;

  case RougeCentre:
    return pathplanner::PathPlannerAuto("Rouge Centre").ToPtr();
    break;

  case RougeDroite:
    return pathplanner::PathPlannerAuto("Rouge Droite").ToPtr();
    break;

  case Test:
    return pathplanner::PathPlannerAuto("Test").ToPtr();
    break;
  }
  // return *autoChooser.GetSelected();
  // return autos::ExampleAuto(&m_subsystem);
}