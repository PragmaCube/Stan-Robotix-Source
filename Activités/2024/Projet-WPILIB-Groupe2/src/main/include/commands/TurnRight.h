// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/controller/PIDController.h>
#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubIMU.h"
#include "RobotContainer.h"
#include "Constants.h"
#include <networktables/GenericEntry.h>
#include <frc/kinematics/MecanumDriveWheelSpeeds.h>
#include <frc/controller/SimpleMotorFeedforward.h>
#include <frc/kinematics/MecanumDriveKinematics.h>
#include <frc/kinematics/MecanumDriveOdometry.h>



/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class TurnRight
    : public frc2::CommandHelper<frc2::Command, TurnRight> {
 public:
  TurnRight(SubDriveTrain* iDriveTrain, SubIMU* iIMU);
  
  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

private:
  SubDriveTrain* mDriveTrain;
  SubIMU* mIMU;
  float angleDebut;
  

  frc::PIDController mPIDController {PIDConstants::kTurnP, PIDConstants::kTurnI, PIDConstants::kTurnD};
  double Output;

nt::GenericEntry* mCoefP = nullptr;
nt::GenericEntry* mCoefI = nullptr;
nt::GenericEntry* mCoefD = nullptr;


frc::SimpleMotorFeedforward<units::meters> m_feedforward{1_V, 3_V / 1_mps};
};
