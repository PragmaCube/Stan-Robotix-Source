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

  m_commandJoystick = new frc2::CommandJoystick{OperatorConstants::kJoystickControllerPortID};
  m_commandXbox = new frc2::CommandXboxController{OperatorConstants::kXboxControlerPortID};

  mIMU = new SubIMU;
  mDriveTrain = new SubDriveTrain{mIMU};

  mDriveTrain->SetDefaultCommand(frc2::RunCommand(
      [this] {
      mDriveTrain->driveFieldRelative(-m_commandXbox->GetLeftY (),
                                      -m_commandXbox->GetLeftX (),
                                      -m_commandXbox->GetRightX (),
                                      (1 - m_commandXbox->GetRightTriggerAxis()));
     },
     {mDriveTrain}));

  ConfigureBindings();

  mIMU->resetAngle();

  pathplanner::NamedCommands::registerCommand("Go to tag", std::move(GoToTag(mDriveTrain, mIMU).ToPtr()));
}

void RobotContainer::ConfigureBindings() {  
  m_commandXbox->Y().WhileTrue(frc2::RunCommand([this] {mIMU->resetAngle();}, {mIMU}).ToPtr());
  m_commandXbox->X().WhileTrue(frc2::RunCommand([this] {mDriveTrain->resetPose(frc::Pose2d(0_m, 0_m, 0_rad));}, {mDriveTrain}).ToPtr());
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

  default:
    return autos::ExampleAuto(&m_subsystem);
    break;
  }
}