/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <RobotMap.h>

#include "Commands/Subsystem.h"

#include <ADXRS450_Gyro.h>
#include <BuiltInAccelerometer.h>

#include <Encoder.h>

#include <Math.h>

#include <AnalogInput.h>

class GPS : public frc::Subsystem 
{
 private:
  
  frc::ADXRS450_Gyro * mGyroPtr;
  frc::BuiltInAccelerometer * mAcceleroPtr;

  Encoder *mRightEncoder;
  Encoder *mLeftEncoder;

  AnalogInput* mDistCaptPtr;

 public:
  GPS();
  void InitDefaultCommand() override;
  
  void ResetSensors(); 
  
  double GetAngle();

  double GetXAcceleration();
  double GetYAcceleration();
  double GetZAcceleration();
  double GetAcceleration();

  double GetEncoderDistance();
  double GetCapteurDistance();
};
