// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>
#include <frc2/command/RunCommand.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"

#include "commands/GoToTag.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  m_commandJoystick = new frc2::CommandJoystick{OperatorConstants::kJoystickPortID};
  m_commandXbox = new frc2::CommandXboxController{OperatorConstants::kXboxControlerPortID};

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

  pathplanner::NamedCommands::registerCommand("Go to tag", std::move(GoToTag(mDriveTrain, mIMU).ToPtr()));

  mTabGeneral->AddCamera("camera Tab","Limelight + usb",std::span<const std::string>({ "http://10.66.22.11:5800/" })).WithWidget(frc::BuiltInWidgets::kCameraStream);
  mTabGeneral->Add("GoToTag",false);
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  m_commandJoystick->Button(JoystickBindingsConstants::kGoToTag).OnTrue(GoToTag(mDriveTrain, mIMU).ToPtr());

  m_commandJoystick->Button(JoystickBindingsConstants::kResetIMU).WhileTrue(frc2::RunCommand([this] {mIMU->resetAngle();},{mIMU}).ToPtr());
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
  // return autos::ExampleAuto(&m_subsystem);
}