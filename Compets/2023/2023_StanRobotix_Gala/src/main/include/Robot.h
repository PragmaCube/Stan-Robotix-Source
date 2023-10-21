// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <iostream>

#include <frc/TimedRobot.h>
#include <frc/motorcontrol/VictorSP.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/XboxController.h>
#include <rev/CANSparkMax.h>

#include <frc/shuffleboard/Shuffleboard.h>
#include <networktables/GenericEntry.h>
#include <networktables/NetworkTableInstance.h>
#include <frc/shuffleboard/BuiltInWidgets.h>

#include <subsystems/SubDriveTrain.h>
#include <subsystems/SubArm.h>
#include <subsystems/SubPneumatic.h>


class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void DisabledInit() override;
  void DisabledPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;

  void SimulationInit() override;
  void SimulationPeriodic() override;

  SubDriveTrain mDrive;
  SubGyro mGyro;
  SubArm mArm;
  SubPneumatic mPneumatic;
  
  private : 
  

  frc::XboxController mController{0};
  
  double wLeftY;
  double wLeftX;
  double wRightX;

  bool mManualMode = false;

};
