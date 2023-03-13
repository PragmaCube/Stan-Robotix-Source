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

  setLogPeriodity(kLogPeriod_1s);
}

void SubLimelight::Init() 
{ 
  if (isEnabled())
  {
     mNetworkTable = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
     mNetworkTable->PutNumber("ledMode",3); // TODO: 3 signification ? rajouter enum
  }
}

void SubLimelight::doExecute()
{
  if (isEnabled())
  {
    mTargetOffsetAngle_Horizontal = mNetworkTable->GetNumber("tx", 0.0);
    mTargetOffsetAngle_Vertical = mNetworkTable->GetNumber("ty", 0.0);
    mTargetArea = mNetworkTable->GetNumber("ta", 0.0);
    mTargetSkew = mNetworkTable->GetNumber("ts", 0.0);

    mFieldBotPos = mNetworkTable->GetNumberArray("botpose",std::vector<double>(6));
    mTagBotPos   = mNetworkTable->GetNumberArray("botpose_targetspace", std::vector<double>(6));
  }

  if (timeToDisplaySystemLog())
  {
    std::cout << "\nTargetOffsetAngle Hz(tx):" << mTargetOffsetAngle_Horizontal
              << "\nTargetOffsetAngle Vt(ty):" << mTargetOffsetAngle_Vertical
              << "\nTargetArea (ta):" << mTargetArea
              << "\nTargetSkew (ts):" << mTargetSkew << std::endl;
    std::cout << "\nFieldBotPos(botpose): { "; 

    for (int i = 0 ; i < mFieldBotPos.size() ; i++ )
    {
      std::cout << mFieldBotPos[i] << ", ";
    }

    std::cout << "} \n";
    
    std::cout << "\nTagBotPos(botpose_targetspace): { ";
    for (int i = 0 ; i < mTagBotPos.size() ; i++ )
    {
      std::cout << mTagBotPos[i] << ", ";
    }
    std::cout << "} \n"
    << std::endl;
  }
}

double SubLimelight::getPos(ePos iPos, eReferential iReferential)
{
  switch(iReferential)
  {
    case eField:
      return mFieldBotPos[iPos];

    case eTag:
      return mTagBotPos[iPos];

    default:
      break;
  };
  return 0.0;
}