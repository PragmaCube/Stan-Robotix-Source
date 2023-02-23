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

void RobotContainer::Init()
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

  std::cout << "RobotContainer::Init() terminé" << std::endl ;  
  mIsInit = true;
}

void RobotContainer::AutonomousInit()
{
  if (!mIsInit)
  {
    Init();
  }
}

void RobotContainer::AutonomousPeriodic()
{
  m_autonomousCommand->Execute();
}

void RobotContainer::TeleopInit()
{
  if (!mIsInit)
  {
    Init();
  }
}

void RobotContainer::DriveDisplacement()
{// TODO
  const double slider = (1 - mJoystick.GetThrottle()) / 2;
  mSubDriveTrain->MoveMeca(mJoystick.GetX() * slider, mJoystick.GetY() * slider, mJoystick.GetTwist() * slider, 1 - mJoystick.GetRawButton(1));
  // if (mJoystick.GetRawButtonPressed(2))
  // {
  //   SubIMU::getInstance()->ResetYaw();
  // }
}

void RobotContainer::ConfigureButtonBindings()
{
  // Configure your button bindings here
}

void RobotContainer::Drive()
{
  DriveDisplacement();

  //mSubUltrasonic->Execute(); TODO Enable it!!!! toto

 // mSubElevator->setCommand(mJoystick.GetPOV()); // TODO

  mSubImu->Execute();

  mSubColorSensor->Execute();

 // mSubLimelight->doExecute(); // TODO toto

  if (mJoystick.GetRawButtonPressed(1)) // TODO
  {
    mSubPneumatic->Toggle();
  }
}

void RobotContainer::Auto()
{
}

