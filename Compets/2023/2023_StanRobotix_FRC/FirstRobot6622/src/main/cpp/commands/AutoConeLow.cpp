// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "../../include/commands/AutoConeLow.h"
#include "../../include/RobotContainer.h"

#include <iostream>

AutoConeLow::AutoConeLow(RobotContainer * iRobotContainer)
{
   mCurrentStep = Phase1_;

   mRobotContainer = iRobotContainer;

   mGenericTimer.Reset();

   EnableSubsystemLog(kLogAutoConeLowEnable);
   EnablePerformanceLog(kLogPerf_AutoConeLowEnable);

   Init();
}

/**
 * The initial subroutine of a command.  Called once when the command is
 * initially scheduled.
 */
void AutoConeLow::Init()
{
   mCurrentStep = Phase1_;

   mSubDriveTrain = mRobotContainer->getSubDriveTrain();
   mSubLimelight = mRobotContainer->getSubLimelight();
}

/**
 * The main body of a command.  Called repeatedly while the command is
 * scheduled.
 */
void AutoConeLow::doExecute()
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

bool AutoConeLow::isFinish()
{
  return mCurrentStep == PhaseFinish;
}

void AutoConeLow::reset() 
{ 
   std :: cout <<  "Fin de l'execution de AutoConeLow" << std::endl;
   mCurrentStep = Phase1_; 
} 

void AutoConeLow::doExecutePhase1()
{
   std :: cout <<  "Execution de  AutoConeLow" << std::endl;
}

bool AutoConeLow::isPhase1Finished()
{
   return true;
}

void AutoConeLow::doExecutePhase2() { }
bool AutoConeLow::isPhase2Finished() { return false; }
void AutoConeLow::doExecutePhase3() { }
bool AutoConeLow::isPhase3Finished() { return false; }
void AutoConeLow::doExecutePhase4() { }
bool AutoConeLow::isPhase4Finished() { return false; }
void AutoConeLow::doExecutePhase5() { }
bool AutoConeLow::isPhase5Finished() { return false; }
void AutoConeLow::doExecutePhase6() { }
bool AutoConeLow::isPhase6Finished() { return false; }
void AutoConeLow::doExecutePhase7() { }
bool AutoConeLow::isPhase7Finished() { return false; }
void AutoConeLow::doExecutePhase8() { }
bool AutoConeLow::isPhase8Finished() { return false; }
void AutoConeLow::doExecutePhase9() { }
bool AutoConeLow::isPhase9Finished() { return false; }

void AutoConeLow::doFinish() { }



