// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Auto.h"

Auto::Auto() {
  // Use addRequirements() here to declare subsystem dependencies.
}

// // Called when the command is initially scheduled.
void Auto::Initialize() 
{
  frc::Timer mTimer;
}

// Called repeatedly when this Command is scheduled to run
void Auto::Execute() 
{
  switch (mCurrentStep)
  {
    case Phase1_:
      mDrive.drive(mOrdonnee, 0.0, 0.0);
      mTimer.Start();

      if (mCompteur < 4)
      {
        if (mTimer.Get() >= 0.5_s)
        {
          mCurrentStep = Phase2_;
          mCompteur += 1;
          mOrdonnee *= -1.0;
        }
      }

      else
      {
        doFinish();
      }

      break;

    case Phase2_:
      mDrive.drive(0.0, mAbscisse, 0.0);
      mTimer.Start();

      if (mCompteur < 4)
      {
        if (mTimer.Get() >= 0.5_s)
        {
          mCurrentStep = Phase1_;
          mCompteur += 1;
          mAbscisse *= -1.0;
        }
      }

      else
      {
        doFinish();
      } 

      break;
  };
}
// Called once the command ends or is interrupted.
void Auto::End(bool interrupted) {}

// Returns true when the command should end.
bool Auto::IsFinished() {
  return false;
}

void Auto::doFinish() {}