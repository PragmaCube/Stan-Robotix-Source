/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/PIDSubsystem.h>

class LinearPID : public frc::PIDSubsystem {
 private:
  double mOutput; 

 public:
  LinearPID(double targetDist);
  double ReturnPIDInput() override;
  double ReturnPIDOutput();
  void UsePIDOutput(double output) override;
  void InitDefaultCommand() override;
};
