// // Copyright (c) FIRST and other WPILib contributors.
// // Open Source Software; you can modify and/or share it under the terms of
// // the WPILib BSD license file in the root directory of this project.

#pragma once
// #include <frc2/command/CommandBase.h>
// #include <frc2/command/CommandHelper.h>
#include "time.h"

#include "RobotContainer.h"
#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubArm.h"
#include "subsystems/SubEjector.h"
#include "subsystems/SubIMU.h"
// AJOUT COMMANDE AUTOMATISEE
 class AutoCmd 
 {
 public:
AutoCmd(RobotContainer);

 virtual std::string getName() { return "Autocmd"; }
  
virtual void reset();
virtual void doExecute();
virtual bool isFinish();



private:
enum step_t
{
   Phase1_,
   Phase2_,
   Phase3_,
   Phase4_,
   PhaseFinish
  };

step_t          mCurrentStep = Phase1_;
//   frc::Timer      mGenericTimer;
//   SubDriveTrain * mSubDriveTrain = nullptr;
//   SubLimelight *  mSubLimelight = nullptr;

void Init();

// Definition des phases
void doExecutePhase1();
void doExecutePhase2();
void doExecutePhase3();
void doExecutePhase4();
void doFinish();

bool isPhase1Finished();
bool isPhase2Finished();
bool isPhase3Finished();
bool isPhase4Finished();

frc::Timer mGenericTimer;

SubDriveTrain driveTrain;
SubIMU IMU;
};