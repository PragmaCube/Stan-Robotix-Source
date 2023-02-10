/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include <Servo.h>

class Actuator : public frc::Subsystem {
 private:

  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  Servo * mActuator;
 public:
  Actuator();
  void InitDefaultCommand() override;
  void MoveDelta(double distance);
};
