// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <iostream>

RobotContainer::RobotContainer()
{
  // Liste des commandes automatises.
  // Ne pas creer les commandes comme  m_ManualPilot ici
  m_autonomousCommand = new AutonomousCommand(this);
  
  // Liste des sorties
  mSubDriveTrain      = new SubDriveTrain(this); // On mets this car ce subsystem depend d'autres
  mSubElevator        = new SubElevator(this);
  mSubPneumatic       = new SubPneumatic(this);

  // liste des entrees.
  mSubColorSensor     = new SubColorSensor();
  mSubImu             = new SubIMU();
  mSubLimelight       = new SubLimelight();
  mSubContactDetection= new SubContactDetection();
  mSubPilotInterface  = new SubPilotInterface(this);
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

  mSubPilotInterface->Init(); // Requis absoltu: Derniere initialisation sinon Boum!!!!!!
                              // Tous les autres subsystems (mSubDriveTrain, mSubImu...)
                              // doivent etre initialises avant d initialiser les commandes
                              // automatisees.

  std::cout << "Initialisation de RobotContainer terminée" << std::endl ;  
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

void RobotContainer::ConfigureButtonBindings()
{
  // Configure your button bindings here
}

void RobotContainer::Execute()
{
  mSubPilotInterface ->Execute();
}

void RobotContainer::Auto()
{
}

