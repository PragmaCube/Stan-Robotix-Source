/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/Advance.h"
#include <iostream>

Advance::Advance(double iDistance, StraightPID *iPid, bool dynamicDistance) 
{
  Requires(&Robot::m_drivetrain);
  mSPidPtr = iPid;
  mDistanceIncrement = iDistance;
  mDynamicDistance = dynamicDistance;
}

void Advance::Initialize() 
{
  mSPidPtr = new StraightPID(Robot::PIDP,Robot::PIDI,Robot::PIDD);
  Robot::m_StraightPID = mSPidPtr;
  
  if (mDynamicDistance)
  {
    mDistanceIncrement = Robot::PIDVal;
  }

  mTargetDistance = Robot::m_gps.GetEncoderDistance() + mDistanceIncrement;
  if(mSPidPtr != nullptr) 
  {
    mSPidPtr->SetSetpoint(mTargetDistance);
  }
}

void Advance::Execute() 
{
   double wPower = 0;

   if(mSPidPtr != nullptr) 
     {
       wPower = mSPidPtr->GetPIDOutput();
     }
  
  Robot::m_drivetrain.TankDrive(wPower, wPower);
}

bool Advance::IsFinished() 
{ 
  if(mSPidPtr != nullptr) 
  { 
    return mSPidPtr->OnTarget();
  }
  else return false || Robot::m_oi.GetStart();
}

void Advance::End() 
{
  Robot::m_drivetrain.TankDrive(0,0);
}

void Advance::Interrupted() 
{
  Robot::m_drivetrain.TankDrive(0,0);
}
