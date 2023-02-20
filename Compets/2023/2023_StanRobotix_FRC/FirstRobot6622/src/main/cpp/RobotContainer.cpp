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
  mDriveTrain = new SubDriveTrain(this);
  mElevator = new SubElevator(this);
  mPneumatic = new SubPneumatic(this);

  // liste des entrees.
  mImu = new SubIMU();
  mLimelight = new SubLimelight();
  mColorSensor = new SubColorSensor();
  mUltrasonic = new SubUltrasonic();
  mUltrasonic->EnableImperialSystem();

  ConfigureButtonBindings();
}

void RobotContainer::AutonomousInit()
{
  // Initialisation des subsystemes
  mDriveTrain->Init();
  mElevator->Init();
  mPneumatic->Init();
  mImu->Init();
  mLimelight->Init();
  mColorSensor->Init();
  mUltrasonic->Init();

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
  mDriveTrain->MoveMeca(mJoystick.GetX() * slider, mJoystick.GetY() * slider, mJoystick.GetTwist() * slider, 1 - mJoystick.GetRawButton(1));
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

  mUltrasonic->Execute();

  mElevator->setCommand(mJoystick.GetPOV());

  SubIMU::getInstance()->Execute();

  mColorSensor->Execute();

  mLimelight->Execute();

  if (mJoystick.GetRawButtonPressed(1))
  {
    mPneumatic->Toggle();
  }
}

void RobotContainer::Auto()
{
}