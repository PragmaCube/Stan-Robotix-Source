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


    if ((count % 50) == 0) 
    {
        for(int i=MANUAL_TELEOP; i<CMD_MAX; i++) 
        {
        std :: cout <<  mCommandList[i].mDescription << std::endl;
        }

        if (GetRawButtonPressed(11))
        {
            std::cout << "le bouton 11 est pressé" << std::endl;
        }

        if (GetRawButtonPressed(12))
        {
            std::cout << "le bouton 12 est pressé" << std::endl;
        }
    }
    count++;
}

