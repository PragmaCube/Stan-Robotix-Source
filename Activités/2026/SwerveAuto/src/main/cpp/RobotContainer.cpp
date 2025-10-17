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

  m_commandJoystick = new frc2::CommandJoystick{0};
  m_commandXbox = new frc2::CommandXboxController{1};

  mIMU = new SubIMU;
  mDriveTrain = new SubDriveTrain{mIMU};

  mDriveTrain->SetDefaultCommand(frc2::RunCommand(
      [this] {
     mDriveTrain->driveFieldRelative(-m_commandJoystick->GetHID().GetX(),
                                      -m_commandJoystick->GetHID().GetY(),
                                      -m_commandJoystick->GetHID().GetZ(),
                                      (-(m_commandJoystick->GetHID().GetThrottle()) / 2) + 0.5);
      },
      {mDriveTrain}));

  // mSubCoralPivot->SetDefaultCommand(frc2::RunCommand(
  //   [this] {
  //     mSubCoralPivot->CounterGravity();
  //   },
  //   {mSubCoralPivot}));

  // mSubAlgaePivot->SetDefaultCommand(frc2::RunCommand(
  //   [this] {
  //     mSubAlgaePivot->CounterGravity();
  //   },
  //   {mSubAlgaePivot}));

  // mSubReefPivot->SetDefaultCommand(frc2::RunCommand(
  //   [this] {
  //     mSubReefPivot->CounterGravity();
  //     mSubReefPivot->StopIntake();
  //   },
  //   {mSubReefPivot}));

  // mSubCoralIntake->SetDefaultCommand(frc2::RunCommand(
  //   [this] {
  //     mSubCoralIntake->Stop();
  //   },
  //   {mSubCoralIntake}));

  //  mSubAlgaeIntake->SetDefaultCommand(frc2::RunCommand(
  //   [this] {
  //     mSubAlgaeIntake->Stop();
  //   },
  //   {mSubAlgaeIntake}));

  ConfigureBindings();

  mIMU->resetAngle();

  // pathplanner::NamedCommands::registerCommand("Go to tag", std::move(GoToTag(mDriveTrain, mIMU).ToPtr()));

  // pathplanner::NamedCommands::registerCommand("Pivot coral up", std::move(CoralPivotUp(mSubCoralPivot, mSubCoralIntake).ToPtr()));
  // pathplanner::NamedCommands::registerCommand("Pivot coral down", std::move(CoralPivotDown(mSubCoralPivot).ToPtr()));
  // pathplanner::NamedCommands::registerCommand("Pivot coral down 0.5s", std::move(AutoCoralDown(mSubCoralPivot).ToPtr()));
  // pathplanner::NamedCommands::registerCommand("Coral intake", std::move(CoralIntake(mSubCoralIntake).ToPtr()));
  // pathplanner::NamedCommands::registerCommand("Coral outtake", std::move(CoralOuttake(mSubCoralIntake, m_commandXbox->GetHID()).ToPtr()));

  // pathplanner::NamedCommands::registerCommand("Pivot algae up", std::move(AlgaePivotUp(mSubAlgaePivot).ToPtr()));
  // pathplanner::NamedCommands::registerCommand("Pivot algae down", std::move(AlgaePivotDown(mSubAlgaePivot).ToPtr()));
  // pathplanner::NamedCommands::registerCommand("Algae full intake", std::move(AlgaeFullIntake(mSubAlgaeIntake, mSubAlgaePivot).ToPtr()));
  // pathplanner::NamedCommands::registerCommand("Algae intake", std::move(AlgaeIntakeIn(mSubAlgaeIntake).ToPtr()));
  // pathplanner::NamedCommands::registerCommand("Algae outtake", std::move(AlgaeIntakeOut(mSubAlgaeIntake, m_commandXbox->GetHID()).ToPtr()));

  // autoChooser = pathplanner::AutoBuilder::buildAutoChooser("New Auto 1m");

  // Build an auto chooser. This will use frc2::cmd::None() as the default option.
  frc::SendableChooser<frc2::Command *> autoChooser = pathplanner::AutoBuilder::buildAutoChooser("Default Auto");
  
  frc::SmartDashboard::PutData("Auto Chooser", &autoChooser);

  mTabGeneral->AddCamera("camera Tab","Limelight + usb",std::span<const std::string>({ "http://10.66.22.11:5800/" })).WithWidget(frc::BuiltInWidgets::kCameraStream);
  mTabGeneral->Add("GoToTag",false);
}

void RobotContainer::periodic(){}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  // m_commandJoystick->Button(JoystickBindingsConstants::kGoToTag).OnTrue(GoToTag(mDriveTrain, mIMU).ToPtr());

  // m_commandJoystick->Button(JoystickBindingsConstants::kResetIMU).WhileTrue(frc2::RunCommand([this] {mIMU->resetAngle();},{mIMU}).ToPtr());  

  // m_commandJoystick->Button(12).OnTrue(ReefPivotDown(mSubReefPivot).ToPtr());
  // m_commandJoystick->Button(11).WhileTrue(ManualReefPivot(mSubReefPivot).ToPtr());
  // m_commandJoystick->Button(1).WhileTrue(ReefPivotUp(mSubReefPivot).ToPtr());  

  // m_commandJoystick->Button(JoystickBindingsConstants::kClimb).OnTrue(Climb(mSubAlgaePivot, mJoystick).ToPtr());

  // m_commandJoystick->Button(JoystickBindingsConstants::Coral::kManualIn).WhileTrue(CoralIntake(mSubCoralIntake).ToPtr());
  // m_commandXbox->LeftBumper().OnTrue(CoralOuttake(mSubCoralIntake, mJoystickSecondaire).ToPtr());

  // m_commandJoystick->Button(JoystickBindingsConstants::Algae::kManualIn).WhileTrue(AlgaeIntakeIn(mSubAlgaeIntake).ToPtr());
  // m_commandXbox->RightBumper().WhileTrue(AlgaeIntakeOut(mSubAlgaeIntake, mJoystickSecondaire).ToPtr());

  // m_commandJoystick->Button(JoystickBindingsConstants::Algae::kPivotUp).OnTrue(AlgaePivotUp(mSubAlgaePivot).ToPtr());
  // m_commandJoystick->Button(JoystickBindingsConstants::Algae::kPivotDown).OnTrue(AlgaePivotDown(mSubAlgaePivot).ToPtr());  
  // m_commandJoystick->Button(JoystickBindingsConstants::Algae::kManualPivotUp).WhileTrue(ClimbPivotUp(mSubAlgaePivot).ToPtr());  

  // m_commandJoystick->Button(JoystickBindingsConstants::Coral::kPivotUp).WhileTrue(CoralPivotUp(mSubCoralPivot, mSubCoralIntake).ToPtr());
  // m_commandJoystick->Button(JoystickBindingsConstants::Coral::kPivotDown).WhileTrue(CoralPivotDown(mSubCoralPivot).ToPtr());
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand(Auto iStartingPoint) {
  // An example command will be run in autonomous

  // switch (iStartingPoint)
  // {
  // case BleuGauche:
  //   return pathplanner::PathPlannerAuto("Bleu Gauche").ToPtr();
  //   break;

  // case BleuCentre:
  //   return pathplanner::PathPlannerAuto("Bleu Centre").ToPtr();
  //   break;

  // case BleuDroite:
  //   return pathplanner::PathPlannerAuto("Bleu Droite").ToPtr();
  //   break;
  
  // case RougeGauche:
  //   return pathplanner::PathPlannerAuto("Rouge Gauche").ToPtr();
  //   break;

  // case RougeCentre:
  //   return pathplanner::PathPlannerAuto("Rouge Centre").ToPtr();
  //   break;

  // case RougeDroite:
  //   return pathplanner::PathPlannerAuto("Rouge Droite").ToPtr();
  //   break;

  // case Test:
  //   return pathplanner::PathPlannerAuto("Test").ToPtr();
  //   break;
  // }
  // return *autoChooser.GetSelected();
  return autos::ExampleAuto(&m_subsystem);
}
