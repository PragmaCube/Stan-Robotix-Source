// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoFollowTag.h"
#include "../../include/RobotContainer.h"

AutoFollowTag::AutoFollowTag(RobotContainer * iRobotContainer)
{
    mRobotContainer = iRobotContainer;

    mGenericTimer.Reset();

    EnableSubsystemLog(kLogAutoFollowTagEnable);
    EnablePerformanceLog(kLogPerf_AutoFollowTagEnable);
    Init();
  }

// Returns true when the command should end.
bool AutoFollowTag::isFinish() {
  return   0 && mXController.AtSetpoint() && mYController.AtSetpoint() && mYawController.AtSetpoint();
}

void AutoFollowTag::reset()
{
   std :: cout <<  "Fin de l'execution de AutoFollowTag" << std::endl;
}

void AutoFollowTag::Init()
{
  mSubDriveTrain = mRobotContainer->getSubDriveTrain();
  mSubLimelight = mRobotContainer->getSubLimelight();
  mXController.SetSetpoint(0);
  mYController.SetSetpoint(-1.5);
  mYawController.SetSetpoint(0);
}

void AutoFollowTag::doExecute()
{
  mSubLimelight->Execute();

  double mXOutput;
  if(mSubLimelight->getPos(SubLimelight::ePos::eX, SubLimelight::eReferential::eTag) != 0)
  {
    mXOutput = mXController.Calculate(mSubLimelight->getPos(SubLimelight::ePos::eX, SubLimelight::eReferential::eTag));
    // std::cout << mSubLimelight->getPos(SubLimelight::ePos::eYaw, SubLimelight::eReferential::eTag) << std::endl;
  }
  else
  {
    mXOutput = 0;
  }

  double mYOutput;
  if(mSubLimelight->getPos(SubLimelight::ePos::eZ, SubLimelight::eReferential::eTag) != 0)
  {
    mYOutput = mYController.Calculate(mSubLimelight->getPos(SubLimelight::ePos::eZ, SubLimelight::eReferential::eTag));
    // std::cout << mSubLimelight->getPos(SubLimelight::ePos::eY, SubLimelight::eReferential::eTag) << std::endl;
  }
  else
  {
    mYOutput = 0;
  }

  double mYawOutput;
  if(mSubLimelight->getTargetOffsetAngleHorizontal() != 0)
  {
    mYawOutput = mYawController.Calculate(mSubLimelight->getTargetOffsetAngleHorizontal());
    // std::cout << mSubLimelight->getPos(SubLimelight::ePos::eYaw, SubLimelight::eReferential::eTag) << std::endl;
  }
  else
  {
    mYawOutput = 0;
  }

  mSubDriveTrain->setParameters(mXOutput,mYOutput,-mYawOutput,0);
  mSubDriveTrain->Execute();
  
  if(mXController.AtSetpoint() && mYController.AtSetpoint() && mYawController.AtSetpoint())
  {
    if(mXController.GetSetpoint() == 0)
    {
      mXController.SetSetpoint(1.80);
      mYController.SetSetpoint(-1.90);
      mYawController.SetSetpoint(0);
    }
    else
    {
      mXController.SetSetpoint(0);
      mYController.SetSetpoint(-1.5);
      mYawController.SetSetpoint(0);
    }
  }

}
