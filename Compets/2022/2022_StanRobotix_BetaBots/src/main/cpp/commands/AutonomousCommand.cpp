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
   // Tourne avec IMU de 130 degrees vers la gauche
   m_pDriveTrain->MoveDrive(-1,1, SubDriveTrain::MotorSpeed::eMedium);

}

bool AutonomousCommand::isPhase1Finished()
{
   static float startAngle = m_pIMU->getAngle();

     if (fabs(startAngle-m_pIMU->getAngle()) > 100)
     {
        std::cout << "Leaving phase 1 " << std::endl;
        m_pDriveTrain->MoveDrive(0,0, SubDriveTrain::MotorSpeed::eSlow);
        mGenericTimer.Reset();
        return true;
     }

     return false;
   
}

void AutonomousCommand::doExecutePhase2()
{
   // On avance de 2.61 pieds et on active le climber a la hauteur h2
   static bool executeTimerOnce = true;
   bool wRetVal = mGenericTimer.Get().value() < FeetToTime(2.90,eSlow   ) ;
   m_pClimber->Stage(SubClimber::eHeight::h2);
   m_pClimber->Periodic();
   if (wRetVal)
   {
      m_pDriveTrain->MoveDrive(1,1, SubDriveTrain::MotorSpeed::eSlow);
   }


   if (executeTimerOnce)
   {
       mGenericTimer.Start();
   }
}

bool AutonomousCommand::isPhase2Finished()
{
   
   bool wRetVal = mGenericTimer.Get().value() > FeetToTime(3.2,eSlow);
   bool wRetVal2 = m_pClimber->isOperationCompleted();

   if (wRetVal && wRetVal2)
   {
      std::cout << "Leaving phase 2 " << std::endl;
   }
   return (wRetVal && wRetVal2);
   
}

void AutonomousCommand::doExecutePhase3()
{
   // Tourne avec IMU de 130 degrees vers la droite
   m_pDriveTrain->MoveDrive(1,-1, SubDriveTrain::MotorSpeed::eMedium);
}

bool AutonomousCommand::isPhase3Finished()
{
   static float startAngle = m_pIMU->getAngle();

     if (fabs(startAngle-m_pIMU->getAngle()) > 100)
     {
        std::cout << "Leaving phase 3 " << std::endl;
        m_pDriveTrain->MoveDrive(0,0, SubDriveTrain::MotorSpeed::eSlow);
        mGenericTimer.Reset();
        return true;
     }

     return false;
     
}

void AutonomousCommand::doExecutePhase4()
{
   // On avance de 5.6 pieds
   static bool executeTimerOnce = true;

   m_pDriveTrain->MoveDrive(1,1, SubDriveTrain::MotorSpeed::eMedium);

   if (executeTimerOnce)
   {
      
      mGenericTimer.Start();
   }
}


bool AutonomousCommand::isPhase4Finished()
{
   bool wRetVal = mGenericTimer.Get().value() > FeetToTime(3.0,eMedium);
   if (wRetVal)
   {
      std::cout << "Leaving phase 5 " << std::endl;
   }
   return wRetVal;
}

void AutonomousCommand::doExecutePhase5()
{
   // Tourne avec IMU de 16.9 degrees vers la gauche
   m_pDriveTrain->MoveDrive(-1,1, SubDriveTrain::MotorSpeed::eMedium);
}

bool AutonomousCommand::isPhase5Finished()
{
   static float startAngle = m_pIMU->getAngle();

     if (fabs(startAngle-m_pIMU->getAngle()) > 18.0)
     {
        std::cout << "Leaving phase 3 " << std::endl;
        m_pDriveTrain->MoveDrive(0,0, SubDriveTrain::MotorSpeed::eSlow);
        mGenericTimer.Reset();
        return true;
     }

     return false;
   
}

void AutonomousCommand::doExecutePhase6()
{
   // On avance de 5.2 pieds
   static bool executeTimerOnce = true;

   m_pDriveTrain->MoveDrive(1,1, SubDriveTrain::MotorSpeed::eSlow);

   if (executeTimerOnce)
   {
      
      mGenericTimer.Start();
   }
}


bool AutonomousCommand::isPhase6Finished()
{
   bool wRetVal = mGenericTimer.Get().value() > FeetToTime(4.2,eSlow);
   if (wRetVal)
   {
      std::cout << "Leaving phase 5 " << std::endl;
   }
   return wRetVal;
}

void AutonomousCommand::doExecutePhase7()
{
   // Tourne avec IMU de 16.9 degrees vers la droite
   m_pDriveTrain->MoveDrive(1,-1, SubDriveTrain::MotorSpeed::eMedium);
}


bool AutonomousCommand::isPhase7Finished()
{
   static float startAngle = m_pIMU->getAngle();

     if (fabs(startAngle-m_pIMU->getAngle()) > 18.0)
     {
        std::cout << "Leaving phase 3 " << std::endl;
        m_pDriveTrain->MoveDrive(0,0, SubDriveTrain::MotorSpeed::eSlow);
        mGenericTimer.Reset();
        return true;
     }

     return false;
}

void AutonomousCommand::doExecutePhase8()
{
   // On avance de 0.7 pieds
   static bool executeTimerOnce = true;

   m_pDriveTrain->MoveDrive(1,1, SubDriveTrain::MotorSpeed::eSlow);

   if (executeTimerOnce)
   {
      
      mGenericTimer.Start();
   }
}


bool AutonomousCommand::isPhase8Finished()
{
   bool wRetVal = mGenericTimer.Get().value() > FeetToTime(1.5,eSlow);
   if (wRetVal)
   {
      std::cout << "Leaving phase 5 " << std::endl;
   }
   return wRetVal;
}

void AutonomousCommand::doExecutePhase9()
{
   // On utilise l ejector a valeur de vitesse par defaut
   static bool didEjectorExecuted = true;
   m_pEjectorSubsystem->Periodic(didEjectorExecuted);
   // std::cout<<m_pEjectorSubsystem->GetEncoder() << "SALUT CA MARCHE " << std::endl;
   didEjectorExecuted = false;
}

bool AutonomousCommand::isPhase9Finished()
{
   if (m_pEjectorSubsystem->isOperationCompleted())
   {
      std::cout << "Leaving phase 6 " << std::endl;
      return true;
   }
   return false;
}


void AutonomousCommand::doFinish()
{
   m_pDriveTrain->MoveDrive(0, 0, SubDriveTrain::MotorSpeed::eSlow); // Stop the robot
}


float AutonomousCommand::FeetToTime(float mFeet, eSpeed iSpeed)
{
// Pour convertir un distance en pieds en temps
 float mTime;

switch(iSpeed){ 

case eFast:
// 18 ft pour 2.85 secondes
mTime = (2.85* mFeet)/18 ;

case eMedium:
// 18 ft pour 5.5 secondes
mTime = (5.5* mFeet)/18 ;

case eSlow:
// 18 ft pour 12.77 secondes
 mTime = (12.77* mFeet)/18 ;

}

 return mTime;

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


