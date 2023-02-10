/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <frc/Joystick.h>
#include <frc/buttons/JoystickButton.h>
#include <RobotMap.h>

class OI {
 private:
  frc::Joystick * mJoystickPtr;
  frc::JoystickButton* m1ButtonPtr;
  frc::JoystickButton* m2ButtonPtr;
  bool canTurn;
  

 public:
  OI();
  double GetXJoystick();
  double GetYJoystick();
  double GetZJoystick();
  double GetSlider();
  void OIToggleTurn();
};
