// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/button/CommandJoystick.h>
#include <frc2/command/button/CommandXboxController.h>
#include <frc2/command/CommandPtr.h>
#include <frc/Joystick.h>

#include <pathplanner/lib/commands/PathPlannerAuto.h>
#include <pathplanner/lib/auto/AutoBuilder.h>
#include <pathplanner/lib/auto/NamedCommands.h>

#include <frc2/command/Command.h>
#include <memory>

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardTab.h>


#include "Constants.h"

#include "commands/AlgaePivotUp.h"
#include "commands/AlgaeIntakeOut.h"
#include "commands/AlgaeFullIntake.h"

#include "commands/CoralOuttake.h"
#include "commands/CoralPivotUp.h"
#include "commands/CoralFullIntake.h"

#include "commands/ReefPivotUp.h"
#include "commands/ReefPivotDown.h"
#include "commands/ManualReefPivot.h"

#include "commands/Climb.h"
#include "commands/ClimbPivotUp.h"

#include "commands/AutoCoralDown.h"

#include "commands/GoToTag.h"
#include "commands/SequentialGoToTag.h"


/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and trigger mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  void periodic();
  void Initialize();

/* Enum to be able to change quicky the autonomous phase during competition days.
   You should insert the right item name at line 43 of the Robot.cpp to change the autonomous phase you want to use. 
   Warning : you also need to change line 97 of the SubDriveTrain.h consequently for the robot to understand that he is at the right starting position.
   If you do not do so, the robot will try to reach the position where he needs to be from the wrong position where he thinks he is.
   What you would then observe is the robot moving very fast in an unwanted direction independently from the chosen max speed. */
  enum Auto{
    RougeGauche, // All these names correspond to autonomous phases used from different starting points. Starting points to which those names refer to.
    RougeCentre,
    RougeDroite,
    BleuGauche,
    BleuCentre,
    BleuDroite,
    Test
  };

  frc2::CommandPtr GetAutonomousCommand(Auto);


 private:
  void ConfigureBindings();
  
  // Replace with CommandPS4Controller or CommandJoystick if needed
  frc2::CommandJoystick * m_commandJoystick;
  frc2::CommandXboxController * m_commandXbox;

  // Build an auto chooser. This will use frc2::cmd::None() as the default option.
  frc::SendableChooser<frc2::Command *> autoChooser;

  // The robot's subsystems are defined here...
  SubDriveTrain * mDriveTrain;

  SubIMU * mIMU;

  SubAlgaePivot * mSubAlgaePivot;
  SubAlgaeIntake * mSubAlgaeIntake;

  SubCoralPivot * mSubCoralPivot;
  SubCoralIntake * mSubCoralIntake;

  SubReefPivot * mSubReefPivot;

  frc::Joystick * mJoystick;
  frc::XboxController * mJoystickSecondaire;

  frc::ShuffleboardTab * mTabGeneral = &frc::Shuffleboard::GetTab("Main Tab");
};
