// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "../../include/commands/AutoFinalStabilisation.h"
#include "../../include/RobotContainer.h"

#include <iostream>

AutoFinalStabilisation::AutoFinalStabilisation(RobotContainer * iRobotContainer)
{
   mCurrentStep = Phase1_;

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
   mCurrentStep = Phase1_;

   mSubDriveTrain = mRobotContainer->getSubDriveTrain();
   mSubLimelight = mRobotContainer->getSubLimelight();
}

/**
 * The main body of a command.  Called repeatedly while the command is
 * scheduled.
 */
void AutoFinalStabilisation::doExecute()
{
   bool wIsFinished = true;
   step_t wNextPhase = mCurrentStep;
   
   switch (mCurrentStep)
   {
   case Phase1_:
      doExecutePhase1();
      wIsFinished = isPhase1Finished();
      wNextPhase = step_t::PhaseFinish;
      break;
   }
}

bool AutoFinalStabilisation::isFinish()
{
   return false; // pour que la tache ne se finit jamsais puisqu'elle est fait à la fin 
}

void AutoFinalStabilisation::Reset() 
{ 
   std :: cout <<  "Fin de l'execution de AutoFinalStabilisation" << std::endl;
   mCurrentStep = Phase1_; 
} 

/**
 * The action to take when the command ends.  Called when either the command
 * finishes normally, or when it interrupted/canceled.
 *
 * @param interrupted whether the command was interrupted/canceled
 */

void AutoFinalStabilisation::doExecutePhase1()
{
   std :: cout <<  "Execution de  AutoFinalStabilisation" << std::endl;

}

bool AutoFinalStabilisation::isPhase1Finished()
{
   return true;
}
