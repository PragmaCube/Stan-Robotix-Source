// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubPilotInterface.h"

#include "commands/AutoConeHigh.h"
#include "commands/ManualPilot.h"
 
SubPilotInterface::SubPilotInterface(RobotContainer * iRobotContainer) 
{
   mRobotContainer = iRobotContainer;
}

void SubPilotInterface::Init() 
{
    // MANUAL_TELEOP, AUTO_CONEHIGH, AUTO_CONELOW, AUTO_CHARGEUP, CMD_MAX };
   mCommandList[MANUAL_TELEOP].mCommandPtr = new ManualPilot(mRobotContainer); 
   mCommandList[AUTO_CONEHIGH].mCommandPtr = new AutoConeHigh(mRobotContainer);   
}
  
void SubPilotInterface::doExecute()
{  
    if (GetRawButtonPressed(ChangementCommandeAuto))
    {
        mMenuIndex++;

        // TODO: tenir compte de mCommandList[mMenuIndex].mIsEnabled poue chercher la
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
    }

    if (GetRawButtonPressed(AnnulationCommandeAuto))
    {
        std :: cout <<  "Interruption de la " << mCommandList[mMenuIndex].mDescription << std::endl;

        mActiveIndex = MANUAL_TELEOP;
        mMenuIndex   = MANUAL_TELEOP;        
    }

    if (mCommandList[mActiveIndex].mCommandPtr != nullptr)
    {        
       mCommandList[mActiveIndex].mCommandPtr->Execute();

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

