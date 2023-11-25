// // Copyright (c) FIRST and other WPILib contributors.
// // Open Source Software; you can modify and/or share it under the terms of
// // the WPILib BSD license file in the root directory of this project.

// #include "include\commands\Autos.h"
// #include "include\RobotContainer.h"

// #include <iostream>

// AutoCmd::AutoCmd(RobotContainer * iRobotContainer)
// {
//    mCurrentStep = Phase1_;

//    mRobotContainer = iRobotContainer;

//    mGenericTimer.Reset();

//    EnableSubsystemLog(kLogAutoCmdEnable);
//    EnablePerformanceLog(kLogPerf_AutoCmdEnable);

//    Init();
// }

// /**
//  * The initial subroutine of a command.  Called once when the command is
//  * initially scheduled.
//  */
// void AutoCmd::Init()
// {
//    mCurrentStep = Phase1_;

//    mSubDriveTrain = mRobotContainer->getSubDriveTrain();
//    mSubLimelight = mRobotContainer->getSubLimelight();
// }

// /**
//  * The main body of a command.  Called repeatedly while the command is
//  * scheduled.
//  */
// void AutoCmd::doExecute()
// {
//    bool wIsFinished = true;
//    step_t wNextPhase = mCurrentStep;
   
//    switch (mCurrentStep)
//    {
//    case Phase1_:
//       doExecutePhase1();
//       wIsFinished = isPhase1Finished();
//       wNextPhase = step_t::PhaseFinish;
//       break;

//    case Phase2_:
//       doExecutePhase2();
//       wIsFinished = isPhase2Finished();
//       wNextPhase = step_t::phase3_;
//       break;

//    case phase3_:
//       doExecutePhase3();
//       wIsFinished = isPhase3Finished();
//       wNextPhase = step_t::Phase4_;
//       break;

//    case Phase4_:
//       doExecutePhase4();
//       wIsFinished = isPhase4Finished();
//       wNextPhase = step_t::Phase5_;
//       break;
//    case Phase5_:
//       doExecutePhase5();
//       wIsFinished = isPhase5Finished();
//       wNextPhase = step_t::Phase6_;
//       break;
//    case Phase6_:
//       doExecutePhase6();
//       wIsFinished = isPhase6Finished();
//       wNextPhase = step_t::Phase7_;
//       break;
//    case Phase7_:
//       doExecutePhase7();
//       wIsFinished = isPhase7Finished();
//       wNextPhase = step_t::Phase8_;
//       break;
//    case Phase8_:
//       doExecutePhase8();
//       wIsFinished = isPhase8Finished();
//       wNextPhase = step_t::Phase9_;
//       break;
//    case Phase9_:
//       doExecutePhase9();
//       wIsFinished = isPhase9Finished();
//       wNextPhase = step_t::PhaseFinish;
//       break;
//    case PhaseFinish:
//       break;
//    };

//    if (wIsFinished)
//    {
//       mCurrentStep = wNextPhase;
//    }
// }

// bool AutoCmd::isFinish()
// {
//   return mCurrentStep == PhaseFinish;
// }

// void AutoCmd::reset() 
// { 
//    std :: cout <<  "Fin de l'execution de AutoCmd" << std::endl;
//    mCurrentStep = Phase1_; 
// } 

// void AutoCmd::doExecutePhase1()
// {
//    std :: cout <<  "Execution de  AutoCmd" << std::endl;
// }

// bool AutoCmd::isPhase1Finished()
// {
//    return true;
// }

// void AutoCmd::doExecutePhase2() { }
// bool AutoCmd::isPhase2Finished() { return false; }
// void AutoCmd::doExecutePhase3() { }
// bool AutoCmd::isPhase3Finished() { return false; }
// void AutoCmd::doExecutePhase4() { }
// bool AutoCmd::isPhase4Finished() { return false; }
// void AutoCmd::doExecutePhase5() { }
// bool AutoCmd::isPhase5Finished() { return false; }
// void AutoCmd::doExecutePhase6() { }
// bool AutoCmd::isPhase6Finished() { return false; }
// void AutoCmd::doExecutePhase7() { }
// bool AutoCmd::isPhase7Finished() { return false; }
// void AutoCmd::doExecutePhase8() { }
// bool AutoCmd::isPhase8Finished() { return false; }
// void AutoCmd::doExecutePhase9() { }
// bool AutoCmd::isPhase9Finished() { return false; }

// void AutoCmd::doFinish() { }
