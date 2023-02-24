// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubPilotInterface.h"

 
SubPilotInterface::SubPilotInterface() 
{

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
        std :: cout <<  "Activation de " << mCommandList[mMenuIndex].mDescription << std::endl;
    }

    if ((count % 50) == 0) 
    {
        for(int i=MANUAL_TELEOP; i<CMD_MAX; i++) 
        {
       
        }

       
    }
    count++;
}

