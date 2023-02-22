// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems\SubContactDetection.h"

SubContactDetection::SubContactDetection()
{
    mDigitalInputVector.reserve(10);
}

// parcourir la liste kContactEnable[10] avec for (;;)
// si l element index = true alors

void SubContactDetection::Init()
{
    for (int i = 0; i < 10; i++)
    {
        if (kContactEnable[i])
        {
            mDigitalInputVector[i] = new frc::DigitalInput(i);
        }
    }
}

bool SubContactDetection::GetContactStatus(int index)
{
    if (kContactEnable[index] == true)
    {
        return mContactCache[index];
    }

    return false;
}

// This method will be called once per scheduler run
void SubContactDetection::Periodic()
{
    for (int i = 0; i < 10; i++)
    {
        if (kContactEnable[i] == true)
        {
            mContactCache[i] = mDigitalInputVector[i]->Get();
        }
    }
}