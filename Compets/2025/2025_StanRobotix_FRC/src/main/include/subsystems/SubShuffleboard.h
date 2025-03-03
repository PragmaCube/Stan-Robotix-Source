// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

#include <frc/shuffleboard/ShuffleboardTab.h>
#include <networktables/NetworkTableEntry.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include "commands/TestShuffleBoard.h"

/*
#include "commands/AlgaeFullIntake.h"
#include "commands/AlgaeIntakeIn.h"
#include "commands/AlgaeIntakeOut.h"
#include "commands/AlgaePivotDown.h"
#include "commands/Autos.h"
#include "commands/Climb.h"
#include "commands/CoralIntake.h"
#include "commands/CoralOuttake.h"
#include "commands/CoralPivotDown.h"
#include "commands/CoralPivotUp.h"
#include "commands/GoToTag.h"
#include "commands/StopAlgaeIntake.h"
#include "commands/StopCoralIntake.h"

#include "subsystems/SubAlgaeIntake.h"
#include "subsystems/SubCoralIntake.h"
#include "subsystems/SubCoralPivot.h"
#include "subsystems/SubAlgaePivot.h"
*/

class SubShuffleboard : public frc2::SubsystemBase {
 public:
  SubShuffleboard();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  double GetNumberTestChangeable();

  double GetNumberTestConstant();


 private:
  // tabs
  frc::ShuffleboardTab* mTabGeneral;

  //Commandes
  frc::SuppliedValueWidget<bool>* mCmdAlgaeFullIntake = nullptr;
  frc::SuppliedValueWidget<bool>* mCmdAlgaeIntakeIn = nullptr;
  frc::SuppliedValueWidget<bool>* mCmdAlgaeIntakeOut = nullptr;
  frc::SuppliedValueWidget<bool>* mCmdAlgaePivotDown = nullptr;
  //frc::SuppliedValueWidget<bool>* mCmdAlgaePivotState = nullptr;
  frc::SuppliedValueWidget<bool>* mCmdAlgaePivotUp = nullptr;
  frc::SuppliedValueWidget<bool>* mCmdAutos = nullptr;
  frc::SuppliedValueWidget<bool>* mCmdClimb = nullptr;
  frc::SuppliedValueWidget<bool>* mCmdCoralIntake = nullptr;
  frc::SuppliedValueWidget<bool>* mCmdCoralOuttake = nullptr;
  frc::SuppliedValueWidget<bool>* mCmdCoralPivotDown = nullptr;
  frc::SuppliedValueWidget<bool>* mCmdCoralPivotUp = nullptr;
  frc::SuppliedValueWidget<bool>* mCmdGoToTag = nullptr;
  frc::SuppliedValueWidget<bool>* mCmdStopAlgaeIntake = nullptr;
  frc::SuppliedValueWidget<bool>* mCmdStopCoralIntake = nullptr;
  frc::SuppliedValueWidget<bool>* mCmdTestShuffleBoard = nullptr;

  //Valeurs non modifiables
  nt::GenericEntry* NumberTestConstant = nullptr;

  //Valeurs modifiables
  nt::GenericEntry* NumberTestChangeable = nullptr;
  nt::GenericEntry* AlgaeIntakeSpeed = nullptr;
  nt::GenericEntry* AlgaeOuttakeSpeed = nullptr;
  nt::GenericEntry* AlgaeSetPoint = nullptr;
  nt::GenericEntry* AlgaekG = nullptr;
  nt::GenericEntry* AlgaeClimb = nullptr;
  nt::GenericEntry* AlgaeStayStill = nullptr;
  nt::GenericEntry* CoralIntakeSpeed = nullptr;
  nt::GenericEntry* CoralOuttakeSpeed = nullptr;
  nt::GenericEntry* CoralPivotSetPoint = nullptr;
  nt::GenericEntry* CoralPivotkG = nullptr;

  //Capteurs
  frc::ComplexWidget* CameraFeed = nullptr;


  //Commandes pour isFinished
  TestShuffleBoard * mTestSuffleBoard = nullptr;
/*
  AlgaeFullIntake * mAlgaeFullIntake = nullptr;
  AlgaeIntakeIn * mAlgaeIntakeIn = nullptr;
  AlgaeIntakeOut * mAlgaeIntakeOut = nullptr;
  AlgaePivotDown * mAlgaePivotDown = nullptr;
  AlgaePivotDown * mAlgaePivotUp = nullptr;
  Autos * mAutos = nullptr;
  Climb * mClimb = nullptr;
  CoralIntake * mCoralIntake = nullptr;
  CoralOuttake * mCoralOuttake = nullptr;
  CoralPivotDown * mCoralPivotDown = nullptr;
  CoralPivotUp * mCoralPivotUp = nullptr;
  GoToTag * mGoToTag = nullptr;
  StopAlgaeIntake * mStopAlgaeIntake = nullptr;
  StopCoralIntake * mStopCoralIntake = nullptr;
*/

  //Subsystems
/*
  SubAlgaeIntake * mSubAlgaeIntake = nullptr;
  SubCoralIntake * mSubCoralIntake = nullptr;
  SubCoralPivot * mSubCoralPivot = nullptr;
  SubAlgaePivot * mSubAlgaePivot = nullptr;
*/
};
