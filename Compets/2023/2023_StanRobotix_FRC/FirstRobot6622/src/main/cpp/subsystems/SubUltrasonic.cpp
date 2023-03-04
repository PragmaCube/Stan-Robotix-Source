// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Date       Auteur       Description                                               Test
// 21jan2023  Antoine T.   Prototypage de ultra son                Distance avec plusieurs objets
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Référence: https://docs.wpilib.org/en/stable/docs/software/hardware-apis/sensors/ultrasonics-software.html

#include "subsystems/SubUltrasonic.h"

#include <iostream>

SubUltrasonic::SubUltrasonic()
{
    Enable(kUltrasonEnable);
    EnableSubsystemLog(kLogUltrason);
    EnablePerformanceLog(kLogPerf_UltrasonEnable);
}

void SubUltrasonic::Init()
{
  if (mIsEnabled && mUltrasonic == nullptr)
  {
    mUltrasonic = new frc::AnalogInput(kUltrasonicDIO);
  }
}

float SubUltrasonic::getDistance()
{
    double wDistance = 0.0f;

    if (mUltrasonic != nullptr)
    {
        double wRawValue = mUltrasonic->GetValue();

        double wVoltageScaleFactor = 5 / frc::RobotController::GetVoltage5V();


        if (mMetricSystem)
        {
            wDistance = wRawValue * wVoltageScaleFactor * 0.125; // Distance in centimeter
        }
        else
        {
            wDistance = wRawValue * wVoltageScaleFactor * 0.0492; // Distance in Inch
        }
    }
    else
    {
        wDistance = -10.0f;
    }

    return wDistance;
}

void SubUltrasonic::doExecute()
{
    if (kUltrasonEnable && kLogUltrason)
    {
        std::cout << "Ultrason: " << getDistance() << std::endl;
    }
}
