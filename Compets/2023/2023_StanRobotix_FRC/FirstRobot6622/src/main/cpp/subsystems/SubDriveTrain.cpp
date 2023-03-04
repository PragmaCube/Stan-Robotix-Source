// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Date       Auteur     Description                                               Test
// 21jan2023  Andre W.   mecanum operationel en robot-oriented-drive sans IMU      Deplacement omni-directionnel
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Référence: https://docs.wpilib.org/en/stable/docs/software/hardware-apis/motors/wpi-drive-classes.html

#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubIMU.h"
#include "RobotContainer.h"

#include <iostream>

SubDriveTrain::SubDriveTrain(RobotContainer *iRobotContainer)
{
  Enable(kDriveTrainEnabled);
  EnablePerformanceLog(kLogPerf_DrivetrainEnable);
  EnableSubsystemLog(kLogDrivetrain);

  mRobotContainer = iRobotContainer;

  setLogPeriodity(kLogPeriod_2s);
}

void SubDriveTrain::Init()
{
  if (mIsEnabled)
  {
    m_frontLeft  = new frc::Spark (kMotorL1Port);
    m_rearLeft   = new frc::Spark (kMotorL2Port);
    m_frontRight = new frc::Spark (kMotorR1Port);
    m_rearRight  = new frc::Spark (kMotorR2Port);    

    m_rearRight->SetInverted(true);        // Le filage est inverse pour ce moteur dans le robot.
    m_frontRight->SetInverted(true);       // Le filage est inverse pour ce moteur dans le robot.

    m_robotDrive = new frc::MecanumDrive(*m_frontLeft, *m_rearLeft, *m_frontRight, *m_rearRight);
  }

  mSubIMU = mRobotContainer->getSubIMU();
}

void SubDriveTrain::setParameters(const double iX, const double iY, const double iTwist, const bool iFieldOriented) // le prefix i est necessaire, pour specifier que c est une entree.
{
  mX = iX;
  mY = iY;
  mTwist = iTwist;
  mFieldOriented = iFieldOriented;
}

void SubDriveTrain::doExecute()
{
  static int wNumberOfExecution = 0;

  if (mIsEnabled)
  {
    if (mFieldOriented)
    {
      frc::Rotation2d imuAngle = mSubIMU->getRadian();
      m_robotDrive->DriveCartesian(-mY, mX, mTwist, imuAngle);
    }
    else
    {
      m_robotDrive->DriveCartesian(-mY, mX, mTwist);
    }
  }

  if (((wNumberOfExecution % mLogPeriodicity) == 0) && mSubsystemLogEnabled)
  {
    std::cout << "mX:" << mX << std::endl
              << "  mY :" << mY << std::endl
              << "   mTwist " << mTwist << std::endl;
  }

  wNumberOfExecution++;
}
