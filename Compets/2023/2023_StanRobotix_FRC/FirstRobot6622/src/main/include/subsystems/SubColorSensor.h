// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"

#include "Constants.h"

class SubColorSensor : public frc2::SubsystemBase
{
public:
  static constexpr frc::Color kCone = frc::Color(0.360, 0.569, 0.070); // couleur du Cone 0.34 R, 0.54 G, 0.10 B
  static constexpr frc::Color kCube = frc::Color(0.200, 0.327, 0.473); // couleur du Cube 0.22 R, 0.41 G, 0.36 B
  static constexpr double kColorConfidence = 0.0;                      // intervalle de confiance pour la couleur

public:
  SubColorSensor();

  void Enable(const bool iEnable);
  void EnableSubsystemLog(const bool iEnable);

  void Execute();

  frc::Color GetColor();

  frc::Color GetMatchedColor();

private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  rev::ColorSensorV3 mColorSensor{frc::I2C::Port::kOnboard};
  rev::ColorMatch mColorMatcher;

  bool mIsEnabled = false;
  bool mSubsystemLogEnabled = false;
};
