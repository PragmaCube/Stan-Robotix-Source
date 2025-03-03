// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>
#include <frc/Joystick.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubAlgaePivot.h"
#include "subsystems/SubCoralPivot.h"
#include "subsystems/SubAlgaeIntake.h"
#include "subsystems/SubCoralIntake.h"

#include "commands/AlgaePivotDown.h"
#include "commands/AlgaePivotUp.h"
#include "commands/AlgaeIntakeIn.h"
#include "commands/AlgaeIntakeOut.h"
#include "commands/CoralIntake.h"
#include "commands/CoralOuttake.h"
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <networktables/NetworkTableEntry.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include "commands/TestShuffleBoard.h"


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
  frc2::CommandPtr GetAutonomousCommand();


 private:

  // Replace with CommandPS4Controller or CommandJoystick if needed
  frc2::CommandXboxController m_driverController{
      OperatorConstants::kDriverControllerPort};

  // The robot's subsystems are defined here...
  ExampleSubsystem m_subsystem;
  SubDriveTrain * mDriveTrain = nullptr;
  SubIMU * mIMU = nullptr;
  SubAlgaePivot * mSubAlgaePivot = nullptr;
  SubAlgaeIntake * mSubAlgaeIntake = nullptr;
  SubCoralPivot * mSubCoralPivot = nullptr;
  SubCoralIntake * mSubCoralIntake = nullptr;
  TestShuffleBoard * mTestShuffleBoard = nullptr;
  frc::Joystick * mJoystick = nullptr;

  void ConfigureBindings();

  frc::ShuffleboardTab &mTabGeneral = frc::Shuffleboard::GetTab("Main Tab");
/*
  //Commandes
  frc::SuppliedValueWidget<bool> mCmdAlgaeFullIntake = ;
  frc::SuppliedValueWidget<bool> mCmdAlgaeIntakeIn = ;
  frc::SuppliedValueWidget<bool> mCmdAlgaeIntakeOut = ;
  frc::SuppliedValueWidget<bool> mCmdAlgaePivotDown = ;
  //frc::SuppliedValueWidget<bool> mCmdAlgaePivotState = ;
  frc::SuppliedValueWidget<bool> mCmdAlgaePivotUp = ;
  frc::SuppliedValueWidget<bool> mCmdAutos = ;
  frc::SuppliedValueWidget<bool> mCmdClimb = ;
  frc::SuppliedValueWidget<bool> mCmdCoralIntake = ;
  frc::SuppliedValueWidget<bool> mCmdCoralOuttake = ;
  frc::SuppliedValueWidget<bool> mCmdCoralPivotDown = ;
  frc::SuppliedValueWidget<bool> mCmdCoralPivotUp = ;
  frc::SuppliedValueWidget<bool> mCmdGoToTag = ;
  frc::SuppliedValueWidget<bool> mCmdStopAlgaeIntake = ;
  frc::SuppliedValueWidget<bool> mCmdStopCoralIntake = ;
  */
  frc::SuppliedValueWidget<bool> &mCmdTestShuffleBoard = mTabGeneral.AddBoolean("mTestShuffleBoard",[this]{return mTestSuffleBoard->IsFinished();}).WithWidget(frc::BuiltInWidgets::kBooleanBox);

  //Valeurs non modifiables
  nt::GenericEntry * NumberTestConstant = mTabGeneral.Add("turc", 0.5).WithWidget(frc::BuiltInWidgets::kDial).GetEntry();

  //Valeurs modifiables
  nt::GenericEntry * NumberTestChangeable = mTabGeneral.Add("turc modifiable", 0.5).WithWidget(frc::BuiltInWidgets::kNumberSlider).GetEntry();
  /*
  nt::GenericEntry AlgaeIntakeSpeed = ;
  nt::GenericEntry AlgaeOuttakeSpeed = ;
  nt::GenericEntry AlgaeSetPoint = ;
  nt::GenericEntry AlgaekG = ;
  nt::GenericEntry AlgaeClimb = ;
  nt::GenericEntry AlgaeStayStill = ;
  nt::GenericEntry CoralIntakeSpeed = ;
  nt::GenericEntry CoralOuttakeSpeed = ;
  nt::GenericEntry CoralPivotSetPoint = ;
  nt::GenericEntry CoralPivotkG = ;
*/
  //Capteurs
  frc::ComplexWidget * CameraFeed = &mTabGeneral.AddCamera("cameras","Limelight + usb",std::span<const std::string>({ "http://10.66.22.11:5800/" })).WithWidget(frc::BuiltInWidgets::kCameraStream);


  //Commandes pour isFinished
  TestShuffleBoard * mTestSuffleBoard = nullptr;
};
