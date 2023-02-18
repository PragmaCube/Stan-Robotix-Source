// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubColorSensor.h"

#include <frc/smartdashboard/smartdashboard.h>

SubColorSensor::SubColorSensor() 
{
    mColorMatcher.AddColorMatch(kCube);
    mColorMatcher.AddColorMatch(kCone);
}

void SubColorSensor::Enable(const bool iEnable)
{
    mIsEnabled = iEnable;
}

void SubColorSensor::Execute()
{
    if (mIsEnabled)
    {
        frc::Color mColor = GetColor();
        double red = mColor.red;
        double green = mColor.green;
        double blue = mColor.blue;

        std::string mColorString;
        if (blue > green && green > red)
        {
            mColorString = "Cube";
        }
        else if (green > red && red > blue)
        {
            mColorString = "Cone";
        }
        else
        {
            mColorString = "Nothing";
        }
        frc::SmartDashboard::PutString("Color", mColorString);
        frc::SmartDashboard::PutNumber("Red", mColor.red);
        frc::SmartDashboard::PutNumber("Green", mColor.green);
        frc::SmartDashboard::PutNumber("Blue", mColor.blue);
    }
}

frc::Color SubColorSensor::GetColor()
{
    return mColorSensor.GetColor();
}

frc::Color SubColorSensor::GetMatchedColor()
{
    double mConfidence = kColorConfidence;
    return mColorMatcher.MatchClosestColor(GetColor(), mConfidence);
}