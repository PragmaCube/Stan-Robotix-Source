// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "../../include/commands/AutoFinalStabilisation.h"
#include "../../include/RobotContainer.h"
#include "subsystems/PerformanceMonitor.h"
#include <iostream>

AutoFinalStabilisation::AutoFinalStabilisation(RobotContainer *iRobotContainer)
{
   mRobotContainer = iRobotContainer;

   mGenericTimer.Reset();

   EnableSubsystemLog(kLogAutoFinalStabilisationEnable);
   EnablePerformanceLog(kLogPerf_AutoFinalStabilisationEnable);

   Init();
}

/**
 * The initial subroutine of a command.  Called once when the command is
 * initially scheduled.
 */
void AutoFinalStabilisation::Init()
{
   mSubDriveTrain = mRobotContainer->getSubDriveTrain();
   mSubIMU = mRobotContainer->getSubIMU();
   mPitchController.SetSetpoint(0.0);
}

/**
 * The main body of a command.  Called repeatedly while the command is
 * scheduled.
 */
void AutoFinalStabilisation::doExecute()
{
   mSubIMU->Execute();
   double wAngle = mSubIMU->getAnglePitch();
   double wYaw = mSubIMU->getAngleYaw();
   double wYOutput = 0.0;
   double wYawOutput = 0.0;
   
   if(abs(wAngle - mPitchController.GetSetpoint()) > 0.0)
   {
      wYOutput = mPitchController.Calculate(wAngle);
   }
   if(abs(wYaw - mYawController.GetSetpoint()) > 0.0)
   {
      wYawOutput = mYawController.Calculate(wYaw);
   }
   mSubDriveTrain->setParameters(0, -wYOutput, -wYawOutput, 0);
   mSubDriveTrain->Execute();
   std::cout << wAngle <<std::endl;
}

bool AutoFinalStabilisation::isFinish()
{
   return false; // pour que la tache ne se finit jamsais puisqu'elle est fait à la fin
}

void AutoFinalStabilisation::Reset()
{
   std :: cout <<  "Fin de l'execution de AutoFinalStabilisation" << std::endl;
   mCurrentDir = eNotInit;
}