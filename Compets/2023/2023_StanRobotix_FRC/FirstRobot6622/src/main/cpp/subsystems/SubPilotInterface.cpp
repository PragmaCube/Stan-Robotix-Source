// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubPilotInterface.h"

#include "commands/AutoConeHigh.h"
 
SubPilotInterface::SubPilotInterface(RobotContainer * iRobotContainer) 
{
   mRobotContainer = iRobotContainer;
}

void SubPilotInterface::Init() 
{
    // MANUAL_TELEOP, AUTO_CONEHIGH, AUTO_CONELOW, AUTO_CHARGEUP, CMD_MAX };
   mCommandList[AUTO_CONEHIGH].mCommandPtr = new AutoConeHigh(mRobotContainer);
}
  
void SubPilotInterface::doExecute()
{  
    if (GetRawButtonPressed(ChangementCommandeAuto))
    {
        mMenuIndex++;

        if (mMenuIndex == CMD_MAX)
        {
            mMenuIndex = 0;
        }

        std :: cout <<  "Selection de la " << mCommandList[mMenuIndex].mDescription << std::endl;
    }

    if (GetRawButtonPressed(ActivationCommandeAuto))
    {
        mActiveIndex = mMenuIndex; 
    }

    if (mCommandList[mActiveIndex].mCommandPtr != nullptr)
    {        
       mCommandList[mActiveIndex].mCommandPtr->Execute();

       bool wFinish = mCommandList[mActiveIndex].mCommandPtr->isFinish();
       if (wFinish)
       {
         mCommandList[mActiveIndex].mCommandPtr->reset(); // Pour remettre l'etat de la commande
                                                          // automatique a zero!
         mActiveIndex = mMenuIndex = MANUAL_TELEOP;
       }
    }
}

