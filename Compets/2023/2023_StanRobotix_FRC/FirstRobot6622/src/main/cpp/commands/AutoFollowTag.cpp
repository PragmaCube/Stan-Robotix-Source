// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoFollowTag.h"
#include "../../include/RobotContainer.h"

// AJOUT COMMANDE AUTOMATISEE
AutoFollowTag::AutoFollowTag(RobotContainer * iRobotContainer)
{
    mRobotContainer = iRobotContainer;

    mGenericTimer.Reset();

    EnableSubsystemLog(kLogAutoFollowTagEnable);
    EnablePerformanceLog(kLogPerf_AutoFollowTagEnable);

    Init();
}

void AutoFollowTag::Init()
{
  mSubDriveTrain = mRobotContainer->getSubDriveTrain();
  mSubLimelight = mRobotContainer->getSubLimelight();
  mXController.SetSetpoint(0);
  mYController.SetSetpoint(-1.5);
  mYawController.SetSetpoint(0);
}

void AutoFollowTag::reset()
{
   std :: cout <<  "Fin de l'execution de AutoFollowTag" << std::endl;

   // Ne pas oublier de remettre les variables de la commande automatisee... dans la mesure ou 
   // on risque de la relancer plus tard
}

// Returns true when the command should end.
bool AutoFollowTag::isFinish() {
  return   0 && mXController.AtSetpoint() && mYController.AtSetpoint() && mYawController.AtSetpoint();
}

void AutoFollowTag::doExecute()
{
  mSubLimelight->Execute();      // Ne pas oublier de rajouter les executes de chaque subsysteme entree, telle que Limelight, Ultrason... etc

  double wXOutput = 0.0;
  if(mSubLimelight->getPos(SubLimelight::ePos::eX, SubLimelight::eReferential::eTag) != 0)
  {
    wXOutput = mXController.Calculate(mSubLimelight->getPos(SubLimelight::ePos::eX, SubLimelight::eReferential::eTag));
    // std::cout << mSubLimelight->getPos(SubLimelight::ePos::eYaw, SubLimelight::eReferential::eTag) << std::endl;
  }

  double wYOutput = 0.0;
  if(mSubLimelight->getPos(SubLimelight::ePos::eZ, SubLimelight::eReferential::eTag) != 0)
  {
    wYOutput = mYController.Calculate(mSubLimelight->getPos(SubLimelight::ePos::eZ, SubLimelight::eReferential::eTag));
    // std::cout << mSubLimelight->getPos(SubLimelight::ePos::eY, SubLimelight::eReferential::eTag) << std::endl;
  }

  double wYawOutput = 0.0;
  if(mSubLimelight->getTargetOffsetAngleHorizontal() != 0)
  {
    wYawOutput = mYawController.Calculate(mSubLimelight->getTargetOffsetAngleHorizontal());
    // std::cout << mSubLimelight->getPos(SubLimelight::ePos::eYaw, SubLimelight::eReferential::eTag) << std::endl;
  }

  mSubDriveTrain->setParameters(wXOutput,wYOutput,-wYawOutput,0);
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
