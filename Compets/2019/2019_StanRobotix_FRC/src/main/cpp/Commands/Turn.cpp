/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/Turn.h"

#include <iostream>

Turn::Turn(double iAngle, RotationPID* iPid, bool dynamicAngle)
{
  Requires(&Robot::m_drivetrain);
  mAngleIncrement = iAngle;
  mRPidPtr = iPid;
  mDynamicAngle = dynamicAngle;
}

void Turn::Initialize() 
{
  mRPidPtr = new RotationPID(Robot::PIDP,Robot::PIDI,Robot::PIDD);
  Robot::m_RotationPID = mRPidPtr;
  
  if (mDynamicAngle)
  {
    mAngleIncrement = Robot::PIDVal;
  }
  
  mTargetAngle = mAngleIncrement + Robot::m_gps.GetAngle();
  mRPidPtr->SetSetpoint(mTargetAngle);
}

void Turn::Execute() 
{
  double wPower = 0;
  
  if(mRPidPtr != nullptr) 
  {
    wPower = mRPidPtr->GetPIDOutput();
  }

  Robot::m_drivetrain.TankDrive(wPower, -wPower); 
}

bool Turn::IsFinished() 
{ 
  if(mRPidPtr != nullptr) 
  { 
    return mRPidPtr->OnTarget();
  }
  else return false || Robot::m_oi.GetStart(); 
}

void Turn::End() 
{
  Robot::m_drivetrain.TankDrive(0,0);
}

void Turn::Interrupted() 
{
  Robot::m_drivetrain.TankDrive(0,0);
}
