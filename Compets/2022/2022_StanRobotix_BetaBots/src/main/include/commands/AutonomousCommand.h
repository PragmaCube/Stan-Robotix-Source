// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/SubEjector.h"
#include "subsystems/SubDriveTrain.h"
#include "subsystems/subClimber.h"
#include "subsystems/SubIMU.h"

class AutonomousCommand
    : public frc2::CommandHelper<frc2::CommandBase, AutonomousCommand> {
 private:
   typedef enum step_t { Phase1_, Phase2_, phase3_, Phase4_, PhaseFinish };
   step_t mCurrentStep;

 public:
  /**
   * Creates a new ExampleCommand.
   *
   * @param subsystem The subsystem used by this command.
   */
  explicit AutonomousCommand();
  
  void setSubsystem(SubEjector* pEjector, SubDriveTrain * pDriveTrain, SubClimber * pClimber, SubIMU * pIMU);

   void Initialize();
   void Execute();
   void End(bool interrupted);

   void doExecutePhase1();
   void doExecutePhase2();
   void doExecutePhase3();
   void doExecutePhase4();
   void doFinish();

   bool isPhase1Finished();
   bool isPhase2Finished();
   bool isPhase3Finished();
   bool isPhase4Finished();

 private:
   SubClimber::eHeight m_Height[4];

   SubEjector* m_pEjectorSubsystem;
   SubDriveTrain * m_pDriveTrain;
   SubClimber * m_pClimber;
   SubIMU * m_pIMU;
};
