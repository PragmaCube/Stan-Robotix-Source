/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "OI.h"
#include <Subsystems/CordeMoteur.h>
#include <SmartDashboard/SendableChooser.h>
#include <TimedRobot.h>
#include "Preferences.h"
#include <Servo.h>

#include <CameraServer.h>

#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"
#include <cscore_oo.h>

#include <Subsystems/GPS.h>
#include <Subsystems/Actuator.h>

#include <Subsystems/CentrePID.h>
#include <Subsystems/StraightPID.h>
#include <Subsystems/RotationPID.h>

#include <Subsystems/DriveTrain.h>
#include <Subsystems/Vision.h>
#include <Subsystems/HatchPiston.h>

#include <Subsystems/Ventouse.h>


//class Vision;

class Robot : public frc::TimedRobot 
{
 public:
  static DriveTrain m_drivetrain;
  static GPS m_gps; 
  static OI m_oi;
  static Actuator m_actuator;
  static Vision m_vision;
  static Ventouse m_ventouse;
  static HatchPiston m_piston;
  
  static double PIDVal;
  static double PIDP;
  static double PIDI;
  static double PIDD;
  static CordeMoteur m_CordeMoteur;

  static CentrePID* m_CentrePID;
  static StraightPID* m_StraightPID;
  static RotationPID* m_RotationPID;

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
  Preferences* prefs;
};
