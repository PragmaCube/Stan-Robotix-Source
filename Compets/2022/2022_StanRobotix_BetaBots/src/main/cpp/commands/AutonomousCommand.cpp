// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutonomousCommand.h"

AutonomousCommand::AutonomousCommand()
{
   mCurrentStep = Phase1_;
}

void AutonomousCommand::setSubsystem(SubEjector* pEjector, SubDriveTrain * pDriveTrain, SubClimber * pClimber, SubIMU * pIMU)
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
   static int StartAngle = 0; // note explicative: on pourrait creer aussi une propriete mStartAngle dans le .h.... mais elle serait accessible
                              // a toutes les fonctions membres de la classe.... Si vous avez besoin d'une variables angle dans deux phases
                              // differente.... votre .h deviendra un gros fouilli.
                              // l<avantage de declarer statique fait en sorte que c est comme une propriete de l objet AutonomousCommand, mais
                              // elle n est visible que pour la fonction doExecutePhase1. Et surtout, le fait qu elle soit statique, on ne perd pas
                              // l valeur de la variable a chaque fois que doExecutePhase1 est appelle.

   m_pDriveTrain->TankDrive(-1,1, SubDriveTrain::MotorSpeed::eSlow);
   // Tourne robot avec IMU
   // avance drive train avec timer
   //m_pClimber->Stage(m_Height[2]);
   // Tourne robot avec IMU
   //m_pClimber->Periodic();
   /*
   if (m_pEjectorSubsystem->GetEncoder() < kPosOut)
    {
      m_pEjectorSubsystem->Push();
    }
    else
    {
      m_pEjectorSubsystem->Pull();
 
    }
    */
}
void AutonomousCommand::doExecutePhase2()
{

}

void AutonomousCommand::doExecutePhase3()
{

}

void AutonomousCommand::doExecutePhase4()
{

}

bool AutonomousCommand::isPhase1Finished()
{
     return false;
}

bool AutonomousCommand::isPhase2Finished()
{
     return false;
}

bool AutonomousCommand::isPhase3Finished()
{
     return false;
}

bool AutonomousCommand::isPhase4Finished()
{
     return false;
}

void AutonomousCommand::doFinish()
{
   m_pDriveTrain->TankDrive(0,0, SubDriveTrain::MotorSpeed::eSlow); // Stop the robot
}
