/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Joystick.h>
#include <Buttons/JoystickButton.h>
#include "Preferences.h"

class OI 
{
  public:
    OI();
    double GetLeftJoystick();
    double GetRightJoystick();
    double GetActuatorInput();
    double GetLT();
    double GetRT();
    bool GetStart();

  private:
    Joystick * mJoystickPtr;

    JoystickButton * mAButtonPtr;
    JoystickButton * mBButtonPtr;
    JoystickButton * mXButtonPtr;
    JoystickButton * mYButtonPtr;

    JoystickButton * mLBButtonPtr;
    JoystickButton * mRBButtonPtr;
    JoystickButton * mStartButtonPtr;
};
