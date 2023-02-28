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

class RobotContainer;
class AutomatedCommandBase;

class SubPilotInterface : public PerformanceMonitor {

private:
  enum CommandId_t {MANUAL_TELEOP, AUTO_CONEHIGH, AUTO_CONELOW, AUTO_CHARGEUP, CMD_MAX };

  struct AutomatedCommand_t
  {
      CommandId_t mCmdId;
      bool mIsEnabled = false;
      std::string mDescription;
      PerformanceMonitor * mCommandPtr = nullptr;
  };

  AutomatedCommand_t mCommandList[CMD_MAX] = {
    { MANUAL_TELEOP, true, "commande manuel", nullptr},
    { AUTO_CONEHIGH, true, "commande pour placer un cone en haut" , nullptr},
    { AUTO_CONELOW, false, "commande pour placer un cone en bas" , nullptr},
    { AUTO_CHARGEUP, false, "commande pour la stabilisation finale" , nullptr},
  };

public:
 enum ButtonDefinition_t
 {
   NePasToucher, // Les index des boutons commencent a 1, pas a zero
   ActivationFieldOriented,
   ResetIMUGlobal,
   TogglePneumatic,
   Unused4,
   Unused5,
   Unused6,
   Unused7,
   Unused8,
   Unused9,
   AnnulationCommandeAuto,
   ChangementCommandeAuto,
   ActivationCommandeAuto
 };

 public:
  explicit SubPilotInterface(RobotContainer * iRobotContainer);
  
  void Init();

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
  RobotContainer * mRobotContainer;
  int mMenuIndex   = MANUAL_TELEOP;
  int mActiveIndex = MANUAL_TELEOP; 
};
