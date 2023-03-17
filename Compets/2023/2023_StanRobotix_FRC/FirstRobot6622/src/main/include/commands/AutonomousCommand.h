// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubUltrasonic.h"
#include "subsystems/SubIMU.h"

class RobotContainer;

class AutonomousCommand
    : public frc2::CommandHelper<frc2::CommandBase, AutonomousCommand>
{
private:
  enum step_t
  {
    Phase1_1_,
    Phase1_2_,
    Phase1_3_,
    Phase2_s1_,
    Phase2_s2_,
    Phase2_s3_,
    Phase3_s1_,
    Phase3_s2_,
    Phase3_s3_,
    Phase4_s1_s3,
    Phase4_s2,
    PhaseFinish
  };
  step_t mCurrentStep;

  enum senario_t
  {
    Senario1,
    Senario2,
    Senario3
  };
  senario_t mCurrentSenario; 

public:
  /**
   * Creates a new ExampleCommand.
   *
   * @param subsystem The subsystem used by this command.
   */
  explicit AutonomousCommand(RobotContainer *iRobotContainer);

  void setSubsystem(SubDriveTrain *pDriveTrain /*,SubIMU * pIMU*/);

  void Init();
  void Execute();
  void End(bool interrupted);

  void doExecutePhase1_1();
  void doExecutePhase1_2();
  void doExecutePhase1_3();
  void doExecutePhase2_s1();
  void doExecutePhase2_s2();
  void doExecutePhase2_s3();
  void doExecutePhase3_s1();
  void doExecutePhase3_s2();
  void doExecutePhase3_s3();
  void doExecutePhase4_s1_s3();
  void doExecutePhase4_s2();
  void doFinish();

  bool isPhase1_1Finished();
  bool isPhase1_2Finished();
  bool isPhase1_3Finished();
  bool isPhase2_s1Finished();
  bool isPhase2_s2Finished();
  bool isPhase2_s3Finished();
  bool isPhase3_s1Finished();
  bool isPhase3_s2Finished();
  bool isPhase3_s3Finished();
  bool isPhase4_s1_s3Finished();
  bool isPhase4_s2Finished();
  void doExecuteSenario1();
  void doExecuteSenario2();
  void doExecuteSenario3();

  bool isSenario1Finished();
  bool isSenario2Finished();
  bool isSenario3Finished();

private:
  frc::Timer mGenericTimer;
  RobotContainer *mRobotContainer;

  SubDriveTrain *m_pDriveTrain = nullptr;
  SubUltrasonic *m_pUltrasonic = nullptr;
  SubIMU *m_pIMU = nullptr;
};
