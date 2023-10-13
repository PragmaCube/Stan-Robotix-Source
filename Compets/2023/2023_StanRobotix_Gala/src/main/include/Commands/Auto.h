// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/drive/DifferentialDrive.h>
#include <Constants.h>
#include <frc/Timer.h>
#include "Robot.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class Auto
    : public frc2::CommandHelper<frc2::CommandBase, Auto> 
{
  public:
    Auto(frc::MecanumDrive iDrive);

    void Initialize() override;

    void Execute() override;

    void End(bool interrupted) override;

    bool IsFinished() override;
  private:
    enum step_t
    {
      Phase1_,
      Phase2_
    };
    step_t mCurrentStep;

    int mCompteur = 0;

    void doExecute(step_t iPhase);

    void doFinish();

    double mX, mY = 1.0;
    double mTwist = 0;

    frc::MecanumDrive *mDrive;
    frc::Timer mTimer;

    
};

