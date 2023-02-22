// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems\SubContactDetection.h"

SubContactDetection::SubContactDetection()
{
    mDigitalInputVector.reserve(inputMax);
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
    if (kContactEnable[index] == true) 
    {
        return mContactCache[index];
    }

    return false;
}

// This method will be called once per scheduler run
void SubContactDetection::doExecute()
{
    for (int i = input0; i < inputMax; i++)
    {
        if (kContactEnable[i] == true)
        {
            mContactCache[i] = mDigitalInputVector[i]->Get();
        }
    }
}