// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/Joystick.h> 
#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>
#include <frc2/command/button/Trigger.h>
#include <frc/controller/PIDController.h>

#include "subsystems/ExampleSubsystem.h"
#include "subsystems/SubEjector.h"
#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubIMU.h"
#include "subsystems/SubElevator.h"

#include "commands/ExampleCommand.h"
#include "commands/GoToTag.h"
#include "commands/TurnLeft.h"
#include "commands/Autos.h"
#include "commands/ElevatorUp.h"
#include "commands/ElevatorMiddle.h"
#include "commands/ElevatorDown.h"
#include "commands/Amplificateur.h"
#include "commands/PosStorage.h"
#include "commands/PivotUp.h"
#include "commands/PivotMiddle.h"
#include "commands/PivotDown.h"
#include "commands/Pickup.h"
#include "commands/TrapDown.h"
#include "commands/TrapUp.h"
#include "commands/Automatisation.h"
#include "commands/Avancer.h"
#include "commands/EjectorIn.h"
#include "commands/EjectorOut.h"

#include "LimelightHelpers.h" 
#include "Constants.h"


/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and trigger mappings) should be declared here... ......
 */
class RobotContainer {
 public:

  RobotContainer();

  frc2::CommandPtr GetAutonomousCommand();

  void drive();
  void MoveElevator();
  void MoveEjector();

 private:

  
  // Replace with CommandPS4Controller or CommandJoystick if needed
  frc2::CommandXboxController m_driverController{OperatorConstants::kDriverControllerPort};

  // The robot's subsystems are defined here...
  SubEjector mEjector;
  SubElevator mElevator;
  SubPivot mPivot;
  SubDriveTrain mDriveTrain;
  SubIMU mIMU;
  frc::Joystick mJoystick{0};

  void Init();
  void ConfigureBindings();
};