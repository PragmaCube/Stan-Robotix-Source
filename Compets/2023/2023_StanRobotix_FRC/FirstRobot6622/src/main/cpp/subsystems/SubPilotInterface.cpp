// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubPilotInterface.h"

#include "commands/AutoConeHigh.h"
#include "commands/ManualPilot.h"
#include "commands/AutoFinalStabilisation.h"
#include "commands/AutoFollowTag.h"

SubPilotInterface::SubPilotInterface(RobotContainer * iRobotContainer) 
{
   mRobotContainer = iRobotContainer;
    std::chrono::microseconds getFunctionMeanExecutionTimeInUs()
    {
        +=newDuration;
        return mAccumulFuncDurationiNnS/mNumberOfFunctionExecution;
    }
}

void SubPilotInterface::Init() 
{
    // MANUAL_TELEOP, AUTO_CONEHIGH, AUTO_CONELOW, AUTO_CHARGEUP, CMD_MAX };
   mCommandList[MANUAL_TELEOP].mCommandPtr = new ManualPilot(mRobotContainer); 
   mCommandList[AUTO_CONEHIGH].mCommandPtr = new AutoConeHigh(mRobotContainer);  
   mCommandList [AUTO_CHARGEUP].mCommandPtr= new AutoFinalStabilisation (mRobotContainer); 
   mCommandList[AUTO_FOLLOWTAG].mCommandPtr = new AutoFollowTag(mRobotContainer); 
   // AJOUT COMMANDE AUTOMATISEE
}
  
void SubPilotInterface::doExecute()
{  
    if (GetRawButtonPressed(ChangementCommandeAuto))
    {
        mMenuIndex++;

        // TODO: tenir compte de mCommandList[mMenuIndex].isEnabled() pour chercher la
        // prochaine commande utilisable
        if (mMenuIndex == CMD_MAX)
        {
            mMenuIndex = MANUAL_TELEOP;
        }

        std :: cout <<  "Selection de la " << mCommandList[mMenuIndex].mDescription << std::endl;
    }

    if (GetRawButtonPressed(ActivationCommandeAuto))
    {
        mActiveIndex = mMenuIndex; 
        std :: cout << "Activation de la " << mCommandList[mMenuIndex].mDescription << std::endl;
    }

    if (GetRawButtonPressed(AnnulationCommandeAuto))
    {
        std :: cout <<  "Interruption de la " << mCommandList[mMenuIndex].mDescription << std::endl;

        mActiveIndex = MANUAL_TELEOP;
        mMenuIndex   = MANUAL_TELEOP;        
    }

    if (mCommandList[mActiveIndex].mCommandPtr != nullptr)
    {        
       startFunctionTimer();
       mCommandList[mActiveIndex].mCommandPtr->Execute();
       stopFunctionTimer();


       // affiche du texte dans la console

       bool wFinish = mCommandList[mActiveIndex].mCommandPtr->isFinish();
       if (wFinish)
       {
         if (mActiveIndex != MANUAL_TELEOP)
         {
            mCommandList[mActiveIndex].mCommandPtr->reset(); // Pour remettre l'etat de la commande
                                                             // automatique a zero!
            std :: cout <<  "Mort naturel de la " << mCommandList[mMenuIndex].mDescription << 
                           std::endl << " Mode manuel activé" << std::endl;
         
         }
         mActiveIndex = MANUAL_TELEOP;
       }
    }
    else
    {
       mActiveIndex = MANUAL_TELEOP;
       mCommandList[mActiveIndex].mCommandPtr->Execute();
    }
}

