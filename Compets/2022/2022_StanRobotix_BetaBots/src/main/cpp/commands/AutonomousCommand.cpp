// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutonomousCommand.h"
#include <iostream>

AutonomousCommand::AutonomousCommand()
{
   mCurrentStep = Phase1_;

   mGenericTimer.Reset();
}

void AutonomousCommand::setSubsystem(SubEjector *pEjector, SubDriveTrain *pDriveTrain, SubClimber *pClimber, SubIMU *pIMU)
{
   m_pEjectorSubsystem = pEjector;
   m_pDriveTrain = pDriveTrain;
   m_pClimber = pClimber;
   m_pIMU = pIMU;
}
/**
 * The initial subroutine of a command.  Called once when the command is
 * initially scheduled.
 */
void AutonomousCommand::Initialize()
{
   mCurrentStep = Phase1_;
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
      wNextPhase = step_t::PhaseFinish;
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
   static bool executeTimerOnce = true;
   static bool didEjectorExecuted = true;


   static int StartAngle = 0; // note explicative: on pourrait creer aussi une propriete mStartAngle dans le .h.... mais elle serait accessible
                              // a toutes les fonctions membres de la classe.... Si vous avez besoin d'une variables angle dans deux phases
                              // differente.... votre .h deviendra un gros fouilli.
                              // l<avantage de declarer statique fait en sorte que c est comme une propriete de l objet AutonomousCommand, mais
                              // elle n est visible que pour la fonction doExecutePhase1. Et surtout, le fait qu elle soit statique, on ne perd pas
                              // l valeur de la variable a chaque fois que doExecutePhase1 est appelle.

   // avance drive train avec timer
   // m_pClimber->Stage(m_Height[2]);
   // m_pClimber->Periodic();

   // Tourne robot avec IMU
   // m_pClimber->Periodic();

   m_pEjectorSubsystem->Periodic(didEjectorExecuted);
   didEjectorExecuted = false;

}

bool AutonomousCommand::isPhase1Finished()
{
   if (m_pEjectorSubsystem->isOperationCompleted())
   {
      return false;
   }
   return true;
}

void AutonomousCommand::doExecutePhase2()
{
   static bool executeTimerOnce = true;

   m_pDriveTrain->TankDrive(1,-1, SubDriveTrain::MotorSpeed::eSlow);

   if (executeTimerOnce)
   {
      mGenericTimer.Start();
   }
}

bool AutonomousCommand::isPhase2Finished()
{
   return (mGenericTimer.Get().value() > 2);
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

void AutonomousCommand::doFinish()
{
   m_pDriveTrain->TankDrive(0, 0, SubDriveTrain::MotorSpeed::eSlow); // Stop the robot
}

// List of example for autonomous period
/*  Example 1: Turn right for 90 degrees
void doExecutePhase1_TurnRight()
{
   m_pDriveTrain->TankDrive(1,-1, SubDriveTrain::MotorSpeed::eSlow);
}

bool isPhase1_TurnRight_Finished()
{
     static float startAngle = m_pIMU->getAngle();

     if (fabs(startAngle-m_pIMU->getAngle()) > 90)
     {
        m_pDriveTrain->TankDrive(0,0, SubDriveTrain::MotorSpeed::eSlow);
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

   m_pDriveTrain->TankDrive(1,-1, SubDriveTrain::MotorSpeed::eSlow);

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
   m_pDriveTrain->TankDrive(0,0, SubDriveTrain::MotorSpeed::eSlow);
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
      return false;
   }
   return true;
}*/