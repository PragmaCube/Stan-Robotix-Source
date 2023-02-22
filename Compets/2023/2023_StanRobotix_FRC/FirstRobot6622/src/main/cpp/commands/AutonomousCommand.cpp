// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "../../include/commands/AutonomousCommand.h"
#include "../../include/RobotContainer.h"

#include <iostream>

AutonomousCommand::AutonomousCommand(RobotContainer * iRobotContainer)
{
   mCurrentStep = Phase1_;

   mRobotContainer = iRobotContainer;

   mGenericTimer.Reset();
}

/**
 * The initial subroutine of a command.  Called once when the command is
 * initially scheduled.
 */
void AutonomousCommand::Init()
{
   mCurrentStep = Phase1_;

   m_pDriveTrain = mRobotContainer->getDriveTrain();
   m_pUltrasonic = mRobotContainer->getUltrasonic();
   m_pIMU        = mRobotContainer->getImu();
}

/**
 * The main body of a command.  Called repeatedly while the command is
 * scheduled.
 */
void AutonomousCommand::Execute()
{
   bool wIsFinished = true;
   step_t wNextPhase = mCurrentStep;
   
   switch (mCurrentStep)
   {
   case Phase1_:
      doExecutePhase1();
      wIsFinished = isPhase1Finished();
      wNextPhase = step_t::Phase2_;
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

/**
 * The action to take when the command ends.  Called when either the command
 * finishes normally, or when it interrupted/canceled.
 *
 * @param interrupted whether the command was interrupted/canceled
 */
void AutonomousCommand::End(bool interrupted)
{
   doFinish();
}

void AutonomousCommand::doExecutePhase1()
{
   
m_pDriveTrain->MoveMeca(0,0.5,0,false);

}

bool AutonomousCommand::isPhase1Finished()
{
   static bool executePhase1Once = true;
      if (executePhase1Once)
     {
      mGenericTimer.Start();
      executePhase1Once = false;
     }
     if (mGenericTimer.Get() >= 0.5_s)
     {
         return true;
     }
   return false;
}

void AutonomousCommand::doExecutePhase2()
{
m_pDriveTrain->MoveMeca(0,-0.5,0,false);

}

bool AutonomousCommand::isPhase2Finished()
{
   
 
   static bool executePhase2Once = true;
      if (executePhase2Once)
     {
      mGenericTimer.Reset();
      mGenericTimer.Start();
      executePhase2Once = false;
     }
     if (mGenericTimer.Get() >= 0.5_s)
     {
         return true;
     }
   return false;
   
}

void AutonomousCommand::doExecutePhase3()
{
 
}

bool AutonomousCommand::isPhase3Finished()
{

     return true;
     
}

void AutonomousCommand::doExecutePhase4()
{
}


bool AutonomousCommand::isPhase4Finished()
{
   return true;
}

void AutonomousCommand::doExecutePhase5()
{
  
}

bool AutonomousCommand::isPhase5Finished()
{

     return true;
   
}

void AutonomousCommand::doExecutePhase6()
{
  
}


bool AutonomousCommand::isPhase6Finished()
{
  return true;
}

void AutonomousCommand::doExecutePhase7()
{

}


bool AutonomousCommand::isPhase7Finished()
{
     return true;
}

void AutonomousCommand::doExecutePhase8()
{
  
}


bool AutonomousCommand::isPhase8Finished()
{
   return true;
}

void AutonomousCommand::doExecutePhase9()
{
  
}

bool AutonomousCommand::isPhase9Finished()
{
   return true;
}


void AutonomousCommand::doFinish()
{
}

// List of example for autonomous period
/*  Example 1: Turn right for 90 degrees
void doExecutePhase1_TurnRight()
{
   m_pDriveTrain->MoveDrive(1,-1, SubDriveTrain::MotorSpeed::eSlow);
}

bool isPhase1_TurnRight_Finished()
{
     static float startAngle = m_pIMU->getAngle();

     if (fabs(startAngle-m_pIMU->getAngle()) > 90)
     {
        m_pDriveTrain->MoveDrive(0,0, SubDriveTrain::MotorSpeed::eSlow);
        return true;
     }

     return false;
}
*/

/* Example 2: Attend 10 secondes, tourne le robot pendant deux secondes et arrete.
void doExecutePhase1()
{
   static bool executeTimerOnce = true;
   if (executeTimerOnce)
   {
      mGenericTimer.Start();
   }
}

bool isPhase1Finished()
{
   if (mGenericTimer.Get().value()>10)
   {
     mGenericTimer.Reset();
     return true;
   }
   return false;
}

void doExecutePhase2()
{
   static bool executeTimerOnce = true;

   m_pDriveTrain->MoveDrive(1,-1, SubDriveTrain::MotorSpeed::eSlow);

   if (executeTimerOnce)
   {
      mGenericTimer.Start();
   }
}

bool isPhase2Finished()
{
     return (mGenericTimer.Get().value()>2);
}

void doExecutePhase3()
{
   m_pDriveTrain->MoveDrive(0,0, SubDriveTrain::MotorSpeed::eSlow);
}
*/

/* Example 3: Exemple pour utiliser l'ejecteur en periode autonome.
void doExecutePhase1()
{
   static bool didEjectorExecuted = true;
   m_pEjectorSubsystem->Periodic(didEjectorExecuted);
   didEjectorExecuted = false;

}

bool isPhase1Finished()
{
   if (m_pEjectorSubsystem->isOperationCompleted())
   {
      return true;
   }
   return false;
}*/

/* Example 4: Exemple pour utiliser le climber. A la fin de la montee, l ejector s active
void doExecutePhase1()
{
   m_pClimber->Stage(SubClimber::eHeight::h2);
   m_pClimber->Periodic();
}

bool isPhase1Finished()
{
   return m_pClimber->isOperationCompleted();
}

void doExecutePhase2()
{
   static bool didEjectorExecuted = true;
   m_pEjectorSubsystem->Periodic(didEjectorExecuted);
   didEjectorExecuted = false;
}*/


