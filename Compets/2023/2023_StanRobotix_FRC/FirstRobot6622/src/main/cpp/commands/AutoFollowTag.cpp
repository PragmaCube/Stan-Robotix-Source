// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoFollowTag.h"
#include "../../include/RobotContainer.h"

AutoFollowTag::AutoFollowTag(RobotContainer * iRobotContainer)
{
    mRobotContainer = iRobotContainer;

    mGenericTimer.Reset();

    EnableSubsystemLog(kLogAutoFollowTagEnable);
    EnablePerformanceLog(kLogPerf_AutoFollowTagEnable);

    Init();
  }

// Returns true when the command should end.
bool AutoFollowTag::isFinish() {
  return false; //GetController().AtSetpoint();
}

void AutoFollowTag::reset()
{
   std :: cout <<  "Fin de l'execution de AutoFollowTag" << std::endl;
}

void AutoFollowTag::Init()
{
  mSubDriveTrain = mRobotContainer->getSubDriveTrain();
  mSubLimelight = mRobotContainer->getSubLimelight();
}

void AutoFollowTag::doExecute()
{
  mSubLimelight->Execute();
  
  mSubDriveTrain->setParameters(0,0,-mController.Calculate(mSubLimelight->getTargetOffsetAngleHorizontal()),0);
  mSubDriveTrain->Execute();
}
