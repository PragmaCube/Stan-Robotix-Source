// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoFollowTape.h"
#include "../../include/RobotContainer.h"

// AJOUT COMMANDE AUTOMATISEE
AutoFollowTape::AutoFollowTape(RobotContainer * iRobotContainer)
{
    mRobotContainer = iRobotContainer;

    mGenericTimer.Reset();

    EnableSubsystemLog(kLogAutoFollowTapeEnable);
    EnablePerformanceLog(kLogPerf_AutoFollowTapeEnable);

    Init();
}

void AutoFollowTape::Init()
{
  mSubDriveTrain = mRobotContainer->getSubDriveTrain();
  mSubLimelight = mRobotContainer->getSubLimelight();
  mAlignController.SetSetpoint(0);
  mDistanceController.SetSetpoint(1.5);
  mYawController.SetSetpoint(0);
}

void AutoFollowTape::reset()
{
   std :: cout <<  "Fin de l'execution de AutoFollowTape" << std::endl;
   mCorrectPipeline_QuestionMark = 0;
   // Ne pas oublier de remettre les variables de la commande automatisee... dans la mesure ou 
   // on risque de la relancer plus tard
}

// Returns true when the command should end.
bool AutoFollowTape::isFinish() {
  return   0 && mAlignController.AtSetpoint() && mDistanceController.AtSetpoint() && mYawController.AtSetpoint();
}

void AutoFollowTape::doExecute()
{
  if(!mCorrectPipeline_QuestionMark)
  {
    mSubLimelight->setPipeline(SubLimelight::eAprilTag);
  }
  mSubLimelight->Execute();      // Ne pas oublier de rajouter les executes de chaque subsysteme entree, telle que Limelight, Ultrason... etc

  double wAlignOutput = 0.0;
  if(mSubLimelight->getTapeOffSetDistance() != 0)
  {
    wAlignOutput = mAlignController.Calculate(mSubLimelight->getTapeOffSetDistance());
    // std::cout << mSubLimelight->getPos(SubLimelight::ePos::eYaw, SubLimelight::eReferential::eTag) << std::endl;
  }

  double wDistanceOutput = 0.0;
  if(mSubLimelight->getTargetArea() != 30)
  {
    wDistanceOutput = mDistanceController.Calculate(mSubLimelight->getTargetArea());
    // std::cout << mSubLimelight->getPos(SubLimelight::ePos::eY, SubLimelight::eReferential::eTag) << std::endl;
  }

  double wYawOutput = 0.0;
  if(mSubLimelight->getTargetOffsetAngleHorizontal() != 0)
  {
    wYawOutput = mYawController.Calculate(mSubLimelight->getTargetOffsetAngleHorizontal());
    // std::cout << mSubLimelight->getPos(SubLimelight::ePos::eYaw, SubLimelight::eReferential::eTag) << std::endl;
  }
  std::cout<<"wAlignOutput : " <<wAlignOutput << "  wDistanceOutput : " << wDistanceOutput << "  wYawOutput" << wYawOutput << std::endl;
  mSubDriveTrain->setParameters(wAlignOutput,wDistanceOutput,-wYawOutput,0);
  mSubDriveTrain->Execute();
}
