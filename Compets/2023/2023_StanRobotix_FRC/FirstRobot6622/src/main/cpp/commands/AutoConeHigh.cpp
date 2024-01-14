// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "../../include/commands/AutoConeHigh.h"
#include "../../include/RobotContainer.h"

#include <iostream>

AutoConeHigh::AutoConeHigh(RobotContainer * iRobotContainer)
{
   mCurrentStep = Phase1_;

   mRobotContainer = iRobotContainer;

   mGenericTimer.Reset();

   EnableSubsystemLog(kLogAutoConeHighEnable);
   EnablePerformanceLog(kLogPerf_AutoConeHighEnable);

   Init();
}

/**
 * The initial subroutine of a command.  Called once when the command is
 * initially scheduled.
 */
void AutoConeHigh::Init()
{
   mCurrentStep = Phase1_;

   mSubDriveTrain = mRobotContainer->getSubDriveTrain();
   mSubLimelight = mRobotContainer->getSubLimelight();
}

/**
 * The main body of a command.  Called repeatedly while the command is
 * scheduled.
 */
void AutoConeHigh::doExecute()
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

bool AutoConeHigh::isFinish()
{
  return mCurrentStep == PhaseFinish;
}

void AutoConeHigh::reset() 
{ 
   std :: cout <<  "Fin de l'execution de AutoConeHigh" << std::endl;
   mCurrentStep = Phase1_; 
} 

void AutoConeHigh::doExecutePhase1()
{
   std :: cout <<  "Execution de  AutoConeHigh" << std::endl;
}

bool AutoConeHigh::isPhase1Finished()
{
   return true;
}

void AutoConeHigh::doExecutePhase2() { }
bool AutoConeHigh::isPhase2Finished() { return false; }
void AutoConeHigh::doExecutePhase3() { }
bool AutoConeHigh::isPhase3Finished() { return false; }
void AutoConeHigh::doExecutePhase4() { }
bool AutoConeHigh::isPhase4Finished() { return false; }
void AutoConeHigh::doExecutePhase5() { }
bool AutoConeHigh::isPhase5Finished() { return false; }
void AutoConeHigh::doExecutePhase6() { }
bool AutoConeHigh::isPhase6Finished() { return false; }
void AutoConeHigh::doExecutePhase7() { }
bool AutoConeHigh::isPhase7Finished() { return false; }
void AutoConeHigh::doExecutePhase8() { }
bool AutoConeHigh::isPhase8Finished() { return false; }
void AutoConeHigh::doExecutePhase9() { }
bool AutoConeHigh::isPhase9Finished() { return false; }

void AutoConeHigh::doFinish() { }



