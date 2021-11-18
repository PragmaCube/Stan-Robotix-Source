/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include "Camera.h"

class SubsystemCamera : public frc::Subsystem {
 private:
  grip::Camera mCamera;

 public:
  SubsystemCamera();
  void InitDefaultCommand() override;
  std::vector<grip::Line>* getLines();
};
