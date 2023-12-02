// // Copyright (c) FIRST and other WPILib contributors.
// // Open Source Software; you can modify and/or share it under the terms of
// // the WPILib BSD license file in the root directory of this project.

#include "commands\Autos.h"


#include <iostream>

AutoCmd::AutoCmd(RobotContainer )
 {
mCurrentStep = Phase1_;

//mRobotContainer = iRobotContainer;

  mGenericTimer.Reset();


Init();
}

// /**
//  * The initial subroutine of a command.  Called once when the command is
//  * initially scheduled.
//  */
void AutoCmd::Init()
{
  mCurrentStep = Phase1_;

    //mSubDriveTrain = mRobotContainer->getSubDriveTrain();
   // mSubLimelight = mRobotContainer->getSubLimelight();
 }

// /**
//  * The main body of a command.  Called repeatedly while the command is
//  * scheduled.
//  */
   bool wIsFinished = false;
 void AutoCmd::doExecute()
 {
 
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
       wNextPhase = step_t::Phase3_;
       break;

    case Phase3_:
       doExecutePhase3();
       wIsFinished = isPhase3Finished();
       wNextPhase = step_t::Phase4_;
       break;

    case Phase4_:
       doExecutePhase4();
       wIsFinished = isPhase4Finished();
       wNextPhase = step_t::PhaseFinish;
       break;
   
   };

    if (wIsFinished==true)
    {
       mCurrentStep = wNextPhase;
    }
 }

 bool AutoCmd::isFinish()
 {
   return mCurrentStep == PhaseFinish;
 }

 void AutoCmd::reset() 
 { 
    std :: cout <<  "Fin de l'execution de AutoCmd" << std::endl;
    mCurrentStep = Phase1_; 
 } 

 void AutoCmd::doExecutePhase1()
 {
    std :: cout <<  "Execution de  AutoCmd" << std::endl;
     


     driveTrain.mecanumDrive(0,5,0,IMU.getRotation2D());
   
 }

 bool AutoCmd::isPhase1Finished()
 {
    
    if (mGenericTimer.Get()>5_s)
    {
     mGenericTimer.Reset();
     return true;
    }
    else
    {
     return false;
     }
 }

 void AutoCmd::doExecutePhase2() 
 { 
        
        driveTrain.mecanumDrive(0,0,0.4,IMU.getRotation2D());
     
 }
 bool AutoCmd::isPhase2Finished() 
 { 
    if (mGenericTimer.Get()>5_s)
    {
     mGenericTimer.Reset();
     return true;
    }
    else
    {
     return false;
     }
}

 void AutoCmd::doExecutePhase3() 
 { 
    driveTrain.mecanumDrive(0,5,0,IMU.getRotation2D());

 }
 bool AutoCmd::isPhase3Finished() { 
    
    if (mGenericTimer.Get()>5_s)
    {
     mGenericTimer.Reset();
     return true;
    }
    else
    {
     return false;
     } 
     }
 void AutoCmd::doExecutePhase4() 
 { 
    driveTrain.mecanumDrive(0,0,0.4,IMU.getRotation2D());
    
 }
 bool AutoCmd::isPhase4Finished() { 
    if (mGenericTimer.Get()>5_s)
    {
     mGenericTimer.Reset();
     return true;
    }
    else
    {
     return false;
     } 
     }


 void AutoCmd::doFinish() 
 { 
    std::cout<<"la période autonome est finit"<<std::endl;
     }

