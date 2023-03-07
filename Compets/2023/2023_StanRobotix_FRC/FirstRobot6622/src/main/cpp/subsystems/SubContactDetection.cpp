// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems\SubContactDetection.h"

#include <iostream>

SubContactDetection::SubContactDetection()
{
    mDigitalInputVector.reserve(inputMax);

    Enable(kContactDetectionEnable);
    EnableSubsystemLog(kLogContactDetection);
    EnablePerformanceLog(kLogPerfContactDetection);
}

void SubContactDetection::Init()
{
    for (int i = input0; i < inputMax; i++)
    {
        if (kContactEnable[i])
        {
            mDigitalInputVector[i] = new frc::DigitalInput(i);
        }
    }
}

bool SubContactDetection::GetContactStatus(InputDetection_t index)
{
    if (kContactEnable[index]) 
    {
        return mContactCache[index];
    }

    return false;
}

// This method will be called once per scheduler run
void SubContactDetection::doExecute()
{
    if (isEnabled())
    {
        for (int i = input0; i < inputMax; i++)
        {
            if (kContactEnable[i])
            {
                bool wCurrent =  mDigitalInputVector[i]->Get();

                if (isSystemLogEnabled() && mContactCache[i] != wCurrent)
                {
                    std::string wNewState = (wCurrent)?"Active":"Inactive";
                    std::cout << "Changement d'etat pour le contact n# " << i << ": " << wNewState << std::endl;
                }
                mContactCache[i] = wCurrent;
            }
        }
    }
}