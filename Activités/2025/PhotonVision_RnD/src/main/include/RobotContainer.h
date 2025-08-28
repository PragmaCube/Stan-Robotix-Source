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

<<<<<<< HEAD:Compets/2025/2025_StanRobotix_FRC/src/main/include/RobotContainer.h

#include "Constants.h"

#include "commands/AlgaePivotUp.h"
#include "commands/AlgaeOuttake.h"
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
=======
#include "subsystems/SubCameraVision.h"
#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubIMU.h"

#include <photon/PhotonCamera.h>
>>>>>>> origin/master:Activités/2025/PhotonVision_RnD/src/main/include/RobotContainer.h


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

/* Enum to be able to change quickly the autonomous phase during competition days.
   You should insert the right item name at line 108 (mAutonomousPhase variable) of this file to change the autonomous
   you want to use and adjust its starting position.
   Warning : the code is made to change the autonomous used and the starting position just by changing line 108 of this file.
   However, if these aren't changed in accordance with each other (which should never happen with this architecture to be clear), 
   what you are going to observe is the robot moving very fast in an unwanted direction with a speed independent from the speed caps you defined.*/
  enum Auto{
    RedLeft, // All these names correspond to autonomous phases used from different starting points. Starting points to which those names refer to.
    RedCenter,
    RedRight,
    BlueLeft,
    BlueCenter,
    BlueRight,
    Test
  };

  frc2::CommandPtr GetAutonomousCommand(Auto);


 private:
  void ConfigureBindings();
  
  // Replace with CommandPS4Controller or CommandJoystick if needed
  frc2::CommandJoystick * m_commandJoystick;
  frc2::CommandXboxController * m_commandXbox;

  // The robot's subsystems are defined here...
<<<<<<< HEAD:Compets/2025/2025_StanRobotix_FRC/src/main/include/RobotContainer.h
  SubDriveTrain * mDriveTrain;

  SubIMU * mIMU;

  SubAlgaePivot * mSubAlgaePivot;
  SubAlgaeIntake * mSubAlgaeIntake;
=======
  ExampleSubsystem m_subsystem;
  SubDriveTrain * mDriveTrain = nullptr;
  SubIMU * mIMU = nullptr;

  SubCameraVision * mSubCameraVision = nullptr;
>>>>>>> origin/master:Activités/2025/PhotonVision_RnD/src/main/include/RobotContainer.h

  SubCoralPivot * mSubCoralPivot;
  SubCoralIntake * mSubCoralIntake;

<<<<<<< HEAD:Compets/2025/2025_StanRobotix_FRC/src/main/include/RobotContainer.h
  SubReefPivot * mSubReefPivot;
  SubReefIntake * mSubReefIntake;

  frc::Joystick * mJoystick;
  frc::XboxController * mJoystickSecondaire;

  frc::ShuffleboardTab * mTabGeneral = &frc::Shuffleboard::GetTab("Main Tab");

  Auto mAutonomousPhase = RedCenter;
=======
  frc::Pose2d PoseInit;
  frc::ShuffleboardTab * mTabGeneral = &frc::Shuffleboard::GetTab("Main Tab");

  photon::PhotonCamera usbCam{"USB_CAM"};
>>>>>>> origin/master:Activités/2025/PhotonVision_RnD/src/main/include/RobotContainer.h
};
