/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/ADXRS450_Gyro.h>
#include <frc/BuiltInAccelerometer.h>
#include <frc/AnalogInput.h>
#include <RobotMap.h>

class Senseurs : public frc::Subsystem {
 private:
 frc::AnalogInput* captDist;
 frc::AnalogInput* captDist2;
 frc::ADXRS450_Gyro* gyro;
 frc::BuiltInAccelerometer* accelerometre;
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  Senseurs();
  void InitDefaultCommand() override;
  void Calibrate();
  double GetDist();
  double GetDist2();
  double GetGyro();
  double GetAcceleroX();
  double GetAcceleroY();
};
