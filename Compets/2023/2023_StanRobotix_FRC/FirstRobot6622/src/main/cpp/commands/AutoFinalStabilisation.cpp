// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "../../include/commands/AutoFinalStabilisation.h"
#include "../../include/RobotContainer.h"
#include "subsystems/PerformanceMonitor.h"
#include <iostream>

AutoFinalStabilisation::AutoFinalStabilisation(RobotContainer *iRobotContainer)
{
   mRobotContainer = iRobotContainer;

   mGenericTimer.Reset();

   EnableSubsystemLog(kLogAutoFinalStabilisationEnable);
   EnablePerformanceLog(kLogPerf_AutoFinalStabilisationEnable);

   Init();
}

/**
 * The initial subroutine of a command.  Called once when the command is
 * initially scheduled.
 */
void AutoFinalStabilisation::Init()
{
   mSubDriveTrain = mRobotContainer->getSubDriveTrain();
   mSubIMU = mRobotContainer->getSubIMU();
   mPitchController.SetSetpoint(0);

}

/**
 * The main body of a command.  Called repeatedly while the command is
 * scheduled.
 */
void AutoFinalStabilisation::doExecute()
{
   /*if (mSubIMU->getAnglePitch() < -1.0) // l'IMU est trop precis il n'y aura jamais une valeur == a 0 il faut donc laisser une marge
   {
      if (mCurrentDir != eBackward)
      {
         mSpeed = mSpeed / 1.75;
      }
      mSubDriveTrain->setParameters(0, -mSpeed, 0, false); // le robot recule
      mSubDriveTrain->Execute();
      mCurrentDir = eBackward;
   }
   else if (mSubIMU->getAnglePitch() > 1.0)
   {
      if (mCurrentDir != eForward)
      {
         mSpeed = mSpeed / 1.75;
      }
      mSubDriveTrain->setParameters(0, mSpeed, 0, false); // le robot avance
      mSubDriveTrain->Execute();
      mCurrentDir = eForward;
   }
   else {
      mSubDriveTrain->setParameters(0, 0, 0, false); // le robot east immobile
      mSubDriveTrain->Execute();
   }*/
   double wXOutput = 0.0;
   if(mSubIMU->getAnglePitch() != 0)
  {
    wYOutput = mXController.Calculate(mSubIMU->getAnglePitch());
  }
  mSubDriveTrain->setParameters(0,wYOutput,0,0);
  mSubDriveTrain->Execute();
}

bool AutoFinalStabilisation::isFinish()
{
   return false; // pour que la tache ne se finit jamsais puisqu'elle est fait à la fin
}

void AutoFinalStabilisation::Reset()
{
   std :: cout <<  "Fin de l'execution de AutoFinalStabilisation" << std::endl;
   mCurrentDir = eNotInit;
}
