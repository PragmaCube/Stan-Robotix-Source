/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/Solenoid.h>
#include <RobotMap.h>

class Piston : public frc::Subsystem {
 private:
 frc::Solenoid* solenoid0;
 frc::Solenoid* solenoid1;
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  Piston();
  void SetActive();
  void SetInactive();
  void Toggle();
  void InitDefaultCommand() override;
};
