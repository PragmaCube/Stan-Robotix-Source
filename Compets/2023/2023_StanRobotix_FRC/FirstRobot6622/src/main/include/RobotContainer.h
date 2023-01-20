// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once


#include <frc2/command/Command.h>
#include <frc/XboxController.h>
#include <frc/Joystick.h>
#include <frc/Timer.h>
#include <iostream>

#include "subsystems/SubUltrasonic.h"

#include "Constants.h" 

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class RobotContainer 
{
 public:
  RobotContainer();
  
  void Drive();

 private:
  SubUltrasonic* mUltrasonic; 

};
