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

    mJoystick.GetRawButtonPressed(11);

    if ((count % 50) == 0) 
    {
        for(int i=MANUAL_TELEOP; i<CMD_MAX; i++) 
        {
        std :: cout <<  mCommandList[i].mDescription << std::endl;
        }
    }
    count++;
}

