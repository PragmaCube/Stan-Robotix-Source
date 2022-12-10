// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutonomousCommand.h"

AutonomousCommand::AutonomousCommand()
{

}

void AutonomousCommand::setSubsystem(SubEjector* pEjector, SubDriveTrain * pDriveTrain, SubClimber * pClimber)
{
     m_pEjectorSubsystem = pEjector;
     m_pDriveTrain = pDriveTrain;
     m_pClimber = pClimber;

     
}
