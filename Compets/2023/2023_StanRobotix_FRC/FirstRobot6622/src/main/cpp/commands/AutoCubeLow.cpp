// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "../../include/commands/AutoCubeLow.h"
#include "../../include/RobotContainer.h"

#include <iostream>

AutoCubeLow::AutoCubeLow(RobotContainer * iRobotContainer)
{
   mCurrentStep = Phase1_;

   mRobotContainer = iRobotContainer;

   mGenericTimer.Reset();

   EnableSubsystemLog(kLogAutoCubeLowEnable);
   EnablePerformanceLog(kLogPerf_AutoCubeLowEnable);

   Init();
}

/**
 * The initial subroutine of a command.  Called once when the command is
 * initially scheduled.
 */
void AutoCubeLow::Init()
{
   mCurrentStep = Phase1_;

   mSubDriveTrain = mRobotContainer->getSubDriveTrain();
   mSubLimelight = mRobotContainer->getSubLimelight();
}

/**
 * The main body of a command.  Called repeatedly while the command is
 * scheduled.
 */
void AutoCubeLow::doExecute()
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

   case Phase2_:
      doExecutePhase2();
      wIsFinished = isPhase2Finished();
      wNextPhase = step_t::phase3_;
      break;

   case phase3_:
      doExecutePhase3();
      wIsFinished = isPhase3Finished();
      wNextPhase = step_t::Phase4_;
      break;

   case Phase4_:
      doExecutePhase4();
      wIsFinished = isPhase4Finished();
      wNextPhase = step_t::Phase5_;
      break;
   case Phase5_:
      doExecutePhase5();
      wIsFinished = isPhase5Finished();
      wNextPhase = step_t::Phase6_;
      break;
   case Phase6_:
      doExecutePhase6();
      wIsFinished = isPhase6Finished();
      wNextPhase = step_t::Phase7_;
      break;
   case Phase7_:
      doExecutePhase7();
      wIsFinished = isPhase7Finished();
      wNextPhase = step_t::Phase8_;
      break;
   case Phase8_:
      doExecutePhase8();
      wIsFinished = isPhase8Finished();
      wNextPhase = step_t::Phase9_;
      break;
   case Phase9_:
      doExecutePhase9();
      wIsFinished = isPhase9Finished();
      wNextPhase = step_t::PhaseFinish;
      break;
   case PhaseFinish:
      break;
   };

   if (wIsFinished)
   {
      mCurrentStep = wNextPhase;
   }
}

bool AutoCubeLow::isFinish()
{
  return mCurrentStep == PhaseFinish;
}

void AutoCubeLow::reset() 
{ 
   std :: cout <<  "Fin de l'execution de AutoCubeLow" << std::endl;
   mCurrentStep = Phase1_; 
} 

void AutoCubeLow::doExecutePhase1()
{
   std :: cout <<  "Execution de  AutoCubeLow" << std::endl;
}

bool AutoCubeLow::isPhase1Finished()
{
   return true;
}

void AutoCubeLow::doExecutePhase2() { }
bool AutoCubeLow::isPhase2Finished() { return false; }
void AutoCubeLow::doExecutePhase3() { }
bool AutoCubeLow::isPhase3Finished() { return false; }
void AutoCubeLow::doExecutePhase4() { }
bool AutoCubeLow::isPhase4Finished() { return false; }
void AutoCubeLow::doExecutePhase5() { }
bool AutoCubeLow::isPhase5Finished() { return false; }
void AutoCubeLow::doExecutePhase6() { }
bool AutoCubeLow::isPhase6Finished() { return false; }
void AutoCubeLow::doExecutePhase7() { }
bool AutoCubeLow::isPhase7Finished() { return false; }
void AutoCubeLow::doExecutePhase8() { }
bool AutoCubeLow::isPhase8Finished() { return false; }
void AutoCubeLow::doExecutePhase9() { }
bool AutoCubeLow::isPhase9Finished() { return false; }

void AutoCubeLow::doFinish() { }



