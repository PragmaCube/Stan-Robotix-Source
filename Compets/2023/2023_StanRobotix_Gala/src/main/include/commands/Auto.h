// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "Constants.h"
#include <frc/Timer.h>

#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubGyro.h"

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
    Auto();

    void Initialize() override;

    void Execute() override;

    void doFinish();

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

    double mAbscisse, mOrdonnee = 1.0;
    double mTwiste = 0.0;

    SubDriveTrain mDrive;
    SubGyro mGyro;
    frc::Timer mTimer;
};

