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
    static int count =0;
    
    if (GetRawButtonPressed(11))
    {
        mMenuIndex++;

        if (mMenuIndex == CMD_MAX)
        {
            mMenuIndex=0;
        }

        std :: cout <<  "Selection de " << mCommandList[mMenuIndex].mDescription << std::endl;
    }

    if (GetRawButtonPressed(12))
    {
        mActiveIndex = mMenuIndex;
        std :: cout <<  "Activation de " << mCommandList[mMenuIndex].mDescription << std::endl; 
    }

    if (mCommandList[mMenuIndex].mCommandPtr != nullptr)
    {        
       mCommandList[mMenuIndex].mCommandPtr->Execute();

       bool wFinish = mCommandList[mMenuIndex].mCommandPtr->isFinish();

       if (wFinish)
       {
         mCommandList[mMenuIndex].mCommandPtr->reset();
         mActiveIndex = mMenuIndex = MANUAL_TELEOP;
       }
    }

    if ((count % 50) == 0) 
    {
        for(int i=MANUAL_TELEOP; i<CMD_MAX; i++) 
        {
       
        }

       
    }
    count++;
}

