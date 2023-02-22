// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <iostream>

RobotContainer::RobotContainer()
{
  // Liste des commandes automatises.
  m_autonomousCommand = new AutonomousCommand(this);

  // Liste des sorties
  mSubDriveTrain      = new SubDriveTrain(this);
  mSubElevator        = new SubElevator(this);
  mSubPneumatic       = new SubPneumatic(this);

  // liste des entrees.
  mSubColorSensor     = new SubColorSensor();
  mSubImu             = new SubIMU();
  mSubLimelight       = new SubLimelight();
  mSubContactDetection= new SubContactDetection();
  mSubUltrasonic      = new SubUltrasonic();
  mSubUltrasonic->EnableImperialSystem();
  
  ConfigureButtonBindings();
}

void RobotContainer::AutonomousInit()
{
  // Initialisation des subsystemes
  mSubDriveTrain->Init();
  mSubElevator->Init();
  mSubPneumatic->Init();
  mSubImu->Init();
  mSubLimelight->Init();
  mSubColorSensor->Init();
  mSubContactDetection->Init();
  mSubUltrasonic->Init();

  // Initialisation des commandes automatisees.
  m_autonomousCommand->Init();
}

void RobotContainer::AutonomousPeriodic()
{
  m_autonomousCommand->Execute();
}

void RobotContainer::TeleopInit()
{
  // Initialisation des subsystemes

  // Initialisation des commandes automatisees.
  // TODO: ajouter chaque automatisation
}

void RobotContainer::DriveDisplacement()
{
  const double slider = (1 - mJoystick.GetThrottle()) / 2;
  mSubDriveTrain->MoveMeca(mJoystick.GetX() * slider, mJoystick.GetY() * slider, mJoystick.GetTwist() * slider, 1 - mJoystick.GetRawButton(1));
  if (mJoystick.GetRawButtonPressed(2))
  {
    SubIMU::getInstance()->ResetYaw();
  }
}

void RobotContainer::ConfigureButtonBindings()
{
  // Configure your button bindings here
}

void RobotContainer::Drive()
{
  DriveDisplacement();

  mSubUltrasonic->Execute();

  mSubElevator->setCommand(mJoystick.GetPOV());

  mSubImu->Execute();

  mSubColorSensor->Execute();

  mSubLimelight->Execute();

  if (mJoystick.GetRawButtonPressed(1))
  {
    mSubPneumatic->Toggle();
  }
}

void RobotContainer::Auto()
{
}