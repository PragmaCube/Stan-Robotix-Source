// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubContactDetection.h"

SubContactDetection::SubContactDetection() {
   mTototo.reserve(10);
   

   // parcourir la liste kContactEnable[10] avec for (;;)
   // si l element index = true alors 
 

   mTototo[mIndex] = new frc::DigitalInput(mIndex);

}

bool SubContactDetection::GetContactStatus (int index) {
   // return mContactStatus.Get();

    return kContactEnable[index % 10] ;
   
}


// This method will be called once per scheduler run
void SubContactDetection::Periodic() 
{
    for(int i=0;i<10 ; i++)
    {
        kContactEnable [i]=mTototo[i]->Get(); 
    }
    // Pour chaque  kContactEnableîç == true
    // mContactStatus[index] = mContactSmTototo[index]->Get(); 
}