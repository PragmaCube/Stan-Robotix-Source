// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include <frc/XboxController.h>
#include <frc/Joystick.h>

#include "PerformanceMonitor.h"
#include <frc2/command/SubsystemBase.h>
#include "Constants.h"

#include <iostream>

class SubPilotInterface : public PerformanceMonitor {
private:
 enum CommandId_t {MANUAL_TELEOP, CMD0, CMD1, CMD_MAX };

  typedef struct AutomatedCommand_t
  {
      CommandId_t mCmdId;
      bool mIsEnabled = false;
      std::string mDescription;
      int * mCommandPtr = nullptr;
      // AutomatedCommandBase
  };

  AutomatedCommand_t mCommandList[CMD_MAX] = {
    { MANUAL_TELEOP, true, "Commande manuel", new int [2]},
    { CMD0, true, "Ma premiere Commande" , new int [2]},
    { CMD1, false, "Ma 2eme Commande" , new int [2]}
  };

 public:
  SubPilotInterface();
  
  void Init() { }

  double GetThrottle() { return mJoystick.GetThrottle(); }
  double GetX() { return mJoystick.GetX(); }
  double GetY() { return mJoystick.GetY(); }
  double GetTwist() { return mJoystick.GetTwist(); }
  bool GetRawButtonPressed(int index) {return mJoystick.GetRawButtonPressed(index);}
  bool GetRawButton(int index)  {return mJoystick.GetRawButton(index);}

 private:
  virtual void doExecute();
  
  virtual std::string getName() { return "SubPilotInterface"; }
  
  frc::Joystick mJoystick{kJoystickPort};
  int mMenuIndex =0;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
