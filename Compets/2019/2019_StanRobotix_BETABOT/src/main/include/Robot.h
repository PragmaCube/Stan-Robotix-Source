/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/TimedRobot.h>
#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "OI.h"
#include "commands/ExampleCommand.h"
#include "commands/MyAutoCommand.h"
#include "subsystems/ExampleSubsystem.h"
#include <subsystems/DriveTrain.h>
#include <subsystems/Piston.h>
#include <subsystems/Senseurs.h>

#include <frc/Preferences.h>

#include <commands/Autonome.h>

class Robot : public frc::TimedRobot {
 public:
  static ExampleSubsystem m_subsystem;
  static OI m_oi;
  static DriveTrain m_driveTrain;
  static Piston m_piston;
  static Senseurs m_senseurs;

  static bool wallLeft;

  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  frc::Command* m_autonomousCommand = nullptr;
  Autonome m_defaultAuto;
  MyAutoCommand m_myAuto;
  frc::SendableChooser<frc::Command*> m_chooser;
  frc::Preferences* prefs;
};
