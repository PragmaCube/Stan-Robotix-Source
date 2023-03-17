// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "../../include/commands/AutonomousCommand.h"
#include "../../include/RobotContainer.h"

#include <iostream>

AutonomousCommand::AutonomousCommand(RobotContainer * iRobotContainer)
{
   mCurrentStep = Phase1_1_;

   mRobotContainer = iRobotContainer;

   mGenericTimer.Reset();
}

/**
 * The initial subroutine of a command.  Called once when the command is
 * initially scheduled.
 */
void AutonomousCommand::Init()
{
   mCurrentStep = Phase1_1_;

   m_pDriveTrain = mRobotContainer->getSubDriveTrain();
   m_pUltrasonic = mRobotContainer->getSubUltrasonic();
   m_pIMU        = mRobotContainer->getSubIMU();
}

/**
 * The main body of a command.  Called repeatedly while the command is
 * scheduled.
 */
void AutonomousCommand::Execute()
{
   switch (mCurrentSenario)
   {
   // Senario1 = allez chercher le cube au loin, en tournant legerement vers la gauche
   case Senario1:
      doExecuteSenario1();
      break;
   // Senario2 = aller sur le truc au millieu
   case Senario2:
      doExecuteSenario2();
      break;
   // Senario3 = allez chercher le cube au loin, en tournant legerement vers la droite
   case Senario3:
      doExecuteSenario3();
      break;
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

void AutonomousCommand::doExecuteSenario1()
{
   bool wIsFinished = true;
   step_t wNextPhase = mCurrentStep;
   
   switch (mCurrentStep)
   {
   case Phase1_1_:
      doExecutePhase1_1();
      wIsFinished = isPhase1_1Finished();
      wNextPhase = step_t::Phase1_2_;
      break;

   case Phase1_2_:
      doExecutePhase1_2();
      wIsFinished = isPhase1_2Finished();
      wNextPhase = step_t::Phase1_3_;
      break;

   case Phase1_3_:
      doExecutePhase1_3();
      wIsFinished = isPhase1_3Finished();
      wNextPhase = step_t::Phase2_s1_;
      break;

   case Phase2_s1_:
      doExecutePhase2_s1();
      wIsFinished = isPhase2_s1Finished();
      wNextPhase = step_t::Phase3_s1_;
      break;
   
    case Phase3_s1_:
      doExecutePhase3_s1();
      wIsFinished = isPhase3_s1Finished();
      wNextPhase = step_t::Phase4_s1_s3;
      break;

   case Phase4_s1_s3:
      doExecutePhase4_s1_s3();
      wIsFinished = isPhase4_s1_s3Finished();
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

void AutonomousCommand::doExecuteSenario2()
{
   bool wIsFinished = true;
   step_t wNextPhase = mCurrentStep;
   
   switch (mCurrentStep)
   {
   case Phase1_1_:
      doExecutePhase1_1();
      wIsFinished = isPhase1_1Finished();
      wNextPhase = step_t::Phase1_2_;
      break;

   case Phase1_2_:
      doExecutePhase1_2();
      wIsFinished = isPhase1_2Finished();
      wNextPhase = step_t::Phase1_3_;
      break;

   case Phase1_3_:
      doExecutePhase1_3();
      wIsFinished = isPhase1_3Finished();
      wNextPhase = step_t::Phase2_s2_;
      break;

   case Phase2_s2_:
      doExecutePhase2_s2();
      wIsFinished = isPhase2_s2Finished();
      wNextPhase = step_t::Phase2_s2_;
      break;
    case Phase3_s2_:
      doExecutePhase3_s2();
      wIsFinished = isPhase3_s2Finished();
      wNextPhase = step_t::Phase4_s2;
      break;

   case Phase4_s2:
      doExecutePhase4_s2();
      wIsFinished = isPhase4_s2Finished();
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

void AutonomousCommand::doExecuteSenario3()
{
   bool wIsFinished = true;
   step_t wNextPhase = mCurrentStep;
   
   switch (mCurrentStep)
   {
   case Phase1_1_:
      doExecutePhase1_1();
      wIsFinished = isPhase1_1Finished();
      wNextPhase = step_t::Phase1_2_;
      break;

   case Phase1_2_:
      doExecutePhase1_2();
      wIsFinished = isPhase1_2Finished();
      wNextPhase = step_t::Phase1_3_;
      break;

   case Phase1_3_:
      doExecutePhase1_3();
      wIsFinished = isPhase1_3Finished();
      wNextPhase = step_t::Phase2_s3_;
      break;

   case Phase2_s3_:
      doExecutePhase2_s3();
      wIsFinished = isPhase2_s3Finished();
      wNextPhase = step_t::Phase3_s3_;
      break;
   case Phase3_s3_:
      doExecutePhase3_s3();
      wIsFinished = isPhase3_s3Finished();
      wNextPhase = step_t::Phase4_s1_s3;
      break;

   case Phase4_s1_s3:
      doExecutePhase4_s1_s3();
      wIsFinished = isPhase4_s1_s3Finished();
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


void AutonomousCommand::doExecutePhase1_1()
{
   // avancer un peu et aggriper le cube avec le cube
}

bool AutonomousCommand::isPhase1_1Finished()
{
  
}

void AutonomousCommand::doExecutePhase1_2()
{
   // etendre l'elevator
}

bool AutonomousCommand::isPhase1_2Finished()
{ 
   /*
   static bool executePhase1_2Once = true;
      if (executePhase1_2Once)
     {
      mGenericTimer.Reset();
      mGenericTimer.Start();
      executePhase1_2Once = false;
     }
     if (mGenericTimer.Get() >= 0.5_s)
     {
         return true;
     }
   return false;
   */

}

void AutonomousCommand::doExecutePhase1_3()
{
 // lache le cube et retracte
}

bool AutonomousCommand::isPhase1_3Finished()
{
   
   return true;
     
}

void AutonomousCommand::doExecutePhase2_s1()
{
   // reculer un peu, tournez vers la droite d'un peu moins de 180 dergres
}


bool AutonomousCommand::isPhase2_s1Finished()
{
   return true;
}

void AutonomousCommand::doExecutePhase2_s2()
{
  // reculer un peu, tournez de 180 dergres
}

bool AutonomousCommand::isPhase2_s2Finished()
{

     return true;
   
}

void AutonomousCommand::doExecutePhase2_s3()
{
  // reculer un peu, tournez vers la gauche d'un peu moins de 180 dergres
}


bool AutonomousCommand::isPhase2_s3Finished()
{
  return true;
}

void AutonomousCommand::doExecutePhase3_s1()
{
   // avancer jusqu'au cube et tourner legement vers la droite
}


bool AutonomousCommand::isPhase3_s1Finished()
{
     return true;
}

void AutonomousCommand::doExecutePhase3_s2()
{
  // avancer jusqu'a la plateforme
}


bool AutonomousCommand::isPhase3_s2Finished()
{
   return true;
}

void AutonomousCommand::doExecutePhase3_s3()
{
  // avancer jusqu'au cube et tourner legement vers la gauche
}

bool AutonomousCommand::isPhase3_s3Finished()
{
   return true;
}

void AutonomousCommand::doExecutePhase4_s1_s3()
{
   // avancer un peu et toggle la pneumatique pour aggriper le cube
}


bool AutonomousCommand::isPhase4_s1_s3Finished()
{
     return true;
}

void AutonomousCommand::doExecutePhase4_s2()
{
  // se maintenir sur la plateforme
}


bool AutonomousCommand::isPhase4_s2Finished()
{
   return true;
}


void AutonomousCommand::doFinish()
{
}

// List of example for autonomous period
/*  Example 1: Turn right for 90 degrees
void doExecutePhase1_1_TurnRight()
{
   m_pDriveTrain->MoveDrive(1,-1, SubDriveTrain::MotorSpeed::eSlow);
}

bool isPhase1_1_TurnRight_Finished()
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
void doExecutePhase1_1()
{
   static bool executeTimerOnce = true;
   if (executeTimerOnce)
   {
      mGenericTimer.Start();
   }
}

bool isPhase1_1Finished()
{
   if (mGenericTimer.Get().value()>10)
   {
     mGenericTimer.Reset();
     return true;
   }
   return false;
}

void doExecutePhase1_2()
{
   static bool executeTimerOnce = true;

   m_pDriveTrain->MoveDrive(1,-1, SubDriveTrain::MotorSpeed::eSlow);

   if (executeTimerOnce)
   {
      mGenericTimer.Start();
   }
}

bool isPhase1_2Finished()
{
     return (mGenericTimer.Get().value()>2);
}

void doExecutePhase1_3()
{
   m_pDriveTrain->MoveDrive(0,0, SubDriveTrain::MotorSpeed::eSlow);
}
*/

/* Example 3: Exemple pour utiliser l'ejecteur en periode autonome.
void doExecutePhase1_1()
{
   static bool didEjectorExecuted = true;
   m_pEjectorSubsystem->Periodic(didEjectorExecuted);
   didEjectorExecuted = false;

}

bool isPhase1_1Finished()
{
   if (m_pEjectorSubsystem->isOperationCompleted())
   {
      return true;
   }
   return false;
}*/

/* Example 4: Exemple pour utiliser le climber. A la fin de la montee, l ejector s active
void doExecutePhase1_1()
{
   m_pClimber->Stage(SubClimber::eHeight::h2);
   m_pClimber->Periodic();
}

bool isPhase1_1Finished()
{
   return m_pClimber->isOperationCompleted();
}

void doExecutePhase1_2()
{
   static bool didEjectorExecuted = true;
   m_pEjectorSubsystem->Periodic(didEjectorExecuted);
   didEjectorExecuted = false;
}*/


