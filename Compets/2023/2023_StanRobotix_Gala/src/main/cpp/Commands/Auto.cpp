// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Commands/Auto.h"

Auto::Auto(frc::MecanumDrive iDrive) {
  mDrive = &iDrive;
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void Auto::Initialize() 
{
  frc::Timer mTimer;
}

// Called repeatedly when this Command is scheduled to run
void Auto::Execute() {
  switch (mCurrentStep)
  {
    case Phase1_:
      mDrive->DriveCartesian(-mY, 0.0, mTwist);
      mTimer.Start();
      if (mCompteur < 4)
      {
        if (mTimer.Get() >= 0.5_s)
        {
          mCurrentStep = Phase2_;
          mCompteur += 1;
          mY *= -1.0;
        }
      }
      else
      {
        doFinish();
      }
      break;
    case Phase2_:
      mDrive->DriveCartesian(0.0, mX, mTwist);
      mTimer.Start();
      if (mCompteur < 4)
      {
        if (mTimer.Get() >= 0.5_s)
        {
          mCurrentStep = Phase1_;
          mCompteur += 1;
          mX *= -1.0;
        }
      }
      else
      {
        doFinish();
      }
      break;
  };
}


void Auto::doFinish() {}


// Called once the command ends or is interrupted.
void Auto::End(bool interrupted) {}

// Returns true when the command should end.
bool Auto::IsFinished() {
  return false;
}
