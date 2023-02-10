/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include <RobotMap.h>
#include <iostream>
#include <SmartDashboard/SmartDashboard.h>
#include "Commands/PrepHatchAlign.h"
#include "Commands/Aligner.h"
#include "Commands/Advance.h"
#include <math.h>
#include <Commands/ToggleVentouse.h>
#include <Commands/TogglePiston.h>
#include "Robot.h"
#include "Commands/RobotWiggle.h"

OI::OI() 
{
  // Process operator interface input here.

  mJoystickPtr = new Joystick(kJoystick);

  mYButtonPtr = new JoystickButton(mJoystickPtr, kYButton);
  mAButtonPtr = new JoystickButton(mJoystickPtr, kAButton);
  mBButtonPtr = new JoystickButton(mJoystickPtr, kBButton);
  mXButtonPtr = new JoystickButton(mJoystickPtr, kXButton);
  mLBButtonPtr = new JoystickButton(mJoystickPtr, kLBButton);
  mRBButtonPtr = new JoystickButton(mJoystickPtr, kRBButton);
  mStartButtonPtr = new JoystickButton(mJoystickPtr, kStartButton);

  mYButtonPtr->WhenPressed(new RobotWiggle());
  mBButtonPtr->WhenPressed(new PrepHatchAlign());
  mXButtonPtr->WhenPressed(new TogglePiston());
  mAButtonPtr->WhenPressed(new ToggleVentouse());

  //impossible de declarer le mButtonPtr dans le OI.h,
  //car le OI est utilise dans le DriveTrain.cpp qui est utilise
  //dans le Turn.cpp
}

double OI::GetLeftJoystick() 
{
  return -mJoystickPtr->GetRawAxis(kJoystickLeft);
}

double OI::GetRightJoystick() 
{
  return -mJoystickPtr->GetRawAxis(kJoystickRight);
  //signe << - >> devant la valeur des joysticks car 
                                       //leur orientation est inversee par rapport au tank drive
}

double OI::GetActuatorInput()
{
  if (mRBButtonPtr->Get() && !mLBButtonPtr->Get())
  {
    return 1.0;
  }
  
  if (!mRBButtonPtr->Get() && mLBButtonPtr->Get())
  {
    return -1.0;
  }
  return 0.0;
}

double OI::GetLT(){
  if (mJoystickPtr->GetRawAxis(kJoystickLeftTrigger) > 0.1)
  {
    return -1.0;
  }
  else{
    return 0.0;
  }
}

double OI::GetRT(){
  if (mJoystickPtr->GetRawAxis(kJoystickRightTrigger) > 0.1)
  {
    return 1.0;
  }
  else{
    return 0.0;
  }
}

bool OI::GetStart()
{
  return mStartButtonPtr->Get(); 
}
