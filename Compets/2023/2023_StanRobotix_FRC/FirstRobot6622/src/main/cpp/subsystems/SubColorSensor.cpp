// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubColorSensor.h"

#include <frc/smartdashboard/smartdashboard.h>
#include <iostream>

SubColorSensor::SubColorSensor()
{
  mColorMatcher.AddColorMatch(kCube);
  mColorMatcher.AddColorMatch(kCone);

  Enable(kColorDetectionEnabled);
  EnableSubsystemLog(kLogColorDetection);
}

void SubColorSensor::Init()
{
  if (isEnabled())
  {
    mColorSensor = new rev::ColorSensorV3(frc::I2C::Port::kOnboard);
  }
}

void SubColorSensor::doExecute()
{
  if (isEnabled())
  {
    frc::Color wColor = GetColor();
    double wRed = wColor.red;
    double wGreen = wColor.green;
    double wBlue = wColor.blue;

    std::string wColorString;
    if (wBlue > wGreen && wGreen > wRed)
    {
      wColorString = "Cube";
    }
    else if (wGreen > wRed && wRed > wBlue)
    {
      wColorString = "Cone";
    }
    else
    {
      wColorString = "Nothing";
    }
    frc::SmartDashboard::PutString("Color", wColorString);
    frc::SmartDashboard::PutNumber("Red", wRed);
    frc::SmartDashboard::PutNumber("Green", wGreen);
    frc::SmartDashboard::PutNumber("Blue", wBlue);

    if (timeToDisplaySystemLog())

    {
      std::cout << "ColorSensor\nR : " << wRed << "    G : " << wGreen << "    B : " << wBlue << std::endl;
    }
  }
}

frc::Color SubColorSensor::GetColor()
{
  return mColorSensor->GetColor();
}

frc::Color SubColorSensor::GetMatchedColor()
{
  double mConfidence = kColorConfidence;
  return mColorMatcher.MatchClosestColor(GetColor(), mConfidence);
}