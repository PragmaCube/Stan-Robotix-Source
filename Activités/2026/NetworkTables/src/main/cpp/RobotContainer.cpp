// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>
#include <frc2/command/RunCommand.h>

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  m_commandJoystick = new frc2::CommandJoystick{OperatorConstants::kJoystickControllerPortID};
  m_commandXbox = new frc2::CommandXboxController{OperatorConstants::kXboxControlerPortID};

  mIMU = new SubIMU;
  mDriveTrain = new SubDriveTrain{mIMU};

  // mDriveTrain->SetDefaultCommand(frc2::RunCommand(
  //     [this] {
  //     mDriveTrain->driveFieldRelative(-m_commandJoystick->GetHID().GetY(),
  //                                     -m_commandJoystick->GetHID().GetX(),
  //                                     -m_commandJoystick->GetHID().GetZ(),
  //                                     (-(m_commandJoystick->GetHID().GetThrottle()) / 2) + 0.5);
  //     },
  //     {mDriveTrain}));

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
}

void RobotContainer::ConfigureBindings() {
  // m_commandJoystick->Button(JoystickBindingsConstants::kResetIMU).OnTrue(frc2::RunCommand([this] {mIMU->resetAngle();}, {mIMU}).ToPtr());
  
  m_commandXbox->Y().WhileTrue(frc2::RunCommand([this] {mIMU->resetAngle();}, {mIMU}).ToPtr());
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
    return pathplanner::PathPlannerAuto("Rouge Gauche").ToPtr();
    break;
  }
}