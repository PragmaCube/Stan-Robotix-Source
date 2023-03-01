// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubGamePieceHandler.h"
#include "Constants.h"

SubGamePieceHandler::SubGamePieceHandler() 
{
    EnableSubsystemLog(kLogGamePieceHandler);
    EnablePerformanceLog(kLogPerf_GamePieceHandlerEnable);
    Enable(kGamePieceHandlernabled);

    setLogPeriodity(kLogPeriod_260ms);
}

void SubGamePieceHandler::Extract()
{
    m_motor1.Set(0.5);
    m_motor2.Set(-0.5);
}

void SubGamePieceHandler::Retract()
{
    m_motor1.Set(-0.5);
    m_motor2.Set(0.5);
}

void SubGamePieceHandler::Stop()
{
    m_motor1.Set(0);
    m_motor2.Set(0);
}

// This method will be called once per scheduler run
void SubGamePieceHandler::doExecute() {}

void SubGamePieceHandler::Init()
{

}
