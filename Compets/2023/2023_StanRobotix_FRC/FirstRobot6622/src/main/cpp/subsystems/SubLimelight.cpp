// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubLimelight.h"

#include <frc/smartdashboard/smartdashboard.h>

#include <iostream>

SubLimelight::SubLimelight()
{
  Enable(kLimelightEnabled);
  EnablePerformanceLog(kLogPerf_LimelightEnable);
  EnableSubsystemLog(kLogLimelight);
}

void SubLimelight::Enable(const bool iEnable)
{
  mIsEnabled = iEnable;
}


void SubLimelight::Init() 
{ 
  if (mIsEnabled)
  {
     mNetworkTable = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
  }
}

void SubLimelight::doExecute()
{
  static int tempCount = 0; // TODO: get rid of this

  if (mIsEnabled)
  {
    mTargetOffsetAngle_Horizontal = mNetworkTable->GetNumber("tx", 0.0);
    mTargetOffsetAngle_Vertical = mNetworkTable->GetNumber("ty", 0.0);
    mTargetArea = mNetworkTable->GetNumber("ta", 0.0);
    mTargetSkew = mNetworkTable->GetNumber("ts", 0.0);
  }

  if (mSubsystemLogEnabled && tempCount %50 == 0)
  {
    std::cout << "\nTargetOffsetAngle Hz(tx):" << mTargetOffsetAngle_Horizontal
              << "\nTargetOffsetAngle Vt(ty):" << mTargetOffsetAngle_Vertical
              << "\nTargetArea (ta):" << mTargetArea
              << "\nTargetSkew (ts):" << mTargetSkew << std::endl;
  }

  tempCount++;
}