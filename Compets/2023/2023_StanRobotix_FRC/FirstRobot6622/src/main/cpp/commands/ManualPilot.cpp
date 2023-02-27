// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "../../include/commands/ManualPilot.h"
#include "../../include/RobotContainer.h"

#include <iostream>

ManualPilot::ManualPilot(RobotContainer *iRobotContainer)
{
   mRobotContainer = iRobotContainer;

   EnablePerformanceLog(kLogPerf_ManualPilotEnable);

   Init();
}

/**
 * The initial subroutine of a command.  Called once when the command is
 * initially scheduled.
 */
void ManualPilot::Init()
{
   mSubDriveTrain = mRobotContainer->getSubDriveTrain();
   mSubLimelight = mRobotContainer->getSubLimelight();

   mSubUltrasonic = mRobotContainer->getSubUltrasonic();
   mSubElevator = mRobotContainer->getSubElevator();
   mSubPilotInterface = mRobotContainer->getSubPilotInterface();
   mSubImu = mRobotContainer->getSubIMU();
   mSubColorSensor = mRobotContainer->getSubColorSensor();
   mSubPneumatic = mRobotContainer->getSubPneumatic();
}

/**
 * The main body of a command.  Called repeatedly while the command is
 * scheduled.
 */
void ManualPilot::doExecute()
{
   bool wIsFieldOrientedEnabled = mSubPilotInterface->GetRawButton(SubPilotInterface::ActivationFieldOriented);
   const double slider = (1 - mSubPilotInterface->GetThrottle()) / 2;
   mSubDriveTrain->setParameters(mSubPilotInterface->GetX() * -slider,
                            mSubPilotInterface->GetY() * slider,
                            mSubPilotInterface->GetTwist() * slider,
                            !wIsFieldOrientedEnabled);
   mSubDriveTrain->Execute();

   // bool wResetImuYaw = mSubPilotInterface->GetRawButton(SubPilotInterface::ResetImuYaw);
   // if (mSubPilotInterface->GetRawButtonPressed(wResetImuYaw))
   //    // {
   //    //   SubIMU::getInstance()->ResetYaw();
   //    // }

   //    mSubUltrasonic->Execute();

   // // mSubElevator->setCommand(mJoystick.GetPOV()); // TODO

   mSubImu->Execute();

   // mSubColorSensor->Execute();

   // mSubLimelight->doExecute(); // TODO toto

   // if (mSubPilotInterface->GetRawButtonPressed(SubPilotInterface::TogglePneumatic)) // TODO gatien
   // {
   //    mSubPneumatic->Toggle();
   // }
}
