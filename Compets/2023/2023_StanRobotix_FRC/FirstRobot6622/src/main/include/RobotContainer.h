// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc/XboxController.h>
#include <frc/XboxController.h>
#include <frc/Timer.h>

#include "subsystems/SubDriveTrain.h"

#include "Constants.h" 
/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer
{
public:
  RobotContainer();

 
  void Drive();
  void Auto();

private:

  frc::XboxController mController{kJoystickPort};
  SubDriveTrain *mDriveTrain;
  SubDriveTrain::MotorSpeed mMotorSpeed[3];


  int mMotorIndex;

  bool mSmart = 0 ;
  void ConfigureButtonBindings();
  void DriveDisplacement();

};
